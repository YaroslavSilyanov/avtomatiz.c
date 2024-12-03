#ifndef ORDER_H
#define ORDER_H

#define MAX 100

// ��������� ��� ������� ������
typedef struct {
    int id;
    char name[MAX];
    char data[MAX];
    char product[MAX];
    int cena;
} vhod;

// ��������� ��� �������� ������
typedef struct {
    char name[MAX];
    int total;
    int count;
} vihod;

// ���������� �������
void read_orders(FILE *in, vhod *r, int *rcnt);
void process_orders(vhod *r, int rcnt, vihod *v, int *vcnt);
void process_commands(FILE *out, vihod *v, int vcnt, vhod *r, int rcnt);

#endif
