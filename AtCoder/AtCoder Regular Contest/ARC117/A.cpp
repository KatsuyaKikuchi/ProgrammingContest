#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B;
    cin >> B >> A;
    vector<ll> E;
    ll MAX = 100000000 - 1;
    {
        ll s = 0;
        REP(i, A - 1) {
            E.push_back(-(i + 1));
            s += i + 1;
        }
        E.push_back(-(MAX - s));
    }
    {
        ll s = 0;
        REP(i, B - 1) {
            E.push_back(i + 1);
            s += i + 1;
        }
        E.push_back(MAX - s);
    }
    REP(i, E.size()) {
        cout << E[i] << " ";
    }
    cout << endl;

    return 0;
}