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
pll A[30];

ll solve(vector<pll> v) {
    vector<ll> t;
    REP(i, N) {
        t.push_back(v[i].first);
    }
    sort(t.begin(), t.end());
    ll num = 0;
    REP(i, N) {
        ll p = -1;
        FOR(j, N, i) {
            if (t[i] == v[j].first && (j - i) % 2 == v[j].second) {
                p = j;
                break;
            }
        }
        if (p < 0)
            return INF;
        num += p - i;
        for (ll j = p - 1; j >= i; --j) {
            v[j + 1].first = v[j].first;
            v[j + 1].second = (v[j].second + 1) % 2;
        }
    }
    return num;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> A[i].first;
    }
    REP(i, N) {
        cin >> A[i].second;
    }

    ll ans = INF;
    REP(i, pow(2LL, N)) {
        //! bitで裏表を表す
        //! 1の数が帰趨ならばむり
        ll n = 0;
        REP(j, N) {
            if (((i >> j) & 1) == 1)
                n++;
        }
        if (n % 2 == 1)
            continue;

        vector<pll> v;
        REP(j, N) {
            if (((i >> j) & 1) == 1)
                v.push_back(pll(A[j].second, 1));
            else
                v.push_back(pll(A[j].first, 0));
        }

        ll p = solve(v);
        ans = std::min(ans, p);
    }

    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}