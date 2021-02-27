#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll calc(const vector<ll> &v) {
    ll ret = 0;
    REP(i, 10) {
        ret += i * pow(10LL, v[i]);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    string S, T;
    cin >> S >> T;
    vector<ll> C(10, K);
    vector<ll> a(10, 0), b(10, 0);
    REP(i, S.length()) {
        if (S[i] == '#')
            continue;
        ll t = S[i] - '0';
        a[t]++;
        C[t]--;
    }
    REP(i, T.length()) {
        if (T[i] == '#')
            continue;
        ll t = T[i] - '0';
        b[t]++;
        C[t]--;
    }

    C[0] = 0;
    double ans = 0;
    REP(i, 10) {
        REP(j, 10) {
            //! 高橋 i , 青木j
            if (i == j) {
                if (C[i] <= 1)
                    continue;
            }
            else {
                if (C[i] <= 0 || C[j] <= 0)
                    continue;
            }

            a[i]++;
            b[j]++;
            ll x = calc(a);
            ll y = calc(b);
            if (x > y) {
                double ap = C[i] / (9.0 * K - 8);
                C[i]--;
                double bp = C[j] / (9.0 * K - 9);
                C[i]++;
                ans += ap * bp;
            }
            a[i]--;
            b[j]--;
        }
    }
    cout << OF64 << ans << endl;
    return 0;
}