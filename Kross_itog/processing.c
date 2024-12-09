#include <string.h>
#include "processing.h"

// Функция для обработки заказов и расчета суммы и количества заказов для каждого клиента
void process_orders(vhod r[], int rcnt, vihod v[], int *vcnt) {
    for (int i = 0; i < rcnt; i++) {
        int f = 0;

        for (int j = 0; j < *vcnt; j++) {
            if (strcmp(v[j].name, r[i].name) == 0) {
                v[j].total += r[i].cena;
                v[j].count++;
                f = 1; // Устанавливаем флаг, что клиент найден
                break;
            }
        }

        // Если клиент не найден в массиве v, добавляем его
        if (f == 0) {
            strcpy(v[*vcnt].name, r[i].name);
            v[*vcnt].total = r[i].cena;
            v[*vcnt].count = 1;
            (*vcnt)++;
        }
    }
}
