#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll E[300005];
ll W[300005];

int main() {
    ll N;
    string S;
    cin >> N >> S;
    memset(E, 0, sizeof(E));
    memset(W, 0, sizeof(W));
    REP(i, N) {
        E[i + 1] += E[i];
        W[i + 1] += W[i];
        if (S[i] == 'E')
            E[i + 1]++;
        else
            W[i + 1]++;
    }

    ll min = INF;
    REP(i, N) {
        min = std::min(min, W[i] + (E[N] - E[i + 1]));
    }
    cout << min << endl;

    return 0;
}