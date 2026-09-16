#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, now = 1, last = 0;
    printf("Введите двоичное число: ");
    scanf("%d", &a);
    while (a)
    {
        b = a % 10;
        a = a / 10;
        last = last + (b * now);
        now = now * 2;
    }
    printf("Полученный результат: %d", last);
    return 0;
}