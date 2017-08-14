#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;
long long ip;
int range;
void readin() {
  long long a, b, c, d;
  scanf("%lld.%lld.%lld.%lld/%d", &a, &b, &c, &d, &range);
  // printf("%llx %llx %llx %llx %lld\n", a, b, c, d, range);
  ip = (a << 24) + (b << 16) + (c << 8) + d;
  // printf("%llx", ip >> (32 - range));
}

const int CHARSET = 2, MAX_NODE = (int)1e5;

struct Trie {
  int tot, root, child[MAX_NODE][CHARSET];
  set<int> flag[MAX_NODE];

  Trie() {
    memset(child[1], 0, sizeof(child[1]));
    flag[1].clear();
    root = tot = 1;
  }

  void insert(const long long ip, int mask, int id) {
    int *cur = &root;
    for (long long i = 31; i >= (32 - mask); i--) {
      int p = (ip >> i) & 1;
      cur = &child[*cur][p];
      if (*cur == 0) {
        *cur = ++tot;
        memset(child[tot], 0, sizeof(child[tot]));
        flag[tot].clear();
      }
    }
    flag[*cur].insert(id);
  }

  void del(const long long ip, int mask, int id) {
    int *cur = &root;
    for (long long i = 31; i >= (32 - mask); i--) {
      int p = (ip >> i) & 1;
      cur = &child[*cur][p];
    }
    flag[*cur].erase(id);
  }

  void query(const long long &ip1, const long long &ip2) {
    int *cur = &root;
    set<int>::iterator it, c;
    set<int> info;
    for (long long i = 31; i >= 0 && *cur; i--) {
      int p = (ip1 >> i) & 1;
      cur = &child[*cur][p];
      for (it = flag[*cur].begin(); it != flag[*cur].end(); ++it) {
        info.insert(*it);
        // printf("ty1 %d \n", *it);
      }
    }
    cur = &root;
    c = info.end();
    for (long long i = 31; i >= 0 && *cur; i--) {
      int p = (ip2 >> i) & 1;
      cur = &child[*cur][p];
      for (it = flag[*cur].begin(); it != flag[*cur].end(); ++it) {
        // printf("ty2 %d \n", *it);
        if (info.find(*it) != c) {
          puts("F");
          return;
        }
      }
    }
    puts("D");
  }
};

int id, n;
Trie trie;
char s[10];
int pn[1025];
long long pip[1025][16];
int prange[1025][16];

int main() {
  while (~scanf("%s", s)) {
    if (s[0] == 'E') {
      scanf("%d%d", &id, &n);
      pn[id] = n;
      for (int i = 0; i < n; i++) {
        readin();
        trie.insert(ip, range, id);
        pip[id][i] = ip;
        prange[id][i] = range;
      }
    } else if (s[0] == 'D') {
      scanf("%d", &id);
      for (int i = 0; i < pn[id]; i++) {
        trie.del(pip[id][i], prange[id][i], id);
      }

    } else {
      readin();
      long long ip2 = ip;
      // int range2=range;
      readin();
      trie.query(ip2, ip);
    }
  }
  return 0;
}
