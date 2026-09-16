#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int get_size(char std[]);
int scan(int size, char str[], char table[][2]);

void main()
{
    setlocale(LC_ALL, "Russian");
    char str1[20], str2[20];
    char table[26][2] = {{'A','1'}, { 'B','2' }, { 'C','3' }, { 'D','4' }, { 'E','5' }, {'F','1'}, { 'G','2' }, { 'H','3' }, { 'I','4' }, { 'J','5' }, {'K','1'}, { 'L','2' }, { 'M','3' }, { 'N','4' }, { 'O','5' }, {'P','1'}, { 'Q','2' }, { 'R','3' }, { 'S','4' }, { 'T','5' }, {'U','1'}, { 'V','2' }, { 'W','3' }, { 'X','4' }, { 'Y','5' }, { 'Z','6' }};
    printf("Игра Словодел");
    printf("\nВведите слово 1 игрока = ");
    fgets(str1, 20, stdin);
    int size1 = get_size(str1);
    printf("Введите слово 2 игрока = ");
    fgets(str2, 20, stdin);
    int size2 = get_size(str2);
    int result1 = scan(size1, str1, table);
    int result2 = scan(size2, str2, table);
    printf("Результат 1 игрока: %d", result1);
    printf("\nРезультат 2 игрока: %d", result2);
    if (result1 > result2) printf("\nПобеда 1 игрока"); else if (result1 < result2) printf("\nПобеда 2 игрока"); else printf("\nНичья");
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

int scan(int size, char str[], char table[][2])
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (table[j][0] == str[i]) result += table[j][1] - '0';
        }
    }
    return result;
}