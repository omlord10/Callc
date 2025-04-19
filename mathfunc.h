#ifndef MATHFUNC_H
#define MATHFUNC_H

#include "lexer.h"

enum Error_Codes_calculate
{
    Error_Codes_calculate_OK = 0,
    Error_Codes_calculate_NullInput,
    Error_Codes_calculate_EmptyExpression,
    Error_Codes_calculate_LexerError,
    Error_Codes_calculate_ParserError,
    Error_Codes_calculate_MathsError
};

enum Error_Codes_Maths
{
    Error_Codes_Maths_OK = 0,
    Error_Codes_Maths_NullInput,
    Error_Codes_Maths_InitFail,
    Error_Codes_Maths_StackFail,
    Error_Codes_Maths_UnknownOperator,
    Error_Codes_Maths_OperationFail,
    Error_Codes_Maths_DivByZero
};

int calculate(char *expression, double *result);  // Главная функция
//int Maths(Leksema *tokens, size_t count, double *result);  // Вспомогательная функция вычислений

#endif
