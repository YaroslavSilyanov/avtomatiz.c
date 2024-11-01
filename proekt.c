#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[MAX];
    char data[MAX];
    char product[MAX];
    int cena;
} vhod;

typedef struct {
    char name[MAX];
    int total;
} vihod;

int main() {
    FILE *in = fopen("in.txt", "a");

    vhod t;

    printf("id name data product cena\n");
    while (scanf("%d", &t.id) == 1 && t.id != 0) {
    scanf("%s %s %s %d", t.name, t.data, t.product, &t.cena);
    
    fprintf(in, "%d %s %s %s %d\n", t.id, t.name, t.data, t.product, t.cena);
    }
    fclose(in);

    in = fopen("in.txt", "r");
    FILE *out = fopen("out.txt", "w");
    
    vhod r[MAX];
    vihod v[MAX];
    int rcnt = 0, vcnt = 0;


    while (fscanf(in, "%d %s %s %s %d", &r[rcnt].id, r[rcnt].name, r[rcnt].data, r[rcnt].product, &r[rcnt].cena) != EOF) {
        rcnt++;
    }
    fclose(in);

    for (int i = 0; i < rcnt; i++) {
        int f = 0;

        for (int j = 0; j < vcnt; j++) {
            if (strcmp(v[j].name, r[i].name) == 0) {
                v[j].total += r[i].cena; 
                f = 1;
                break;
            }
        }

        if (f == 0) {
            strcpy(v[vcnt].name, r[i].name);
            v[vcnt].total = r[i].cena;
            vcnt++;
        }
    }

    for (int i = 0; i < vcnt; i++) {
        fprintf(out, "%s %d\n", v[i].name, v[i].total);
    }
    fclose(out);

    return 0;
}
