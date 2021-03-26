#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

char head[256], encode[1005], decode[1005];

int stringToInt(char* s, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (1 << (n - 1 - i)) * (s[i] - '0');
    }
    return sum;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    while (scanf("%[^\n]s", head) == 1) {
        scanf("%s", encode);
        //当前位置
        int encodePos = 0, decodePos = 0, n, m;
        while (strlen(encode) < 3)
            scanf("%s", encode + strlen(encode));
        while (strncmp(encode + encodePos, "000", 3)) {
            //位数
            n = stringToInt(encode + encodePos, 3);
            encodePos += 3;
            while (strlen(encode) - encodePos < n)
                scanf("%s", encode + strlen(encode));
            //n位二进制组成的数
            while ((m = stringToInt(encode + encodePos, n)) != ((1 << n) - 1)) {
                encodePos += n;
                //解码
                decode[decodePos] = head[(1 << n) - n + m - 1];
                ++decodePos;
                while (strlen(encode) - encodePos < n)
                    scanf("%s", encode + strlen(encode));
            }
            encodePos += n;
            while (strlen(encode) < 3)
                scanf("%s", encode + strlen(encode));
        }
        decode[decodePos] = 0;
        printf("%s\n", decode);
        getchar();
    }
    return 0;
}