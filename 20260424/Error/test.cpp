#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 1 << 20; // 2^20 = 1048576 > 10^6

long long qpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

vector<long long> fac, invfac;
void init_fac(int n) {
    fac.resize(n + 1);
    invfac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    invfac[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
}

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

// FWHT 对二项式数组的每个位置做变换
// arr[i][j] 表示异或和为 i，选了 j 个的方案数
void fwht_2d(vector<vector<long long>>& a, bool invert) {
    int n = a.size(); // 必须是2的幂
    int k = a[0].size() - 1; // 选择的个数上限
    
    for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                for (int t = 0; t <= k; t++) {
                    long long u = a[i + j][t];
                    long long v = a[i + j + len][t];
                    a[i + j][t] = (u + v) % MOD;
                    a[i + j + len][t] = (u - v + MOD) % MOD;
                }
            }
        }
    }
    
    if (invert) {
        long long inv_n = qpow(n, MOD - 2);
        for (int i = 0; i < n; i++) {
            for (int t = 0; t <= k; t++) {
                a[i][t] = a[i][t] * inv_n % MOD;
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }
    
    // 统计频率
    vector<int> cnt(max_val + 1, 0);
    for (int x : a) cnt[x]++;
    
    // 确定多项式的维度大小（2的幂）
    int size = 1;
    while (size <= max_val) size <<= 1;
    
    // 初始化结果多项式的频域表示
    // result[mask][j] 在频域
    vector<vector<long long>> result(size, vector<long long>(k + 1, 0));
    result[0][0] = 1; // 初始：异或和为0，选0个的方案数为1
    fwht_2d(result, false); // 变换到频域
    
    // 对每个值进行卷积
    for (int v = 0; v <= max_val; v++) {
        if (cnt[v] == 0) continue;
        
        // 构造当前值的多项式
        vector<vector<long long>> poly(size, vector<long long>(k + 1, 0));
        
        int max_select = min(k, cnt[v]);
        for (int j = 0; j <= max_select; j++) {
            int xor_val = (j % 2 == 0) ? 0 : v;
            poly[xor_val][j] = C(cnt[v], j);
        }
        
        // 变换到频域
        fwht_2d(poly, false);
        
        // 频域相乘（需要做二维卷积：异或维度和个数维度）
        // 因为是异或卷积在第一个维度，个数维度是普通卷积
        for (int i = 0; i < size; i++) {
            vector<long long> temp(k + 1, 0);
            for (int j1 = 0; j1 <= k; j1++) {
                if (result[i][j1] == 0) continue;
                for (int j2 = 0; j2 <= k - j1; j2++) {
                    if (poly[i][j2] == 0) continue;
                    temp[j1 + j2] = (temp[j1 + j2] + result[i][j1] * poly[i][j2]) % MOD;
                }
            }
            result[i] = temp;
        }
    }
    
    // 逆变换
    fwht_2d(result, true);
    
    cout << result[0][k] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init_fac(1000000);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}