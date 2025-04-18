#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

enum Errors_Config
{
    Error_Config_Success = 0,
    Error_Config_NULL_Config_Pointer = 1,
    Error_Config_OpenFile = 2,
    Error_Config_Reading_Failed = 3,
    Error_Config_Exit_Beyond_The_Array = 4,
    Error_Config_Parse = 5,
    Error_Config_Uncknow_Config_Key = 6,
    Error_Config_Close_File = 7
};

/**
 * Function to read configuration from a file
 * @param filename — Name of the config file
 * @param config — Pointer to the config structure where the values will be saved
 * @return Errors_Config codes (Error_Config_Success, Error_Config_NULL_Config_Pointer,
 * Error_Config_OpenFile, Error_Config_Reading_Failed, Error_Config_Parse,
 * Error_Config_Uncknow_Config_Key, Error_Config_Close_File)
 * )
 */
int load_config(const char *filename, Config *config)
{
    // Check pointer to config
    if (config == NULL)
    {
        printf("Error: Config pointer is NULL\n");
        return Error_Config_NULL_Config_Pointer;
    }

    FILE *file = fopen(filename, "r");
    /**
     * opens a file with the specified filename and mode.
     * Returns a pointer to a FILE object on success, or NULL
     * on failure.
     */


    if (file == NULL)
    {
        printf("Error: Unable to open config file: %s\n", filename);
        return Error_Config_OpenFile;
    }

    char line[MAX_LINE_LENGTH];
    int lines_count = 0;
    int ch = 0;
    size_t i = 0;

    /**
     * Reads the file character by character using fgetc().
     * Increments lines_count each time a newline '\n' is found.
     * Stops reading when EOF is reached.
     */
    while((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            lines_count++;
        }
    }


    for (i = 0; i < lines_count; i++)
    {
        /**
         * Reads lines from the file.
         * If fgets() returns NULL, it checks whether the end of
         * the file has been reached or if an error occurred.
         * If the file has been successfully read to the end, it
         * exits the loop; otherwise, it reports an error.
         */
        if (fgets(line, sizeof(line), file) == NULL)
        {
            if (feof(file) != 0)
            {
                break; // End of file reached
            }
            else
            {
                printf("Error: Reading config file failed\n");
                fclose(file);
                return Error_Config_Reading_Failed;
            }
        }

        /**
         * size_t strcspn(const char *str1, const char *str2)
         * Removes the newline character from the end of line.
         * strcspn() finds the index of '\n', which is then
         * replaced with a null terminator '\0'.
         * This "IF" checks the exit beyond the array
         */
        if ((strcspn(line, "\n") >= 0) && (strcspn(line, "\n") <= sizeof(line)/sizeof(line[0])))
        {
            line[strcspn(line, "\n")] = '\0';
        }
        else
        {
            printf("Error: Attempted to access memory beyond the line buffer bounds when removing newline\n");
            fclose(file);
            return Error_Config_Exit_Beyond_The_Array;
        }

        // Skip empty lines or comments
        if (line[0] == '#' || line[0] == '\0')
        {
            continue;
        }

        char key[MAX_LINE_LENGTH];
        char value[MAX_LINE_LENGTH];

       /**
        * int sscanf(const char *str, const char *format, ...);
        * Parses a line in the format "key = value".
        * Uses sscanf() to extract key and value as strings.
        * Stores the number of successfully parsed items in parsed.
        */

        int parsed = sscanf(line, "%s = %s", key, value);
        if (parsed == 2)
        {
            /**
             * Compares the string key with "rounding_precision".
             * Uses strcmp() to check if the strings are equal.
             * Returns 0 if equal, triggering the condition.
             */

            if (strcmp(key, "rounding_precision") == 0)
            {
                /**
                 * int atoi(const char *str);
                 * Skips leading whitespace, handles optional + or -
                 * Converts the string value to an integer using atoi()
                 * Sets config->rounding_precision to the converted value.
                 */

                config->rounding_precision = atoi(value);
            }
            else
            {
                printf("Warning: Unknown config key: %s\n", key);
                fclose(file);
                return Error_Config_Uncknow_Config_Key;
            }
        }
        else
        {
            printf("Error: Invalid config line format: %s\n", line);
            fclose(file);
            return Error_Config_Parse;
        }
    }

    /**
     * int fclose(FILE *stream);
     * Closes the given file stream.
     * Returns 0 on success, EOF on error.
     */

    if (fclose(file) != 0)
    {
        printf("Error: Failed to close config file\n");
        return Error_Config_Close_File;
    }
    return Error_Config_Success;
}
