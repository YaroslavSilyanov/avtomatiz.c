#ifndef COMMANDS_H
#define COMMANDS_H

#include "structs.h"

// Функция для вычисления и вывода суммы всех заказов
void c_sum(vihod v[], int vcnt, const char *filename);

// Функция для вычисления и вывода количества всех заказов
void c_count(vihod v[], int vcnt, const char *filename);

// Функция для вывода всех заказов
void c_allorders(vhod r[], int rcnt, const char *filename);

// Функция для вывода заказов, сгруппированных по месяцам
void c_months(vhod r[], int rcnt, const char *filename);

// Функция для вычисления и вывода среднего чека
void c_check(vihod v[], int vcnt, const char *filename);

#endif
