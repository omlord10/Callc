#include "utils.h"
#include <stdio.h>

/**
 * Simple test for the load_config function
 */
int main()
{
    Config config;

    // Путь к конфигурационному файлу
    const char *filename = "app.config";

    // Загружаем конфиг
    int result = load_config(filename, &config);

    // Проверка кода возврата
    switch (result)
    {
        case Error_Config_Success:
            printf("Config loaded successfully.\n");
            printf("rounding_precision = %d\n", config.rounding_precision);
            break;

        case Error_Config_NULL_Config_Pointer:
            printf("Error: NULL pointer passed to load_config\n");
            break;

        case Error_Config_OpenFile:
            printf("Error: Unable to open config file: %s\n", filename);
            break;

        case Error_Config_Reading_Failed:
            printf("Error: Failed to read from config file\n");
            break;

        case Error_Config_Exit_Beyond_The_Array:
            printf("Error: Attempted to access memory beyond line buffer\n");
            break;

        case Error_Config_Parse:
            printf("Error: Failed to parse config line\n");
            break;

        case Error_Config_Uncknow_Config_Key:
            printf("Error: Unknown config key found\n");
            break;

        case Error_Config_Close_File:
            printf("Error: Failed to close config file\n");
            break;

        default:
            printf("Error: Unknown error code %d\n", result);
            break;
    }

    return 0;
}
