#include <iostream>
#include <cstring>

using namespace std;

const int MaxK = 202;
const int MaxN = 50002 * 2;

int n, k;
long long dp[2][MaxK];
int nums[MaxN], size[MaxN];
int prefix[MaxN];
int Ten[MaxN * 3];

void print() {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n + n; j++) {
            cout << dp[j][i] << " ";
        }
        cout << "\n";
    }
}

int cal(int x) {
	if(!x) return 1;
	int ret = 0;
	while(x) x /= 10, ++ret;
	return ret;
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    long long ans;
    while (cin >> n >> k) {
    	int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            size[i] = cal(nums[i]);
            size[i + n] = size[i];
            sum += size[i];
            nums[i] %= k;
            nums[i + n] = nums[i];
        }
        memset(dp, 0, sizeof dp);
        memset(prefix, 0, sizeof prefix);
        prefix[0] = nums[0];
        Ten[0] = 1;
        Ten[1] = 10 % k;
        for (int i = 1; i <= sum; i++) {
        	Ten[i + 1] = Ten[i] * 10 % k;
        }
        for (int i = 1; i < n + n; i++) {
            prefix[i] = (prefix[i - 1] * Ten[size[i]] % k + nums[i]) % k;
        }
        dp[0][nums[0]] = 1;
        ans = dp[0][0];
        for (int i = 1; i < n; i++) {
        	int t = i & 1, s = t ^ 1;
        	memset(dp[t], 0, sizeof(dp[t]));
            for (int j = 0; j < k; j++) {
                dp[t][(j * Ten[size[i]] % k + nums[i]) % k] += dp[s][j];
            }
            dp[t][nums[i]]++;
            ans += dp[t][0];
            /*
			for (int j = 0; j < k; j++) {
                printf("%lld ", dp[t][j]);
            }
            puts("");
            */
        }
        for (int i = n; i < n + n; i++) {
        	int t = i & 1, s = t ^ 1;
        	memset(dp[t], 0, sizeof(dp[t]));
            if (i == n) {
				dp[s][prefix[n - 1]]--;
				if(dp[s][prefix[n - 1]] < 0) for(;;);
			}
            else {
                int tmp = (prefix[i - 1] - prefix[i - n - 1] * Ten[sum] % k + k) % k;
               // printf("	%d %d\n", i, tmp);
                dp[s][tmp]--;
                //if(dp[s][tmp] < 0) for(;;);
            }
            for (int j = 0; j < k; j++) {
                dp[t][(j * Ten[size[i - n]] + nums[i - n]) % k] += dp[s][j];
            }
            //printf("%lld ", ans);
            ans += dp[t][0];
        }
       // print();
        cout << ans << "\n";
    }
	return 0;
}

/*
5 7
9 6 4 2 8

5 7
6 4 2 8 9

5 7
4 2 8 9 6

5 7
2 8 9 6 4

5 7
8 9 6 4 2
*/
