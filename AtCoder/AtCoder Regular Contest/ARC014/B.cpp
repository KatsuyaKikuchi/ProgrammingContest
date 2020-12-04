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

void solve(ll N) {
    FOR(i, N, 1) {
        REP(j, i) {
            if (S[i] == S[j]) {
                if (i % 2 == 1)
                    cout << "WIN" << endl;
                else
                    cout << "LOSE" << endl;
                return;
            }
        }
        if (S[i][0] != S[i - 1][S[i - 1].length() - 1]) {
            if (i % 2 == 1)
                cout << "WIN" << endl;
            else
                cout << "LOSE" << endl;
            return;
        }
    }
    cout << "DRAW" << endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i];
    }
    solve(N);
    return 0;
}