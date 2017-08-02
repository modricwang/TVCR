

const int N = (int)1e5;
int Tree[N * 32], lazy[N * 32], Sum[N * 32];

void push(int t, int l, int r) {
  lazy[t << 1] = lazy[t];
  lazy[t << 1 | 1] = lazy[t];
  Sum[t] = lazy[t] * (r - l + 1);
  lazy[t] = 0;
}

void update(int t) { Sum[t] = Sum[t << 1] + Sum[t << 1 | 1]; }

void Modify(int t, int l, int r, int x, int y, int v) { //[x, y] = v
  if (l <= x && y <= r) {
    lazy[t] = v;
    return;
  }
  push(t, l, r); //
  int mid = l + r >> 1;
  if (x <= mid)
    Modify(t << 1, l, mid, x, y, v);
  if (y > mid)
    Modify(t << 1 | 1, mid + 1, r, x, y, v);
  push(t << 1, l, mid);
  push(t << 1 | 1, mid + 1, r);
  update(t);
}

void Build(int t, int l, int r) {
  if (l == r) {
    Tree[t] = a[l];
    Sum[t] = a[l];
    lazy[t] = 0;
    return;
  }
  int mid = l + r >> 1;
  Build(t << 1, l, mid);
  Build(t << 1, mid + 1, r);
  update(t);
}

int Query(int t, int l, int r, int x, int y) {
  push(t, l, r);
  if (x <= l && y <= r) {
    return Sum[t];
  }
  int mid = l + r >> 1, tmp = 0;
  if (x <= mid)
    tmp += Query(t << 1, l, mid, x, y);
  if (y > mid)
    tmp += Query(t << 1, mid + 1, r, x, y);
  return tmp;
}
