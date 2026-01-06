#include <stdio.h>

enum word_states { WS, FL, IN };

void strcaps (char *s)
{
    enum word_states word_state = WS;
    while (*s) {
        if (word_state == WS) {
            if (*s == ' ' || *s == '\t' || *s == '\n') {
                word_state = WS;
            } else {
                word_state = FL;
                if (*s >= 'a' && *s <= 'z') {
                    *s &= 0xdf;
                }
            }
        } else if (word_state == FL || word_state == IN) {
            if (*s == ' ' || *s == '\t' || *s == '\n') {
                word_state = WS;
            } else {
                word_state = IN;
                if (*s >= 'A' && *s <= 'Z') {
                    *s += 32;
                }
            }
        }
        s++;
    }
}

int main (void)
{
    char string[] = "hello anindya mozumdar\t. TEST code.   test code.\n Test Code. 12 main.";
    printf("Original: %s\n", string);
    strcaps(string);
    printf("Modified: %s\n", string);

    return 0;
}