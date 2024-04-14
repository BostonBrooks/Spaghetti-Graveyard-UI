/** "int32_t bbWidget_onCommand(void* widget, void* command);"
 * passes struct command to the widget's virtual function
 * of type "typedef int32_t bbWidget_OnCommand (bbWidget* widget, void* data);"
 * selected by "int32_t v_OnCommand;"
 * The first element of struct command is an int32_t flag that tells the virtual
 * what to do with the command
 */
#ifndef BBCOMMANDS_H
#define BBCOMMANDS_H

#include <inttypes.h>

#include "headers/bbGeometry.h"

#define f_CommandPutChar     0
#define f_CommandPutStr      1
#define f_CommandSetStr      2
#define f_CommandSetDim      3
#define f_CommandSetActive   4
#define f_CommandSetInactive 5

//Commands use void pointers, messages use unions

typedef struct{
    int32_t type;
} bbCommandEmpty;


typedef struct {
    int32_t type; // = f_CommandPutChar
    char m_char;
} bbCommandPutChar;

typedef struct {
    int32_t type; // = f_CommandPutStr
    char* m_str;
} bbCommandPutStr;

typedef struct {
    int32_t type; // = f_CommandSetStr
    char* m_str;
} bbCommandSetStr;

typedef struct {
    int32_t type; // = f_CommandSetDim
    int m_rows;
    int m_columns;
} bbCommandSetDim;
#endif //BBCOMMANDS_H