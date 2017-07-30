#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

const int MaxN = 1000010;
char S[MaxN];
int N, K, Next[MaxN], Mark[MaxN];
bool Ans[MaxN];

int main() {
    scanf("%d%d", &N, &K);
    scanf("%s", S + 1);
    for (int i = 1, j = 0; i <= N; i++) {
        while (j && (S[j + 1] != S[i])) j = Next[j];
        if ((S[j + 1] == S[i]) && (i != 1)) j++;
        Next[i] = j;
        int t = i - Next[i];
        if (i % t == 0) {
            t = i / t;
            if (t % K <= t / K) putchar('1');
            else putchar('0');
        }
		else {
            t = i / t;
            if (t % K < t / K) putchar('1');
            else putchar('0');
        }
    }
    puts("");
    return 0;
}
