#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;
namespace fastIO {
#define BUF_SIZE 100000
#define OUT_SIZE 1000000
bool IOerror = 0;

inline char nc() {
  static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, BUF_SIZE, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}

inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

inline int read(char *s) {
  char ch = nc();
  for (; blank(ch); ch = nc())
    ;
  if (IOerror)
    return 0;
  for (; !blank(ch) && !IOerror; ch = nc())
    *s++ = ch;
  *s = 0;
  return 1;
}

inline int RI(int &a) {
  char ch = nc();
  a = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror)
    return 0;
  for (; !blank(ch) && !IOerror; ch = nc())
    a = a * 10 + ch - '0';
  return 1;
}

struct Ostream_fwrite {
  char *buf, *p1, *pend;

  Ostream_fwrite() {
    buf = new char[BUF_SIZE];
    p1 = buf;
    pend = buf + BUF_SIZE;
  }

  void out(char ch) {
    if (p1 == pend) {
      fwrite(buf, 1, BUF_SIZE, stdout);
      p1 = buf;
    }
    *p1++ = ch;
  }

  void flush() {
    if (p1 != buf) {
      fwrite(buf, 1, p1 - buf, stdout);
      p1 = buf;
    }
  }

  ~Ostream_fwrite() { flush(); }
} Ostream;

inline void print(char x) { Ostream.out(x); }

inline void println() { Ostream.out('\n'); }

inline void flush() { Ostream.flush(); }

char Out[OUT_SIZE], *o = Out;

inline void print1(char c) { *o++ = c; }

inline void println1() { *o++ = '\n'; }

inline void flush1() {
  if (o != Out) {
    if (*(o - 1) == '\n')
      *--o = 0;
    puts(Out);
  }
}

struct puts_write {
  ~puts_write() { flush1(); }
} _puts;
};

struct Trie {
  int next[500010][26], fail[500010], end[500010];
  int root, L;

  int newnode() {
    for (int i = 0; i < 26; i++)
      next[L][i] = -1;
    end[L++] = 0;
    return L - 1;
  }

  void init() {
    L = 0;
    root = newnode();
  }

  void insert(char buf[], int len) {
    // int len = strlen(buf);
    int now = root;
    for (int i = 0; i < len; i++) {
      if (next[now][buf[i] - 'a'] == -1)
        next[now][buf[i] - 'a'] = newnode();
      now = next[now][buf[i] - 'a'];
    }
    end[now]++;
  }

  void build() {
    queue<int> Q;
    fail[root] = root;
    for (int i = 0; i < 26; i++)
      if (next[root][i] == -1)
        next[root][i] = root;
      else {
        fail[next[root][i]] = root;
        Q.push(next[root][i]);
      }
    while (!Q.empty()) {
      int now = Q.front();
      Q.pop();
      for (int i = 0; i < 26; i++)
        if (next[now][i] == -1)
          next[now][i] = next[fail[now]][i];
        else {
          fail[next[now][i]] = next[fail[now]][i];
          Q.push(next[now][i]);
        }
    }
  }

  int query(char buf[], int len) {
    // int len = strlen(buf);
    int now = root;
    int res = 0;
    for (int i = 0; i < len; i++) {
      now = next[now][buf[i] - 'a'];
      int temp = now;
      while (temp != root) {
        res += end[temp];
        end[temp] = 0;
        temp = fail[temp];
      }
    }
    return res;
  }

  void debug() {
    for (int i = 0; i < L; i++) {
      printf("id = %3d,fail = %3d,end = %3d,chi = [", i, fail[i], end[i]);
      for (int j = 0; j < 26; j++)
        printf("%2d", next[i][j]);
      printf("]\n");
    }
  }
};

char buf[100000 + 10];
char lgst[100000 + 10];
int maxLen;
Trie ac;

int main() {
  int T;
  int n;
  fastIO::RI(T);
  // scanf("%d", &T);
  while (T--) {
    fastIO::RI(n);
    ac.init();
    // memset(buf, 0, sizeof(buf));
    // memset(lgst, 0, sizeof(lgst));
    maxLen = 0;
    for (int i = 0; i < n; i++) {
      // scanf("%s", buf);
      // gets(buf);
      fastIO::read(buf);
      int len = strlen(buf);
      ac.insert(buf, len);

      if (len > maxLen) {
        memcpy(lgst, buf, len + 1);
        maxLen = len;
      }
    }
    ac.build();
    int res = ac.query(lgst, maxLen);
    // printf("\t %d \n", res);
    if (res == n) {
      for (int i = 0; i < maxLen; i++) {
        fastIO::print1(lgst[i]);
      }
      fastIO::println1();
    } else {
      fastIO::print1('N');
      fastIO::print1('o');
      fastIO::println1();
    }
  }
  return 0;
}
