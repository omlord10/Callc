#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mathfunc.h"
#include "lexer.h"
#include "parser.h"
#include "stack.h"

/*
static int GetPriority(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

static int ApplyOperation(double a, double b, char op, double *res)
{
    if (res == NULL)
    {
        return Error_Codes_Maths_OperationFail;
    }

    if (op == '+')
    {
        *res = a + b;
    }
    else if (op == '-')
    {
        *res = a - b;
    }
    else if (op == '*')
    {
        *res = a * b;
    }
    else if (op == '/')
    {
        if (b == 0.0)
        {
            return Error_Codes_Maths_DivByZero;
        }
        *res = a / b;
    }
    else
    {
        return Error_Codes_Maths_UnknownOperator;
    }

    return Error_Codes_Maths_OK;
}

int Maths(Leksema *tokens, size_t count, double *result)
{
    Stack values;
    Stack ops;
    size_t i;
    int err = Error_Codes_Maths_OK;

    if (tokens == NULL || result == NULL)
    {
        return Error_Codes_Maths_NullInput;
    }

    if (!InitStack(&values) || !InitStack(&ops))
    {
        return Error_Codes_Maths_InitFail;
    }

    for (i = 0; i < count; i++)
    {
        Leksema current = tokens[i];

        if (current.type == '0')
        {
            if (!PushStack(&values, current))
            {
                err = Error_Codes_Maths_StackFail;
                break;
            }
        }
        else
        {
            Leksema topOp;
            while (!IsEmptyStack(&ops) && TopStack(&ops, &topOp) &&
                   GetPriority(topOp.type) >= GetPriority(current.type))
            {
                Leksema right, left, op;
                double tempRes = 0.0;

                if (!PopStack(&values, &right) || !PopStack(&values, &left) || !PopStack(&ops, &op))
                {
                    err = Error_Codes_Maths_StackFail;
                    goto cleanup;
                }

                err = ApplyOperation(left.value, right.value, op.type, &tempRes);
                if (err != Error_Codes_Maths_OK)
                {
                    goto cleanup;
                }

                Leksema resultLex;
                resultLex.type = '0';
                resultLex.value = tempRes;

                if (!PushStack(&values, resultLex))
                {
                    err = Error_Codes_Maths_StackFail;
                    goto cleanup;
                }
            }

            if (!PushStack(&ops, current))
            {
                err = Error_Codes_Maths_StackFail;
                break;
            }
        }
    }

    while (!IsEmptyStack(&ops))
    {
        Leksema right, left, op;
        double tempRes = 0.0;

        if (!PopStack(&values, &right) || !PopStack(&values, &left) || !PopStack(&ops, &op))
        {
            err = Error_Codes_Maths_StackFail;
            goto cleanup;
        }

        err = ApplyOperation(left.value, right.value, op.type, &tempRes);
        if (err != Error_Codes_Maths_OK)
        {
            goto cleanup;
        }

        Leksema resultLex;
        resultLex.type = '0';
        resultLex.value = tempRes;

        if (!PushStack(&values, resultLex))
        {
            err = Error_Codes_Maths_StackFail;
            goto cleanup;
        }
    }

    if (!PopStack(&values, tokens)) // result in tokens[0]
    {
        err = Error_Codes_Maths_StackFail;
        goto cleanup;
    }

    *result = tokens->value;

cleanup:
    FreeStack(&values);
    FreeStack(&ops);
    return err;
}

// === √À¿¬Õ¿ﬂ calculate ===

int calculate(char *expression, double *result)
{
    Leksema tokens[256];
    size_t tokenCount = 0;
    int err;

    if (expression == NULL || result == NULL)
    {
        return Error_Codes_calculate_NullInput;
    }

    if (strlen(expression) == 0)
    {
        return Error_Codes_calculate_EmptyExpression;
    }

    err = Lexer(expression, tokens, &tokenCount);
    if (err != 0)
    {
        return Error_Codes_calculate_LexerError;
    }

    err = Parser(tokens, &tokenCount);
    if (err != 0)
    {
        return Error_Codes_calculate_ParserError;
    }

    err = Maths(tokens, tokenCount, result);
    if (err != Error_Codes_Maths_OK)
    {
        return Error_Codes_calculate_MathsError;
    }

    return Error_Codes_calculate_OK;
}
*/
