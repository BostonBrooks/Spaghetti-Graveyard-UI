/** "I32 bbWidget_onCommand(void* widget, void* command);"
 * passes struct command to the widget's virtual function
 * of type "typedef I32 bbWidget_OnCommand (bbWidget* widget, void* data);"
 * selected by "I32 v_OnCommand;"
 * The first element of struct command is an I32 flag that tells the virtual
 * what to do with the command
 */
#ifndef BBCOMMANDS_H
#define BBCOMMANDS_H


#include "headers/bbIntTypes.h"

#include "headers/bbGeometry.h"

#define f_CommandPutChar     0
#define f_CommandPutStr      1
#define f_CommandSetStr      2
#define f_CommandSetDim      3
#define f_CommandSetActive   4
#define f_CommandSetInactive 5

//Commands to be sent to Prompt
#define f_PromptSetQuery     6
#define f_PromptAddChar      7
#define f_PromptReturnAnswer 8
#define f_PromptAddDialogue  9

#define f_SpellEscape       10
#define f_SpellAnswer       11


//More recent commands

//bbCommandEmpty
#define c_RequestCode        10

//bbCommandStr
#define c_ReturnCode         11

//bbCommandEmpty
#define c_ActivateSpell      12

//bbCommandEmpty
#define c_DeactivateSpell    13

//bbCommandEmpty
#define c_RequestClick       14

//bbCommand2I
#define c_ReturnClick        15

//bbCommandStr
#define c_RequestAnswer      16

//bbCommandStr
#define c_ReturnAnswer       17

//unknown
#define c_CastSpell          18

//bbCommandEmpty
#define c_SetIdle            19

//Commands use void pointers, messages use unions

typedef struct{
    I32 type;
} bbCommandEmpty;


typedef struct {
    I32 type; // = f_CommandPutChar
    char m_char;
} bbCommandChar;

typedef struct {
    I32 type; // = f_CommandPutStr
    char* m_str;
} bbCommandStr;

typedef struct {
    I32 type; // = f_CommandSetDim
	I32 m_intx;
    I32 m_inty;
} bbCommand2I;
#endif //BBCOMMANDS_H
