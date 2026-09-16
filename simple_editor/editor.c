#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

void write_in_file(const char *filename, const char *string)
{
    int fd = open(filename, O_APPEND | O_WRONLY | O_CREAT, S_IWRITE);
    if (fd == -1) {
        perror("open");
        return;
    }
    if (write(fd, string, strlen(string)) == -1)
        perror("write");
    if (write(fd, "\n", 1) == -1)
        perror("write");
    close(fd);
}

int main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <file> <W|S> <string>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *mode     = argv[2];
    const char *string   = argv[3];

    switch (mode[0]) {
    case 'W': {
        int fd = open(filename, O_WRONLY);
        if (fd == -1) {
            printf("Файла не существует. Хотите создать новый файл?(y/n): ");
            int answer = getc(stdin);
            if (answer == 'y') {
                int fd2 = open(filename, O_WRONLY | O_CREAT, S_IWRITE);
                if (fd2 == -1) { perror("open"); return 1; }
                close(fd2);
                write_in_file(filename, string);
            } else {
                perror("EXIT");
            }
        } else {
            close(fd);
            write_in_file(filename, string);
        }
        break;
    }

    case 'S': {
        int fd = open(filename, O_RDONLY);
        if (fd == -1) {
            perror("EXIT");
            return 1;
        }
        char buffer[100];
        int bytes_read = read(fd, buffer, sizeof(buffer) - 1);
        close(fd);
        if (bytes_read < 0) { perror("read"); return 1; }
        buffer[bytes_read] = '\0';

        int target = string[0] - '0';
        int number = 1;
        int j = 0;
        char result[100];

        for (int i = 0; i < bytes_read; i++) {
            if (number == target) {
                if (j < (int)sizeof(result) - 1)
                    result[j++] = buffer[i];
            }
            if (buffer[i] == '\n')
                number++;
        }
        result[j] = '\0';
        printf("Полученная строка: %s\n", result);
        break;
    }

    default:
        fprintf(stderr, "Неизвестный режим: %c\n", mode[0]);
        return 1;
    }

    return 0;
}