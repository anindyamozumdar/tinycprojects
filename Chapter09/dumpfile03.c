#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

void line_out (int offset, int length, unsigned char *data)
{
    int a;

    printf("%05X ", offset);

    for (a = 0; a < length; a++) {
        printf(" %02X", *(data + a));
        if ((a + 1) % 8 == 0) {
            putchar(' ');
        }
    }

    if (length < SIZE) {
        for (; a < SIZE; a++) {
            printf("   ");
            if ((a + 1) % 8 == 0) {
                putchar(' ');
            }
        }
    }

    for (a = 0; a < length; a++) {
        if (*(data + a) >= ' ' && *(data + a) <= '~') {
            putchar(*(data + a));
        } else {
            putchar(' ');
        }
    }

    putchar('\n');
}

int main (int argc, char *argv[])
{
    char filename[128];
    if (argc < 2) {
        // fprintf(stderr, "Usage: dumpfile <filename>\n");
        fprintf(stdout, "No filename provided. Enter filename: ");
        fgets(filename, 128, stdin);
        if (filename[0] == '\n') {
            fprintf(stderr, "No filename provided.\n");
            exit(1);
        } else {
            filename[strlen(filename) - 1] = '\0';
        }
        printf("Entered filename: '%s'\n", filename);
    } else if (argc == 2) {
        strcpy(filename, argv[1]);
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    int ch;
    const int length = SIZE;
    unsigned char buffer[length];
    int offset = 0;
    int index = 0;
    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ch == EOF) {
            if (index != 0) {
                line_out(offset, index, buffer);
            }
            break;
        }
        buffer[index] = ch;
        index++;
        if (index == length) {
            line_out(offset, length, buffer);
            offset += length;
            index = 0;
        }
    }

    fclose(fp);
    return 0;
}