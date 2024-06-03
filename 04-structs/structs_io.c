// how to read/write structures from/to a file

#include <unistd.h>   // aka UNIX Standard; POSIX (Portable OS Interface) API incl read/write
#include <fcntl.h>    // aka File Control; POSIX API for open/close
#include <stdio.h>
#include <time.h>

/*
pseudocode to implement our very basic login records
    open loginfile
    repeat
        read loginfile record
        display loginfile record
    close loginfile
*/

struct login {
    char user_name[100];
    time_t time_stamp; 
};

#define LOGIN_FILE "login_file.txt"

int main() {
    struct login currentLogin;               // a single login record will be stored here
    int intLoginFile;                        // a file descriptor to work with the login file
    int intLoginLength=sizeof(currentLogin); // how many bytes are there in a login record
    // LOGIN_FILE is a #define that contains the current path of the login record file
    printf("Login file is %s\n", LOGIN_FILE);

    intLoginFile=creat(LOGIN_FILE, S_IRUSR | S_IWUSR); // create the login record file
    if(intLoginFile==-1) {                    // check if it was open successfully
        perror(LOGIN_FILE);                   // any error message will be determined by the value
        return 1;                             // of variable errno (per POSIX standards)
    }

    // populate the login file with some dummy records
    for(int i=0; i<3; i++){
        sprintf(currentLogin.user_name, "user_%d", i);
        time(&currentLogin.time_stamp);     // get the current system time
        write(intLoginFile, &currentLogin, intLoginLength);
        printf("Writing a record for %s\n", currentLogin.user_name);
        sleep(1);                           // add a delay to produce different time stamps
    }
    close(intLoginFile);


    intLoginFile=open(LOGIN_FILE, O_RDONLY);  // open the login record file
    if(intLoginFile==-1) {                    // check if it was open successfully
        perror(LOGIN_FILE);                   // any error message will be determined by the value
        return 1;                             // of variable errno (per POSIX standards)
    }
    // read and print all login records, one at a time
    while(read(intLoginFile, &currentLogin, intLoginLength)==intLoginLength) {
        printf("%s %.24s\n", currentLogin.user_name, asctime(localtime(&currentLogin.time_stamp)));
    }
    close(intLoginFile);
    return 0;
}