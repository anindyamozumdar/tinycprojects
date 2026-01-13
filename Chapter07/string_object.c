#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string {
    char *value;
    int length;
};

int string_create (struct string *s, char *v)
{
    if (s == NULL) {
        return 0;
    }

    s->length = strlen(v);
    s->value = (char *) malloc(sizeof(char) * s->length + 1);
    if (s->value == NULL) {
        return 0;
    }

    strcpy(s->value, v);
    return 1;
}

void string_destroy (struct string *s)
{
    free(s->value);
    s->value = NULL;
    s->length = 0;
}

int main (void)
{
    struct string *s;
    if (string_create(s, "Anindya Mozumdar")) {
        printf("The struct has value %s with length %d.\n", s->value, s->length);
        string_destroy(s);
        printf("After destruction, length is %d.\n", s->length);
    } else {
        fprintf(stderr, "Error.\n");
    }

    return 0;
}