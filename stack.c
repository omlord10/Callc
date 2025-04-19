#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <stdio.h>
#include <math.h>
#include "utils.h"


int InitStack(Stack *stack, Config *config)
{
    if (config->logging == 1)
    {
        printf("Initializing stack...\n");
    }

    if (stack == NULL)
    {
        if (config->logging == 1)
        {
            printf("Error: Stack is NULL\n");
        }
        return Error_Codes_InitStack_NullPointer;
    }

    stack->capacity = 16;
    stack->size = 0;
    stack->items = (Leksema *)malloc(stack->capacity * sizeof(Leksema));

    if (stack->items == NULL)
    {
        if (config->logging == 1)
        {
            printf("Error: Memory allocation failed\n");
        }
        return Error_Codes_InitStack_MemoryAllocationFailed;
    }

    if (config->logging == 1)
    {
        printf("Stack initialized successfully\n");
    }

    return Error_Codes_InitStack_Success;
}


int PushStack(Stack *stack, Leksema item, Config *config)
{
    if (config->logging == 1)
    {
        printf("Pushing item to stack...\n");
    }

    if (stack == NULL)
    {
        if (config->logging == 1)
        {
            printf("Error: Stack is NULL\n");
        }
        return Error_Codes_PushStack_NullPointer;
    }

    if (stack->items == NULL)
    {
        if (config->logging == 1)
        {
            printf("Error: Stack items is NULL\n");
        }
        return Error_Codes_PushStack_NullPointer;
    }

    if (stack->size >= stack->capacity)
    {
        size_t new_capacity = stack->capacity * 2;
        Leksema *new_items = (Leksema *)realloc(stack->items, new_capacity * sizeof(Leksema));
        if (new_items == NULL)
        {
            if (config->logging == 1)
            {
                printf("Error: Memory reallocation failed\n");
            }
            return Error_Codes_PushStack_MemoryAllocationFailed;
        }

        stack->items = new_items;
        stack->capacity = new_capacity;

        if (config->logging == 1)
        {
            printf("Stack capacity increased to %zu\n", new_capacity);
        }
    }

    stack->items[stack->size] = item;
    stack->size += 1;

    if (config->logging == 1)
    {
        printf("Item pushed successfully. Stack size: %zu\n", stack->size);
    }

    return Error_Codes_PushStack_Success;
}

/*
int PopStack(Stack *stack, Leksema *item)
{
    if (stack->size == 0)
    {
        return 0;
    }

    stack->size--;
    if (item != NULL)
    {
        *item = stack->items[stack->size];
    }

    return 1;
}

int TopStack(Stack *stack, Leksema *item)
{
    if (stack->size == 0)
    {
        return 0;
    }

    *item = stack->items[stack->size - 1];
    return 1;
}

int IsEmptyStack(Stack *stack)
{
    return (stack->size == 0);
}
*/
int FreeStack(Stack *stack, Config *config)
{
    if (config != NULL && config->logging == 1)
    {
        printf("Freeing stack...\n");
    }

    if (stack == NULL)
    {
        if (config != NULL && config->logging == 1)
        {
            printf("Error: Stack is NULL\n");
        }
        return Error_Codes_FreeStack_NullPointer;
    }

    if (stack->items != NULL)
    {
        free(stack->items);
        stack->items = NULL;
    }

    stack->size = 0;
    stack->capacity = 0;

    if (config != NULL && config->logging == 1)
    {
        printf("Stack freed successfully\n");
    }

    return Error_Codes_FreeStack_Success;
}
