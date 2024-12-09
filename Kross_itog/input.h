#ifndef INPUT_H
#define INPUT_H

#include "structs.h"

// Функция для ввода данных о заказах
void input_orders(const char *filename, vhod r[], int *rcnt);

// Функция для вывода суммы заказов
void output_sum(const char *filename, vihod v[], int vcnt, int tsum);

// Функция для вывода количества заказов
void output_count(const char *filename, vihod v[], int vcnt, int tcnt);

// Функция для вывода всех заказов
void output_all_orders(const char *filename, vhod r[], int rcnt);

// Функция для вывода заказов, сгруппированных по месяцам
void output_months(const char *filename, vhod r[], int rcnt);

#endif
