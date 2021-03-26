#include <ctype.h>
#include <stdio.h>

int main() {
    int T, num;
    double ele;
    scanf("%d", &T);
    char s[100];
    while (T--) {
        scanf("%s", s);
        int i = 0, first = 1;
        double weight = 0;
        while (s[i]) {
            if (isalpha(s[i])) {
                if (!first)
                    weight += (num == 0 ? 1 : num) * ele;
                else
                    first = !first;
                num = 0;
                switch (s[i]) {
                case 'C':
                    ele = 12.01;
                    break;
                case 'H':
                    ele = 1.008;
                    break;
                case 'O':
                    ele = 16.00;
                    break;
                case 'N':
                    ele = 14.01;
                    break;
                }
            } else
                num = num * 10 + (s[i] - '0');
            ++i;
        }
        weight += (num == 0 ? 1 : num) * ele;
        printf("%.3f\n", weight);
    }
    return 0;
}