#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX 100

// Структура для хранения данных о заказе
typedef struct {
    int id;          // Идентификатор заказа
    char name[MAX];  // Имя заказчика
    char data[MAX];  // Дата заказа (в формате ДД.ММ.ГГГГ)
    char product[MAX]; // Название продукта
    int cena;        // Цена продукта
} vhod;

// Структура для хранения вывода
typedef struct {
    char name[MAX];  // Имя заказчика
    int total;       // Общая сумма заказов
    int count;       // Количество заказов
} vihod;

#endif
