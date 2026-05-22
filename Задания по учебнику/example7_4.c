//подключаем необходимые библиотеки
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define N 10

void printMas(int mas[N][N]) {          //поэлементный вывод элементов массива
    for (int i = 0; i < N; i++) {       //проходим по строкам
        for (int j = 0; j < N; j++)     //по элементам строки
            printf("%4d", mas[i][j]);
        printf("\n");
    }
    printf("\n");
}
void generateRandomMas(int mas[N][N]) { //заполнение массива случайными числами от 0 до 100
    for (int i = 0; i < N; i++)         //проходим по строкам
        for (int j = 0; j < N; j++)     //по элементам строки
            mas[i][j] = rand() % 101;
}
int main() {

    int mas1[N][N];//объявляем двумерные массивы
    int mas2[N][N];
    int result[N][N];
    srand(time(0));                         //задаем начальное значение для генератора случайных чисел (зерно генерации) с помощью текущего времени

                                            //заполняем массивы и выводим их
    generateRandomMas(mas1);
    generateRandomMas(mas2);
    printMas(mas1);
    printMas(mas2);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result[i][j] = mas1[i][j] + mas2[i][j];//result = сумма элементов массивов mas1 и mas2 с теми же индексами

    printMas(result);
    return 0;
}