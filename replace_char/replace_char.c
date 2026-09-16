#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    char str[81] = "";
    printf("¬ведите строку: ");
    fgets(str, 81, stdin);
    for (int i = 0; i < 81; i++)
    {
        if (str[i] == '?') str[i] = '!';
    }
    printf("–езультат: ");
    puts(str);
    return 0;
}