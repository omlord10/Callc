#ifndef UTILS_H
#define UTILS_H

// Структура конфигурации
typedef struct {
    int rounding_precision;
    int logging;  // Флаг для включения/выключения логирования
} Config;

// Ошибки, которые могут возникать при загрузке конфигурации
enum ErrorCodes_Config
{
    Error_Config_Success = 0,
    Error_Config_NULL_Config_Pointer,
    Error_Config_OpenFile,
    Error_Config_Reading_Failed,
    Error_Config_Parse,
    Error_Config_Uncknow_Config_Key,
    Error_Config_Close_File,
    Error_Config_Exit_Beyond_The_Array
};

enum Error_Codes_PrintDouble {
    Error_Codes_PrintDouble_Success = 0,
    Error_Codes_PrintDouble_NullPointer = 1,
    Error_Codes_InitStack_Invalid_Rounding_Precision_Value = 2
};

enum ConfigKeyType
{
    CONFIG_KEY_UNKNOWN,
    CONFIG_KEY_ROUNDING_PRECISION,
    CONFIG_KEY_LOGGING
};

// Функции, которые определены в utils.c
int load_config(const char *filename, Config *config);
int PrintDouble(double value, Config *config);

#endif // UTILS_H
