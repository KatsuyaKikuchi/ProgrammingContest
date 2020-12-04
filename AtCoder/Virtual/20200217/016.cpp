#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll W[55];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> W[i];
    }
    vector<ll> v;
    REP(i, N) {
        ll index = -1;
        REP(j, v.size()) {
            if (v[j] < W[i])
                continue;
            if (index >= 0 && v[j] > v[index])
                continue;
            index = j;
        }
        if (index < 0)
            v.push_back(W[i]);
        else
            v[index] = W[i];
    }

    cout << v.size() << endl;
    return 0;
}