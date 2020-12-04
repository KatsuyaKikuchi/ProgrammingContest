#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<ll> V[20005];

void solve(ll A, ll B, ll C) {
    ll ans = INF;
    vector<ll> v(3);
    REP(i, 20000) {
        ll b = i + 1;
        ll m = abs(b - B);
        if (m > ans)
            continue;
        ll c = b * std::max(1LL, C / b);
        if (abs(C - c) > abs(C - (c + b)))
            c += b;
        m += abs(C - c);
        ll a = b;
        REP(j, V[b].size()) {
            if (abs(A - a) > abs(A - V[b][j])) {
                a = V[b][j];
            }
        }
        m += abs(A - a);
        if (m > ans)
            continue;
        if (m < ans) {
            ans = m;
            v[0] = a;
            v[1] = b;
            v[2] = c;
        }
    }

    cout << ans << endl;
    REP(i, 3) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ll Q;
    cin >> Q;
    FOR(i, 20001, 1) {
        REP(j, i + 1) {
            if (i % (j + 1) == 0) {
                V[i].push_back(j + 1);
            }
        }
    }
    REP(_, Q) {
        ll A, B, C;
        cin >> A >> B >> C;
        solve(A, B, C);
    }
    return 0;
}