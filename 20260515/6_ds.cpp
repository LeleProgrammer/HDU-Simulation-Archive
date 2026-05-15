#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int modpow(int a, int e) {
    int res = 1;
    while (e) {
        if (e & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        e >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int M = 0;
    vector<int> cntA(MAXN, 0), cntB(MAXN, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cntA[a[i]]++;
        M = max(M, a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        cntB[b[i]]++;
        M = max(M, b[i]);
    }
    
    vector<long long> SA(MAXN, 0), SB(MAXN, 0);
    for (int i = 1; i <= M; i++) {
        SA[i] = 1LL * cntA[i] * i % MOD;
        SB[i] = 1LL * cntB[i] * i % MOD;
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 2 * i; j <= M; j += i) {
            SA[i] = (SA[i] + SA[j]) % MOD;
            SB[i] = (SB[i] + SB[j]) % MOD;
        }
    }
    
    vector<int> f(MAXN, 0);
    for (int i = 1; i <= M; i++) {
        f[i] = modpow(1LL * i * i % MOD, MOD - 2);  // 1/i?
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 2 * i; j <= M; j += i) {
            f[j] = (f[j] - f[i] + MOD) % MOD;
        }
    }
    
    long long ans = 0;
    for (int d = 1; d <= M; d++) {
        ans = (ans + 1LL * f[d] * SA[d] % MOD * SB[d]) % MOD;
    }
    
    cout << ans << "\n";
    return 0;
}