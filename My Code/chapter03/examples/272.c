#include <stdio.h>
#include <string.h>

int main() {
    char c;
    int flag = 0;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            if (flag)
                printf("''");
            else
                printf("``");
            flag = !flag;
        } else
            printf("%c", c);
    }
    return 0;
}