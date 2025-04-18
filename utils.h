#ifndef UTILS_H
#define UTILS_H

// Структура конфигурации
typedef struct {
    int rounding_precision;  // точность округления
} Config;

/**
 * Функция для загрузки конфигурации из файла
 * @param filename Имя конфигурационного файла
 * @param config Указатель на структуру конфигурации, куда будут сохранены значения
 * @return Код ошибки (0 — успех, остальные значения — ошибки)
 */
int load_config(const char *filename, Config *config);

#endif // UTILS_H
