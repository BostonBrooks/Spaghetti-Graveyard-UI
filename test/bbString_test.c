#include <stdio.h>

#include "headers/bbString.h"
#include "headers/bbIntTypes.h"

int main(void){

    char output[64] = "";

    char one = 'A';
    char* two = " lovely";
    char* three = " bunch ";
    char four = 'o';
    char* five = " coconuts";

    bbStr_putChar(output, one);
    bbStr_putStr(output, two);
    bbStr_putStr(output, three);
    bbStr_putChar(output, four);
    bbStr_putStr(output, five);

    printf("%s\n", output);

    while(1) {
        char input[1028];

        scanf("%[^~]~", input);
        printf("%s\n", input);
        bbStr_setBounds(input, 7, 5);

        printf("%s\n", input);
    }
}