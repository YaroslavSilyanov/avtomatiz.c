#include <stdio.h>
#include <string.h>
#include "order.h"

int main() {
    FILE *in = fopen("in.txt", "a");
    vhod t;
    printf("id name data product cena\n");

    // ввод заказов
    while (scanf("%d", &t.id) == 1 && t.id != 0) {
        scanf("%s %s %s %d", t.name, t.data, t.product, &t.cena);
        fprintf(in, "%d %s %s %s %d\n", t.id, t.name, t.data, t.product, t.cena);
    }
    fclose(in);

    // читаем данные из файла
    in = fopen("in.txt", "r");
    FILE *out = fopen("out.txt", "w");

    vhod r[MAX];
    vihod v[MAX];
    int rcnt = 0, vcnt = 0;

    read_orders(in, r, &rcnt);
    fclose(in);

    // процесс обработки заказов
    process_orders(r, rcnt, v, &vcnt);

    // выбор команды
    process_commands(out, v, vcnt, r, rcnt);

    fclose(out);

    return 0;
}
