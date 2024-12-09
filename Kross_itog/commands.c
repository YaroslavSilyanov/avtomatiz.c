#include <stdio.h>
#include "commands.h"
#include "input.h"

// Функция для вычисления и вывода суммы всех заказов
void c_sum(vihod v[], int vcnt, const char *filename) {
    int tsum = 0;
    for (int i = 0; i < vcnt; i++) {
        tsum += v[i].total;
    }
    output_sum(filename, v, vcnt, tsum);
}

// Функция для вычисления и вывода количества всех заказов
void c_count(vihod v[], int vcnt, const char *filename) {
    int tcnt = 0;
    for (int i = 0; i < vcnt; i++) {
        tcnt += v[i].count;
    }
    output_count(filename, v, vcnt, tcnt);
}

// Функция для вывода всех заказов
void c_allorders(vhod r[], int rcnt, const char *filename) {
    output_all_orders(filename, r, rcnt);
}

// Функция для вывода заказов, сгруппированных по месяцам
void c_months(vhod r[], int rcnt, const char *filename) {
    output_months(filename, r, rcnt);
}

// Функция для вычисления и вывода среднего чека
void c_check(vihod v[], int vcnt, const char *filename) {
    FILE *out = fopen(filename, "w");
    fprintf(out, "Imya_Zakazchika Sredniy_Chek\n");
    float obshee = 0.0;
    int tcnt = 0;
    for (int i = 0; i < vcnt; i++) {
        float sr = (float)v[i].total / v[i].count;
        fprintf(out, "%s %.2f\n", v[i].name, sr);
        obshee += v[i].total;
        tcnt += v[i].count;
    }
    if (tcnt > 0) {
        obshee /= tcnt;
    }
    fprintf(out, "\nSredniy chek vseh zakazov: %.2f\n", obshee);
    fclose(out);
}
