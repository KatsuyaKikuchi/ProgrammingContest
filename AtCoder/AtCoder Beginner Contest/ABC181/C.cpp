#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[10005];

bool check(pll a, pll b, pll c) {
    if (a.first == b.first || a.first == c.first) {
        if (a.first == b.first && a.first == c.first)
            return true;
        return false;
    }

    ll p = (c.first - a.first) * (b.second - a.second);
    ll q = (b.first - a.first) * (c.second - a.second);
    return p == q;
}

bool solve(ll N) {
    REP(i, N) {
        REP(j, N) {
            if (i == j)
                continue;
            REP(k, N) {
                if (i == k || j == k)
                    continue;
                if (check(A[i], A[j], A[k]))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    if (solve(N))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}