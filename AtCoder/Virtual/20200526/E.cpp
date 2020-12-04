#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<ll> C[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    ll N = S.length();
    ll M = T.length();
    REP(i, N) {
        C[S[i] - 'a'].push_back(i);
    }

    REP(i, 30) {
        C[i].push_back(INF);
    }

    ll x = 0;
    ll index = -1;
    REP(i, M) {
        auto &v = C[T[i] - 'a'];
        if (v.size() == 1) {
            cout << -1 << endl;
            return 0;
        }
        ll nxt = upper_bound(v.begin(), v.end(), index) - v.begin();
        if (v[nxt] == INF || v[nxt] < index) {
            x++;
            nxt = 0;
        }
        index = v[nxt];
    }

    cout << x * N + index + 1 << endl;

    return 0;
}