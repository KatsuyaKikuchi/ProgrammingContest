#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    vector<pll> e;
    vector<pll> v;
    if (N % 2 == 1) {
        v.push_back(pll(N, 0));
        N--;
    }

    REP(i, N / 2) {
        v.push_back(pll(i + 1, N - i));
    }

    REP(i, v.size() - 1) {
        FOR(j, v.size(), i + 1) {
            ll a = v[i].first;
            ll b = v[i].second;
            ll c = v[j].first;
            ll d = v[j].second;
            if (a > 0) {
                if (c > 0)
                    e.push_back(pll(a, c));
                if (d > 0)
                    e.push_back(pll(a, d));
            }
            if (b > 0) {
                if (c > 0)
                    e.push_back(pll(b, c));
                if (d > 0)
                    e.push_back(pll(b, d));
            }
        }
    }

    cout << e.size() << endl;
    REP(i, e.size()) {
        cout << e[i].first << " " << e[i].second << endl;
    }
    return 0;
}