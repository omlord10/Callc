#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

enum ConfigKeyType GetConfigKeyType(const char *key)
{
    if (strcmp(key, "rounding_precision") == 0)
        return CONFIG_KEY_ROUNDING_PRECISION;
    else if (strcmp(key, "logging") == 0)
        return CONFIG_KEY_LOGGING;
    else
        return CONFIG_KEY_UNKNOWN;
}

int load_config(const char *filename, Config *config)
{
    printf("Starting to load config...\n");

    if (config == NULL)
    {
        printf("Error: Config pointer is NULL\n");
        return Error_Config_NULL_Config_Pointer;
    }

    printf("Opening file: %s\n", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Unable to open config file: %s\n", filename);
        return Error_Config_OpenFile;
    }

    int lines_count = 1;
    int ch;
    printf("Counting lines in the config file...\n");
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            lines_count++;
            printf("Found newline. Total lines so far: %d\n", lines_count);
        }
    }

    printf("Total lines in file: %d\n", lines_count);

    if (fseek(file, 0, SEEK_SET) != 0)
    {
        printf("Error: Failed to rewind config file\n");
        fclose(file);
        return Error_Config_Reading_Failed;
    }
     else
     {
         printf("Successfully rewound the file to the beginning\n");
     }

    for (int i = 0; i < lines_count; i++)
    {
        char key[MAX_LINE_LENGTH];
        char value[MAX_LINE_LENGTH];

        printf("Reading line %d...\n", i + 1);
        int parsed = fscanf(file, "%s = %s", key, value);

        if (parsed == EOF)
        {
            printf("End of file reached while reading line %d\n", i + 1);
            break;
        }
        else if (parsed != 2)
        {
            printf("Error: Invalid config line format on line %d\n", i + 1);
            fclose(file);
            return Error_Config_Parse;
        }

        printf("Parsed key: '%s', value: '%s'\n", key, value);

        switch (GetConfigKeyType(key))
        {
            case CONFIG_KEY_ROUNDING_PRECISION:
                config->rounding_precision = atoi(value);
                printf("Set config.rounding_precision = %d\n", config->rounding_precision);
                break;

            case CONFIG_KEY_LOGGING:
                config->logging = atoi(value);
                printf("Set config.logging = %d\n", config->logging);
                break;

            case CONFIG_KEY_UNKNOWN:
            default:
                printf("Warning: Unknown config key: %s\n", key);
                break;
        }

    }

    if (fclose(file) != 0)
    {
        printf("Error: Failed to close config file\n");
        return Error_Config_Close_File;
    }
     else
     {
         printf("Config file closed successfully\n");
     }

    printf("Config loaded successfully!\n");
    return Error_Config_Success;
}

int PrintDouble(double value, Config *config)
{
    if (config == NULL)
    {
        printf("Error: Config is not initialized\n");
        return Error_Codes_PrintDouble_NullPointer;
    }

    if (config->rounding_precision < 0)
    {
        printf("Error: Invalid rounding_precision value (should be >= 0)\n");
        return Error_Codes_InitStack_Invalid_Rounding_Precision_Value;
    }

    double rounded_value = round(value * pow(10, config->rounding_precision)) / pow(10, config->rounding_precision);

    if (config->logging == 1)
    {
        printf("Printing rounded value: %.*f\n", config->rounding_precision, rounded_value);
    }

    printf("%.*f\n", config->rounding_precision, rounded_value);

    return Error_Codes_PrintDouble_Success;
}
