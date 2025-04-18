#ifndef UTILS_H
#define UTILS_H

// ��������� ������������
typedef struct {
    int rounding_precision;
    int logging;  // ���� ��� ���������/���������� �����������
} Config;

// ������, ������� ����� ��������� ��� �������� ������������
enum ErrorCodes_Config
{
    Error_Config_Success = 0,
    Error_Config_NULL_Config_Pointer = 1,
    Error_Config_OpenFile = 2,
    Error_Config_Reading_Failed = 3,
    Error_Config_Parse = 4,
    Error_Config_Uncknow_Config_Key = 5,
    Error_Config_Close_File = 6,
    Error_Config_Exit_Beyond_The_Array = 7
};

// �������, ������� ���������� � utils.c
int load_config(const char *filename, Config *config);

#endif // UTILS_H
