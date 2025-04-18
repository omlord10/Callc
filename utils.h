#ifndef UTILS_H
#define UTILS_H

// ��������� ������������
typedef struct {
    int rounding_precision;  // �������� ����������
} Config;

/**
 * ������� ��� �������� ������������ �� �����
 * @param filename ��� ����������������� �����
 * @param config ��������� �� ��������� ������������, ���� ����� ��������� ��������
 * @return ��� ������ (0 � �����, ��������� �������� � ������)
 */
int load_config(const char *filename, Config *config);

#endif // UTILS_H
