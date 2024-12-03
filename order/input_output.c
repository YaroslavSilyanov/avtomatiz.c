#include <stdio.h>
#include "order.h"

void read_orders(FILE *in, vhod *r, int *rcnt) {
    while (fscanf(in, "%d %s %s %s %d", &r[*rcnt].id, r[*rcnt].name, r[*rcnt].data, r[*rcnt].product, &r[*rcnt].cena) != EOF) {
        (*rcnt)++;
    }
}

void process_orders(vhod *r, int rcnt, vihod *v, int *vcnt) {
    for (int i = 0; i < rcnt; i++) {
        int f = 0;
        for (int j = 0; j < *vcnt; j++) {
            if (strcmp(v[j].name, r[i].name) == 0) {
                v[j].total += r[i].cena;
                v[j].count++;
                f = 1;
                break;
            }
        }

        if (f == 0) {
            strcpy(v[*vcnt].name, r[i].name);
            v[*vcnt].total = r[i].cena;
            v[*vcnt].count = 1;
            (*vcnt)++;
        }
    }
}

