#include <stdio.h>
#include <string.h>
char arr[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
    int c, pos;
    while ((c = getchar()) != EOF) {
        pos = -1;
        for (int i = 0; i < strlen(arr); ++i) {
            if (c == arr[i]) {
                pos = i;
                break;
            }
        }
        if (pos != -1)
            putchar(arr[pos - 1]);
        else
            putchar(c);
    }
    return 0;
}