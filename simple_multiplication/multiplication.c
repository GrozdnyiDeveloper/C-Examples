#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b;
    printf("Введите первое число ");
    scanf("%d", &a);
    printf("Введите второе число ");
    scanf("%d", &b);
    int a1 = a;
    for (int i = 0; i < b - 1; i++)
    {
        a += a1;
    }
    printf("Полученное число: %d", a);
    return 0;
}
