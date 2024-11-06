#include <stdio.h>
#include <string.h>

#define MAX 100

//структура входного файла
typedef struct {
    int id;
    char name[MAX];
    char data[MAX];
    char product[MAX];
    int cena;
} vhod;

//структура выходного файла
typedef struct {
    char name[MAX];
    int total;
    int count;
} vihod;

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

    //читаем данные из файла
    in = fopen("in.txt", "r");
    FILE *out = fopen("out.txt", "w");

    vhod r[MAX];
    vihod v[MAX];
    int rcnt = 0, vcnt = 0;

    while (fscanf(in, "%d %s %s %s %d", &r[rcnt].id, r[rcnt].name, r[rcnt].data, r[rcnt].product, &r[rcnt].cena) != EOF) {
        rcnt++;
    }
    fclose(in);

    // счет суммы и количества
    for (int i = 0; i < rcnt; i++) {
        int f = 0;
        for (int j = 0; j < vcnt; j++) {
            if (strcmp(v[j].name, r[i].name) == 0) {
                v[j].total += r[i].cena;
                v[j].count++;
                f = 1;
                break;
            }
        }

        if (f == 0) {
            strcpy(v[vcnt].name, r[i].name);
            v[vcnt].total = r[i].cena;
            v[vcnt].count = 1;
            vcnt++;
        }
    }

    // выбор команды
    char com[MAX];
    int tsum = 0, tcnt = 0;

    printf("Введите команду: (сумма), (количество), (всезаказы) или (месяцы)\n");
    scanf("%s", com);

    if (strcmp(com, "сумма") == 0) {
        
        // вывод суммы
        for (int i = 0; i < vcnt; i++) {
            fprintf(out, "%s %d\n", v[i].name, v[i].total);
            tsum += v[i].total;
        }
        fprintf(out, "Общая сумма всех заказов: %d\n", tsum);
    } else if (strcmp(com, "количество") == 0) {
        
        // вывод количества
        for (int i = 0; i < vcnt; i++) {
            fprintf(out, "%s %d\n", v[i].name, v[i].count);
            tcnt += v[i].count;
        }
        fprintf(out, "Общее количество всех заказов: %d\n", tcnt);
    } else if (strcmp(com, "всезаказы") == 0) {
        
        // вывод всех заказов
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
    } else if (strcmp(com, "месяцы") == 0) {
        
        // сортировка по возрастанию месяца
        for (int i = 0; i < rcnt - 1; i++) {
            int mini = i;
            for (int j = i + 1; j < rcnt; j++) {
                int m_i, m_j;
                sscanf(r[i].data, "%*d.%d.%*d", &m_i);
                sscanf(r[j].data, "%*d.%d.%*d", &m_j);

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

        // вывод и группировка месяцев
        int cm = -1;
        for (int i = 0; i < rcnt; i++) {
            int m;
            sscanf(r[i].data, "%*d.%d.%*d", &m);

            if (m != cm) {
                cm = m;
                switch (m) {
                    case 1: fprintf(out, "\nЯнварь\n");
                    break;
                    case 2: fprintf(out, "\nФевраль\n"); 
                    break;
                    case 3: fprintf(out, "\nМарт\n"); 
                    break;
                    case 4: fprintf(out, "\nАпрель\n"); 
                    break;
                    case 5: fprintf(out, "\nМай\n"); 
                    break;
                    case 6: fprintf(out, "\nИюнь\n"); 
                    break;
                    case 7: fprintf(out, "\nИюль\n"); 
                    break;
                    case 8: fprintf(out, "\nАвгуст\n");
                    break;
                    case 9: fprintf(out, "\nСентябрь\n"); 
                    break;
                    case 10: fprintf(out, "\nОктябрь\n"); 
                    break;
                    case 11: fprintf(out, "\nНоябрь\n"); 
                    break;
                    case 12: fprintf(out, "\nДекабрь\n"); 
                    break;
                    default: break;
                }
            }
            fprintf(out, "%d %s %s %s %d\n", r[i].id, r[i].name, r[i].data, r[i].product, r[i].cena);
        }
    } else {
        printf("Неверная команда\n");
    }

    fclose(out);

    return 0;
}
