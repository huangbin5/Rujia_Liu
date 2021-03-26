#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define DEBUG

double EPS = 1e-6;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char line[256];
    double lg2 = log10(2), A, v;
    int B;
    while (scanf("%s", line) == 1 && strcmp(line, "0e0") != 0) {
        *strchr(line, 'e') = ' ';
        sscanf(line, "%lf%d", &A, &B);
        v = log10(A) + B;
        for (int M = 1; M <= 10; ++M) {
            int E = round(log10((v - log10(pow(2, M) - 1) + M * lg2) / lg2 + 1) / lg2);
            if (fabs(log10(pow(2, M) - 1) - M * lg2 + lg2 * ((1 << E) - 1) - v) <= EPS) {
                printf("%d %d\n", M - 1, E);
                break;
            }
        }
    }
    return 0;
}