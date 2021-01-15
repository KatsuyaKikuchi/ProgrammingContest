#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll min = 0;
    ll max = 0;
    ll last = 0;
};

void solve() {
    ll N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<Data> P(N), B(N + 1);
    {
        ll s = 0;
        REP(i, N) {
            if (S[i] == '+')
                s++;
            else
                s--;
            ll mn = 0, mx = 0;
            if (i > 0) {
                mn = P[i - 1].min;
                mx = P[i - 1].max;
            }
            P[i].min = std::min(s, mn);
            P[i].max = std::max(s, mx);
            P[i].last = s;
        }
#if false
        REP(i, N) {
            cout << "(" << P[i].min << "," << P[i].max << ") ";
        }
        cout << endl;
#endif
    }
    {
        ll s = 0;
        for (ll i = N - 1; i >= 0; --i) {
            if (S[i] == '+') {
                B[i].min = std::min(0LL, B[i + 1].min + 1);
                B[i].max = std::max(0LL, B[i + 1].max + 1);
            }
            else {
                B[i].min = std::min(0LL, B[i + 1].min - 1);
                B[i].max = std::max(0LL, B[i + 1].max - 1);
            }
        }
#if false
        REP(i, N) {
            cout << "(" << B[i].min << "," << B[i].max << ") ";
        }
        cout << endl;
#endif
    }
    REP(i, M) {
        ll l, r;
        cin >> l >> r;
        l--;
        pll mm(0, 0);
        ll last = 0;
        if (l > 0) {
            mm = pll(P[l - 1].min, P[l - 1].max);
            last = P[l - 1].last;
        }
        auto d = B[r];
        mm.first = std::min(last + d.min, mm.first);
        mm.second = std::max(mm.second, last + d.max);

        ll ret = abs(mm.first) + abs(mm.second) + 1;
        //cout << mm.first << " " << mm.second << endl;
        cout << ret << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}