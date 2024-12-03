#include <stdio.h>
#include <string.h>
#include "order.h"

void process_commands(FILE *out, vihod *v, int vcnt, vhod *r, int rcnt) {
    char com[MAX];
    int tsum = 0, tcnt = 0;

    printf("vvedite komandu: (summ), (kolvo), (vse), (mecyac) ili (srchek)\n");
    scanf("%s", com);

    if (strcmp(com, "summ") == 0) {
        // вывод суммы заказов
        for (int i = 0; i < vcnt; i++) {
            fprintf(out, "%s %d\n", v[i].name, v[i].total);
            tsum += v[i].total;
        }
        fprintf(out, "obshaya summ vseh zakazov: %d\n", tsum);

    } else if (strcmp(com, "kolvo") == 0) {
        // вывод количества заказов
        for (int i = 0; i < vcnt; i++) {
            fprintf(out, "%s %d\n", v[i].name, v[i].count);
            tcnt += v[i].count;
        }
        fprintf(out, "obshee kolvo vseh zakazov: %d\n", tcnt);

    } else if (strcmp(com, "vse") == 0) {
        // сортировка заказов
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

        for (int i = 0; i < rcnt; i++) {
            fprintf(out, "%d %s %s %s %d\n", r[i].id, r[i].name, r[i].data, r[i].product, r[i].cena);
            if (i < rcnt - 1 && strcmp(r[i].name, r[i + 1].name) != 0) {
                fprintf(out, "\n");
            }
        }

    } else if (strcmp(com, "srchek") == 0) {
        // средний чек
        float obshee = 0.0;
        for (int i = 0; i < vcnt; i++) {
            float sr = (float)v[i].total / v[i].count;
            fprintf(out, "%s %.2f\n", v[i].name, sr);
            obshee += v[i].total;
            tcnt += v[i].count;
        }

        if (tcnt > 0) {
            obshee /= tcnt;
        }
        fprintf(out, "\nsrchek vseh zakazov: %.2f\n", obshee);

    } else {
        printf("nevernaya komada\n");
    }
}

