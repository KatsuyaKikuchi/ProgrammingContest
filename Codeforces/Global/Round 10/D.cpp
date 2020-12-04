#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N;
    cin >> N;
    string S;
    cin >> S;

    ll ret = 0;
    ll index = -1;
    REP(i, N) {
        if (S[i] == 'R' && S[(i + 1)] == 'L') {
            index = i;
            break;
        }
    }

    if (index < 0) {
        if (S[0] == 'L') {
            S[0] = 'R';
        }
        else {
            S[1] = 'L';
        }
        index = 0;
        ret++;
    }


    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}