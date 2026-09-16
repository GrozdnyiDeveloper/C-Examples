#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int get_size(char std[]);
void reverse(int size, char str[]);

void main()
{
    setlocale(LC_ALL, "Russian");
    char str[100];
    printf("Программа для обратных слов");
    printf("\nВведите слово = ");
    fgets(str, 100, stdin);
    int size = get_size(str);
    printf("Длина слова: %d", size);
    reverse(size, str);
}

int get_size(char str[])
{
    int j = 0, size = -1;
    while (str[j])
    {
        size++;
        j++;
    }
    return size;
}

void reverse(int size, char str[])
{
    int j = 0;
    for (int i = size * 2; i >= size - 1; i--)
    {
        str[i] = str[j];
        j++;
    }
    printf("\nОбратное слово: ");
    for (int i = size; i < (size * 2) + 1; i++)
    {
        printf("%c", str[i]);
    }
}
