#include <stdio.h>

int main(){
    int iAge = 0;
    printf("How old are you? ");
    scanf("%d", &iAge);

    if(iAge>=0 && iAge<=125) {
        if(iAge<21) {
            printf("You cannot enjoy alcoholic beverages\n");
        }
        else{
            printf("You are %d years old\ 355n", iAge);
        }
    }
    else {
        printf("You entered an invalid age\n");
    }

    return 0;
}