/**
 * @file
 * @brief This file contains methods for manipulating strings
 * May want to do safety checks, later
 * these are small functions that are expected to be in-lined so I made them static
*/
#ifndef BBSTRING_H
#define BBSTRING_H

#include <inttypes.h>
#include "headers/bbFlags.h"

// strcpy()
static int32_t bbStr_setStr(char* dest, char* src){
    int i = 0;
    while(1){
        dest[i] = src[i];
        if (src[i] == '\0') return f_Success;
        i++;
    }
}

// strcat()
static int32_t bbStr_putStr(char* dest, char* src){
    //search through string for \0
    int i = 0;

    while(1){
        if (dest[i] == '\0') break;
        i++;
    }
    //replace \0 with string

    bbStr_setStr(&dest[i], src);

}

// add char at end of string
static int32_t bbStr_putChar(char* dest, char src){
    //search through string for \0
    int i = 0;

    while(1){
        if (dest[i] == '\0') break;
        i++;
    }
    dest[i] = src;
    dest[i+1]= '\0';
    //replace \0 with string

    //add \0 to end
}

// fit string to box given by columns and rows
// not well thought out or tested
static int32_t bbStr_setBounds(char* str, int32_t columns, int32_t rows){

    if(str[0] == '\0') return f_Success;

    char temp[1028];  //heap is slower than stack? stack overflow possible?

    // copy from str to temp, keeping track of chars since last \n
    // insert \n when necessary

    int32_t i_str = 0;
    int32_t i_temp = 0;
    int32_t column = 0;

    while(1){
        if (str[i_str] == '\n') column = 0;

        temp[i_temp] = str[i_str];

        if (str[i_str] == '\0') break;
        column++;
        i_str++;
        i_temp++;


        if (column >= columns){
            if(str[i_str] == '\n') i_str++;
            temp[i_temp] = '\n';
            column = 0;
            i_temp++;
        }

    }

    // go back to the \n character "rows" before the last char
    int row = 0;

    while (1) {
        if (i_temp == 0) break;
        if (temp[i_temp] == '\n') row++;
        if (row > rows) break;
        i_temp--;
    }

    // copy the remainder of temp back to str

    bbStr_setStr(str, &temp[i_temp]);

    return f_Success;
}


#endif //BBSTRING_H