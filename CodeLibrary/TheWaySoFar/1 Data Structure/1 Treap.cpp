template <class T> struct Treap {
    int nodecnt , prior[M];
    int cnt[M] , size[M] , c[M][2];
    T key[M] , GCD[M];
    void clear() {
        nodecnt = 1;
        prior[0] = -1 << 30;
        c[0][0] = c[0][1] = 0;
        key[0] = GCD[0] = cnt[0] = size[0] = 0;
    }
    Treap () {
        clear();
    }
    inline void pushup(int p) {
        size[p] = size[c[p][0]] + size[c[p][1]] + cnt[p];
        GCD[p] = __gcd(__gcd(GCD[c[p][0]] , GCD[c[p][1]]) , key[p]);
    }
    inline void rotate (int& x , int t) {
        int y = c[x][t];
        c[x][t] = c[y][!t] , c[y][!t] = x;
        pushup(x) , pushup(y) , x = y;
    }
    inline void newnode(int& p , T w) {
        p = nodecnt ++;
        key[p] = GCD[p] = w , cnt[p] = size[p] = 1;
        prior[p] = rand() << 15 | rand(), c[p][0] = c[p][1] = 0;
    }
    void insert(int& p , T w) {
        if (!p) {
            newnode(p , w);
            return;
        }
        if (key[p] == w)
            ++ cnt[p];
        else {
            int t = key[p] < w;
            insert(c[p][t] , w);
            if (prior[c[p][t]] > prior[p])
                rotate(p , t);
        }
        pushup(p);
    }
    void erase(int& p , T w) {
        if (!p) return;
        if (key[p] == w) {
            if (cnt[p] == 1) {
                if (!c[p][0] && !c[p][1])
                    p = 0;
                else {
                    rotate(p , prior[c[p][0]] < prior[c[p][1]]);
                    erase(p , w);
                }
            } else
                -- cnt[p];
        } else
            erase(c[p][key[p] < w] , w);
        pushup(p);
    }
    T getKth(int p , int K) {
        if (K <= size[c[p][0]])
            return getKth(c[p][0] , K);
        K -= size[c[p][0]] + cnt[p];
        if (K <= 0) return key[p];
        return getKth(c[p][1] , K);
    }
    T lower_bound(int p , T w) {
        if (!p) return 1 << 30;
        if (key[p] >= w)
            return min(lower_bound(c[p][0] , w) , key[p]);
        else
            return lower_bound(c[p][1] , w);
    }
    T range(int p , int l , int r) {
        if (!p || l > r) return 0;
        if (l <= key[p] && key[p] <= r) {
            int ans = key[p];
            if (l == -1 << 30) {
                ans = __gcd(ans , GCD[c[p][0]]);
                ans = __gcd(ans , range(c[p][1] , l , r));
            } else if (r == 1 << 30) {
                ans = __gcd(ans , GCD[c[p][1]]);
                ans = __gcd(ans , range(c[p][0] , l , r));
            } else {
                ans = __gcd(ans , range(c[p][0] , l , 1 << 30));
                ans = __gcd(ans , range(c[p][1] , -1 << 30 , r));
            }
            return ans;
        }
        if (r < key[p])
            return range(c[p][0] , l , r);
        else
            return range(c[p][1] , l , r);
    }
    void merge(int& p , int& q) {
        if (!p) return;
        merge(c[p][0] , q);
        merge(c[p][1] , q);
        insert(q , key[p]);
        erase(p , key[p]);
    }
};