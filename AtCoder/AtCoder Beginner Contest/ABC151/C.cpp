#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool S[100005];
ll W[100005];

int main() {
    ll N, M;
    cin >> N >> M;
    memset(S, 0, sizeof(S));
    memset(W, 0, sizeof(W));
    REP(i, M) {
        ll p;
        string s;
        cin >> p >> s;
        p--;
        if (s == "AC")
            S[p] = true;
        else if (!S[p])
            W[p]++;
    }

    ll ac = 0, wa = 0;
    REP(i, N) {
        if (S[i]) {
            ac++;
            wa += W[i];
        }
    }

    cout << ac << " " << wa << endl;

    return 0;
}