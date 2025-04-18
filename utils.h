#ifndef UTILS_H
#define UTILS_H

// —труктура конфигурации
typedef struct {
    int rounding_precision;  // точность округлени€
} Config;

/**
 * Function to read configuration from a file
 * @param filename Ч Name of the config file
 * @param config Ч Pointer to the config structure where the values will be saved
 * @return Error code (Error_Config_Success, Error_Config_OpenFile, Error_Config_Parse)
 */
int load_config(const char *filename, Config *config);

#endif // UTILS_H
