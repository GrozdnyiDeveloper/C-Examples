#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, fin;
    char x;
    printf("¬ведите первое число: ");
    scanf("%d", &a);
    printf("¬ведите второе число: ");
    scanf("%d", &b);
    printf("¬ведите нужную функцию (+, -, *, /, ^, %%): ");
    scanf("%c", &x);
    scanf("%c", &x);
    switch (x)
    {
        case '+':
            fin = a + b;
            break;

        case '-':
            fin = a - b;
            break;

        case '*':
            fin = a * b;
            break;

        case '/':
            fin = a / b;
            break;

        case '^':
            fin = 1;
            for (int i = 0; i < b; i++)
            {
                fin *= a;
            }
            break;
        case '%':
            fin = a % b;
            break;
    }
    printf("ќтвет: %d", fin);
    return 0;
}
