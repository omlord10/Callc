#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "evaluator.h"
#include "utils.h"

/*enum Error_Codes_main
{
    Error_Codes_main_OK,
    Error_Codes_main_InvalidInput,
    Error_Codes_main_LexerError,
    Error_Codes_main_ParserError,
    Error_Codes_main_EvaluatorError
};

int main()
{
    struct Config config;
    int result;
    enum Error_Codes_main status;

    char input[256];
    struct Token tokens[128];
    size_t token_count;

    struct ASTNode ast_root;
    double result_value;

    result = load_config("app.config", &config);
    if (result != 0)
    {
        printf("Error: failed to load config\n");
        return 1;
    }

    while (1)
    {
        printf("Enter expression (or 'exit'): ");
        if (!fgets(input, sizeof(input), stdin))
        {
            printf("Error reading input\n");
            status = Error_Codes_main_InvalidInput;
            break;
        }

        size_t len;
        len = strlen(input);
        if (len > 0 && input[len - 1] == '\n')
        {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0)
        {
            break;
        }

        result = lex(input, tokens, &token_count, &config);
        if (result != 0)
        {
            printf("Lexer error\n");
            status = Error_Codes_main_LexerError;
            continue;
        }

        result = parse(tokens, token_count, &ast_root, &config);
        if (result != 0)
        {
            printf("Parser error\n");
            status = Error_Codes_main_ParserError;
            continue;
        }

        result = evaluate(&ast_root, &result_value, &config);
        if (result != 0)
        {
            printf("Evaluator error\n");
            status = Error_Codes_main_EvaluatorError;
            continue;
        }

        printf("Result: %.10g\n", result_value);
        status = Error_Codes_main_OK;
    }

    return status;
}
*/
