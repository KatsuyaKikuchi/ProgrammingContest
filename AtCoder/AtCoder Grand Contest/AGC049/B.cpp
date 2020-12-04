#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;

ll solve(string S, string T) {
    ll ret = 0;
    queue<ll> q;
    REP(i, N) {
        ll s = S[i] - '0', t = T[i] - '0';
        if (s == 0 && t == 0)
            continue;
        if (s == 0 && t == 1) {
            q.push(i);
            continue;
        }
        if (s == 1 && t == 0) {
            if (!q.empty()) {
                ll x = q.front();
                q.pop();
                ret += i - x;
                S[x] = T[x];
                S[i] = T[i];
            }
            else {
                q.push(i);
            }
            continue;
        }

        if (!q.empty()) {
            ll x = q.front();
            q.pop();
            ret += i - x;
            S[x] = T[x];
            S[i] = '0';
            q.push(i);
        }
    }

    if (!q.empty() || S != T) {
        return -1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    string S, T;
    cin >> S >> T;
    ll ans = solve(S, T);
    cout << ans << endl;
    return 0;
}