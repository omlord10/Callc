#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "utils.h"

typedef struct
{
    char type;     // '0' для числа, '+', '-', '*', и т.д. — для операций
    double value;  // значение (используется только, если type == '0', иначе = 0)
} Leksema;

typedef struct
{
    Leksema *items;
    size_t capacity;
    size_t size;
} Stack;

enum Error_Codes_InitStack {
    Error_Codes_InitStack_Success = 0,
    Error_Codes_InitStack_NullPointer = 1,
    Error_Codes_InitStack_MemoryAllocationFailed,
};

enum Error_Codes_PushStack
{
    Error_Codes_PushStack_Success = 0,
    Error_Codes_PushStack_NullPointer = 1,
    Error_Codes_PushStack_MemoryAllocationFailed,
};

enum Error_Codes_FreeStack
{
    Error_Codes_FreeStack_Success = 0,
    Error_Codes_FreeStack_NullPointer = 1
};

int InitStack(Stack *stack, Config *config);
int PushStack(Stack *stack, Leksema item, Config *config);
int PopStack(Stack *stack, Leksema *item);
int TopStack(Stack *stack, Leksema *item);
int IsEmptyStack(Stack *stack);
int FreeStack(Stack *stack, Config *config);


#endif
