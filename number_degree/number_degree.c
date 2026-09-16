#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, a1;
    printf("Введите число: ");
    scanf("%d", &a);
    printf("Введите степень: ");
    scanf("%d", &b);
    a1 = a;
    for (int i = 0; i < b-1; i++)
    {
        a *= a1;
    }
    printf("Полученный результат: %d", a);
    return 0;
}
