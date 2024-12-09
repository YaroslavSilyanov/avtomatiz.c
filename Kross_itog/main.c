#include <stdio.h>
#include "input.h"
#include "processing.h"
#include "sorting.h"
#include "commands.h"

int main() {
    vhod r[MAX];
    vihod v[MAX];
    int rcnt = 0, vcnt = 0;

    // Ввод заказов
    input_orders("in.txt", r, &rcnt);

    // Расчет суммы и количества заказов для каждого клиента
    process_orders(r, rcnt, v, &vcnt);

    // Выбор команды
    char com[MAX];
    printf("Vvedite komandu: (summa), (kolvo), (allzakaz), (month) ili (srchek)\n");
    scanf("%s", com);

    if (strcmp(com, "summa") == 0) {
        c_sum(v, vcnt, "out.txt");
    } else if (strcmp(com, "kolvo") == 0) {
        c_count(v, vcnt, "out.txt");
    } else if (strcmp(com, "allzakaz") == 0) {
        sort_by_name(r, rcnt);
        c_allorders(r, rcnt, "out.txt");
    } else if (strcmp(com, "month") == 0) {
        sort_by_month(r, rcnt);
        c_months(r, rcnt, "out.txt");
    } else if (strcmp(com, "srchek") == 0) {
        c_check(v, vcnt, "out.txt");
    } else {
        printf("Nevernaya komanda\n");
    }

    return 0;
}
