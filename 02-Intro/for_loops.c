#include <stdio.h>

// displays a triangle composed of asterisks
// the number of asterisks on the line corresponds to the line number
    
int main() {
    for(int line=1; line <= 10; line++) {       // iterate over every line
        printf("%2d ", line);
        // iterate over every asterisk on the current line
        for(int star=1; star <= line; star++)   
            printf("*");
        printf("\n");
    }
}