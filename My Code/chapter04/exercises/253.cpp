#include <cstring>
#include <iostream>
using namespace std;
#define DEBUG

struct IP {
    int a, b, c, d;
};

IP address[1005];
char binIP[1005][35];
int m, len;

void digitToBin(int idx, int num, int pos) {
    int curPos = 8 * pos - 1;
    while (num > 0) {
        binIP[idx][curPos--] = num % 2 + '0';
        num /= 2;
    }
    while (curPos >= 8 * (pos - 1))
        binIP[idx][curPos--] = '0';
}

void ipToBin(int idx, IP ip) {
    digitToBin(idx, ip.a, 1);
    digitToBin(idx, ip.b, 2);
    digitToBin(idx, ip.c, 3);
    digitToBin(idx, ip.d, 4);
    binIP[idx][32] = 0;
}

int binToDigit(char* p1, char* p2) {
    int sum = 0;
    for (char* p = p1; p < p2; ++p)
        sum = (sum << 1) + *p - '0';
    return sum;
}

void binToIp(char* str, IP& ip) {
    ip.a = binToDigit(str, str + 8);
    ip.b = binToDigit(str + 8, str + 16);
    ip.c = binToDigit(str + 16, str + 24);
    ip.d = binToDigit(str + 24, str + 32);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d.%d.%d.%d", &address[i].a, &address[i].b, &address[i].c, &address[i].d);
        ipToBin(i, address[i]);
    }
    bool flag = true;
    for (int i = 0; i < 32; ++i) {
        char tmp = binIP[0][i];
        for (int j = 1; j < m; ++j) {
            if (tmp != binIP[j][i]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            len = i;
            break;
        }
    }
    char binNetwork[32], binMask[32];
    memset(binNetwork, '0', sizeof(binNetwork));
    memset(binMask, '0', sizeof(binMask));
    memset(binMask, '1', len);
    strncpy(binNetwork, binIP[0], len);
    IP network, mask;
    binToIp(binNetwork, network);
    binToIp(binMask, mask);
    printf("%d.%d.%d.%d\n", network.a, network.b, network.c, network.d);
    printf("%d.%d.%d.%d\n", mask.a, mask.b, mask.c, mask.d);
    return 0;
}