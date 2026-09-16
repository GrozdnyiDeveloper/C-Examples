#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, c;
    printf("Введите размер первого отрезка: ");
    scanf("%d", &a);
    printf("Введите размер второго отрезка: ");
    scanf("%d", &b);
    printf("Введите размер третьего отрезка: ");
    scanf("%d", &c);
    if ((a + b > c) || (b + c > a) || (a + c > b))
    {
        printf("Треугольник существует; ");
        if ((a*a + b*b == c*c) || (b*b == a*a + c*c) || (a*a == b*b + c*c))
        {
            printf("Тип - прямоугольный.");
        }
        else 
        {
            if ((a == b) || (b == c) || (c == a))
            {
                printf("Тип - равнобедренный.");
            }
            else printf("Тип - обычный.");
        }
    }
    else printf("Треугольника не существует");
    return 0;
}
