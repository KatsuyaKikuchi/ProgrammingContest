#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i];
    }

    FOR(i, N, 1) {
        bool e = false;
        REP(j, i) {
            if (S[j] == S[i])
                e = true;
        }
        if (S[i - 1][S[i - 1].length() - 1] != S[i][0] || e) {
            if (i % 2 == 1)
                cout << "WIN" << endl;
            else
                cout << "LOSE" << endl;
            return 0;
        }
    }
    cout << "DRAW" << endl;
    return 0;
}