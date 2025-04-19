#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "lexer.h"
#include "stack.h"
#include "utils.h"
#include "mathfunc.h"

// Ошибки, возникающие при обработке выражения
enum Errors_evaluate_expression
{
    OK,
    ERROR_DIV_ZERO,
    ERROR_INVALID_TAN,
    ERROR_INVALID_CTG,
    ERROR_SYNTAX,
    ERROR_UNKNOWN
};

/*int evaluate_expression(const char *input)
{
    Stack numbers, operators;
    Leksema item;
    int error = OK;

    if (!init_stack(&numbers) || !init_stack(&operators))
    {
        printf("Stack init error\n");
        return 0;
    }

    const char *p = input;
    int unary_flag = 1;

    while (*p != '\0' && *p != '\n')
    {
        // Пропускаем пробелы
        if (*p == ' ')
        {
            p++;
            continue;
        }

        // Проверка на функции: sin, cos, tan, ctg, exp
        if (strncmp(p, "sin", 3) == 0)
        {
            item.type = 's';
            item.value = 0;
            push(&operators, item);
            p += 3;
            continue;
        }

        if (strncmp(p, "cos", 3) == 0)
        {
            item.type = 'c';
            item.value = 0;
            push(&operators, item);
            p += 3;
            continue;
        }

        if (strncmp(p, "tan", 3) == 0)
        {
            item.type = 't';
            item.value = 0;
            push(&operators, item);
            p += 3;
            continue;
        }

        if (strncmp(p, "ctg", 3) == 0)
        {
            item.type = 'g';
            item.value = 0;
            push(&operators, item);
            p += 3;
            continue;
        }

        if (strncmp(p, "exp", 3) == 0)
        {
            item.type = 'e';
            item.value = 0;
            push(&operators, item);
            p += 3;
            continue;
        }

        // Число Пи
        if (*p == 'p')
        {
            item.type = '0';
            item.value = Pi;
            push(&numbers, item);
            p++;
            unary_flag = 0;
            continue;
        }

        // Число
        if (isdigit(*p) || (*p == '-' && unary_flag))
        {
            char *endptr;
            double val = strtod(p, &endptr);
            item.type = '0';
            item.value = val;
            push(&numbers, item);
            p = endptr;
            unary_flag = 0;
            continue;
        }

        // Операции
        if (strchr("+-* /^", *p) && !unary_flag)
        {
            while (!is_empty(&operators) &&
                   get_priority(*p) <= get_priority(peek(&operators).type))
            {
                if (!calculate(&numbers, &operators, &item, &error))
                {
                    print_error(error);
                    return 0;
                }
            }

            item.type = *p;
            item.value = 0;
            push(&operators, item);
            p++;
            unary_flag = 1;
            continue;
        }

        // Скобки
        if (*p == '(')
        {
            item.type = '(';
            item.value = 0;
            push(&operators, item);
            p++;
            continue;
        }

        if (*p == ')')
        {
            while (!is_empty(&operators) && peek(&operators).type != '(')
            {
                if (!calculate(&numbers, &operators, &item, &error))
                {
                    print_error(error);
                    return 0;
                }
            }
            if (is_empty(&operators))
            {
                print_error(ERROR_SYNTAX);
                return 0;
            }
            pop(&operators); // убираем '('
            p++;
            continue;
        }

        // Неизвестный символ
        print_error(ERROR_SYNTAX);
        return 0;
    }

    // Обработка оставшихся операций
    while (!is_empty(&operators))
    {
        if (!calculate(&numbers, &operators, &item, &error))
        {
            print_error(error);
            return 0;
        }
    }

    if (is_empty(&numbers))
    {
        print_error(ERROR_SYNTAX);
        return 0;
    }

    printf("   Result: %lf\n", peek(&numbers).value);
    return 1;
}
*/
