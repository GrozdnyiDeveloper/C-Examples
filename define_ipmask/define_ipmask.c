#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    char ip[15] = "";
    char now[3] = "";
    int j = 0, result = 0;
    printf("Введите IP-адрес: ");
    fgets(ip, 15, stdin);
    printf("IP-адрес: "); puts(ip);
    while (ip[j] != '.')
    {
        now[j] = ip[j];
        j++;
    }
    for (int i = 0; i < 3; i++)
    {
        result = result * 10 + (now[i] - '0');
    }
    if (result < 128) printf("Класс А, Маска подсети: 255.0.0.0.");
    else if (result < 192) printf("Класс B, Маска подсети: 255.255.0.0.");
    else if (result < 224) printf("Класс C, Маска подсети: 255.255.255.0.");
    else if (result < 240) printf("Класс D. ");
    else printf("Класс E. ");
    return 0;
}