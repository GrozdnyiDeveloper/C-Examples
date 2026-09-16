#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int arr [10];
    int a = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("Введите %d число: ", i+1);
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 1)
        {
            ++a;
        }
    }
    printf("\nЧётных чисел: %d", 10 - a);
    printf("\nНечётных чисел: %d", a);
    return 0;
}