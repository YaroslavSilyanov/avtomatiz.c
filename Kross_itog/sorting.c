#include <string.h>
#include "sorting.h"

// Функция для сортировки заказов по имени клиента
void sort_by_name(vhod r[], int rcnt) {
    for (int i = 0; i < rcnt - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < rcnt; j++) {
            if (strcmp(r[j].name, r[mini].name) < 0) {
                mini = j;
            }
        }
        if (mini != i) {
            vhod temp = r[i];
            r[i] = r[mini];
            r[mini] = temp;
        }
    }
}

// Функция для сортировки заказов по месяцу
void sort_by_month(vhod r[], int rcnt) {
    for (int i = 0; i < rcnt - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < rcnt; j++) {
            int m_i, m_j;
            sscanf(r[i].data, "%*d.%d.%*d", &m_i);
            sscanf(r[j].data, "%*d.%d.%*d", &m_j);
            // Сравниваем месяцы
            if (m_j < m_i) {
                mini = j;
            }
        }
        if (mini != i) {
            vhod t = r[i];
            r[i] = r[mini];
            r[mini] = t;
        }
    }
}
