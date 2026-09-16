#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    char mask[36];
    int cidr;
    printf("Введите маску подсети способом CIDR: ");
    scanf("%d", &cidr);
    printf("Введённое значение: /%d", cidr);
    ++cidr;
    for (int i = 0; i < cidr; i++)
    {
        if (i == 0) mask[i] = ' '; else
        if ((i % 9 == 0) && (i < 30)) 
        {
            mask[i] = '.'; 
            ++cidr;
        }
        else mask[i] = '1';
    }
    for (int i = cidr; i < 36; i++)
    {
        if ((i % 9 == 0) && (i < 30)) mask[i] = '.'; else mask[i] = '0';
    }
    
    printf("\nПолученная маска подсети:");
    for (int i = 0; i <= 35; i++) printf("%c", mask[i]);
    return 0;
}
