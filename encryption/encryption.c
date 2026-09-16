#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

char text[100];
char key[5];
int size;

int get_size();
void reverse();
void encryption();
void dencryption();
void change_places();

// Принцип шифрования:
// 1. Каждые 2 соседних символов меняются местами.
// 2. Текст разворачивается.
// 3. Шифрование по алгоритму: (Код текущего символа текста + Код текущего символа ключа (ключ повторяется)) % Кол-во букв в алфавите + 'A' (для преобразования в символ по таблице ASCII).
// 4. PROFIT

int main()
{
    setlocale(LC_ALL, "Russian");
    int operation;
    printf("Введите текст (Заглавными английскими буквами): ");
    fgets(text, 100, stdin);
    printf("Введите ключ (Заглавными английскими буквами): ");
    fgets(key, 5, stdin);
    printf("Выберите операцию: 1 - Шифрование, 2 - Дешифрование: ");\
    getchar();
    scanf("%d", &operation);
    switch (operation)
    {
    case 1:
        size = get_size();
        change_places();
        // printf("1. Смена местами: ");
        // puts(text);
        reverse();
        // printf("2. Разворот текста: ");
        // puts(text);
        encryption();
        // printf("3. Зашифровка через алгоритм: ");
        // puts(text);
        printf("\n");
        printf("Полученный результат: ");
        puts(text);
        printf("\n");
        break;
    
    case 2:
        size = get_size();
        dencryption();
        // printf("1. Расшифровка через алгоритм: ");
        // puts(text);
        reverse();
        // printf("2. Обратный разворот: ");
        // puts(text);
        change_places();
        // printf("3. Восстановление мест: ");
        // puts(text);
        printf("\n");
        printf("Полученный результат: ");
        puts(text);
        printf("\n");
        break;
    return 0;
    }
}
int get_size()
{
    int j = 0, size = -1;
    while (text[j])
    {
        size++;
        j++;
    }
    text[size] = ' ';
    return size;
}

void reverse()
{
    int j = 0;
    char reverse[100];
    for (int i = size - 1; i >= 0; i--)
    {
        reverse[j] = text[i];
        j++;
    }
    for (int i = 0; i < size; i++)
    {
        text[i] = reverse[i];
    }
}

void change_places()
{
    char s;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 1)
        {
            s = text[i - 1];
            text[i - 1] = text[i];
            text[i] = s;
        }
    }
}

void encryption()
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        text[i] = ((key[j] + text[i]) % 26 + 'A');
        if (j == 4) j = 0; else ++j;
    }
}

void dencryption()
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if  (text[i] < key[i]) text[i] += 26;
        text[i] = ((text[i] - key[j]) % 26 + 'A');
        if (j == 4) j = 0; else ++j;
    }
} 