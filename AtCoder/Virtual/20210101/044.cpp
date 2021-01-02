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
    ll N;
    cin >> N;
    vector<ll> S;
    REP(i, N) {
        ll t;
        cin >> t;
        if (t == 0)
            t--;
        S.push_back(t);
    }
    S.push_back(-1);
    sort(S.begin(), S.end(), greater<ll>());
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll x;
        cin >> x;
        cout << S[x] + 1 << endl;
    }

    return 0;
}