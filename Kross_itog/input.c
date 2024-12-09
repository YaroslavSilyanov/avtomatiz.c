#include <stdio.h>
#include "input.h"

// Функция для ввода данных о заказах
void input_orders(const char *filename, vhod r[], int *rcnt) {
    FILE *in = fopen(filename, "a+");
    vhod t;


    rewind(in);
    while (fscanf(in, "%d %s %s %s %d", &t.id, t.name, t.data, t.product, &t.cena) == 5) {
        r[*rcnt] = t;
        (*rcnt)++;
    }

    printf("Vvedite dannie zakazov (id 0 dlya zaversheniya):\n");

    while (1) {
        printf("Vvedite id zakazchika: ");
        if (scanf("%d", &t.id) != 1 || t.id == 0) {
            break; // Завершаем ввод, если введено id равное 0
        }

        printf("Vvedite imya zakazchika: ");
        scanf("%s", t.name);

        printf("Vvedite datu (format dd.mm.gggg): ");
        scanf("%s", t.data);

        printf("Vvedite nazvanie producta: ");
        scanf("%s", t.product);

        printf("Vvedite cenu: ");
        scanf("%d", &t.cena);

        // Записываем данные о заказе в файл
        fprintf(in, "%d %s %s %s %d\n", t.id, t.name, t.data, t.product, t.cena);
        r[*rcnt] = t;
        (*rcnt)++;
    }

    fclose(in);
}

// Функция для вывода суммы заказов
void output_sum(const char *filename, vihod v[], int vcnt, int tsum) {
    FILE *out = fopen(filename, "w");
    fprintf(out, "Imya_Zakazchika Obshaya_Summa_Zakazov\n");
    for (int i = 0; i < vcnt; i++) {
        fprintf(out, "%s %d\n", v[i].name, v[i].total);
    }
    fprintf(out, "Obshaya summa vseh zakazov: %d\n", tsum);
    fclose(out);
}

// Функция для вывода количества заказов
void output_count(const char *filename, vihod v[], int vcnt, int tcnt) {
    FILE *out = fopen(filename, "w");
    fprintf(out, "Imya_Zakazchika Kolichestvo_Zakazov\n");
    for (int i = 0; i < vcnt; i++) {
        fprintf(out, "%s %d\n", v[i].name, v[i].count);
    }
    fprintf(out, "Obshee kolvo vseh zakazov: %d\n", tcnt);
    fclose(out);
}

// Функция для вывода всех заказов
void output_all_orders(const char *filename, vhod r[], int rcnt) {
    FILE *out = fopen(filename, "w");
    fprintf(out, "ID Imya Data_Zakaza Produkt Cena\n");
    for (int i = 0; i < rcnt; i++) {
        fprintf(out, "%d %s %s %s %d\n", r[i].id, r[i].name, r[i].data, r[i].product, r[i].cena);
        if (i < rcnt - 1 && strcmp(r[i].name, r[i + 1].name) != 0) {
            fprintf(out, "\n");
        }
    }
    fclose(out);
}

// Функция для вывода заказов, сгруппированных по месяцам
void output_months(const char *filename, vhod r[], int rcnt) {
    FILE *out = fopen(filename, "w");
    fprintf(out, "ID Imya Data_Zakaza Produkt Cena\n");
    int cm = -1;
    for (int i = 0; i < rcnt; i++) {
        int m;
        sscanf(r[i].data, "%*d.%d.%*d", &m); // Извлекаем месяц из даты

        if (m != cm) {
            cm = m;
            switch (m) {
                case 1: fprintf(out, "\nYanvar\n"); break;
                case 2: fprintf(out, "\nFevral\n"); break;
                case 3: fprintf(out, "\nMart\n"); break;
                case 4: fprintf(out, "\nAprel\n"); break;
                case 5: fprintf(out, "\nMay\n"); break;
                case 6: fprintf(out, "\nIyn\n"); break;
                case 7: fprintf(out, "\nIyl\n"); break;
                case 8: fprintf(out, "\nAvgust\n"); break;
                case 9: fprintf(out, "\nSentybr\n"); break;
                case 10: fprintf(out, "\nOktybr\n"); break;
                case 11: fprintf(out, "\nNoybr\n"); break;
                case 12: fprintf(out, "\nDekabr\n"); break;
                default: break;
            }
        }
        fprintf(out, "%d %s %s %s %d\n", r[i].id, r[i].name, r[i].data, r[i].product, r[i].cena);
    }
    fclose(out);
}
