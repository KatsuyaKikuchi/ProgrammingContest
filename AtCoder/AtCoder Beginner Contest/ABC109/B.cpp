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

bool check(ll n) {
    FOR(i, n, 1) {
        if (S[i][0] != S[i - 1][S[i - 1].size() - 1])
            return false;

        REP(j, i) {
            if (S[i] == S[j])
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i];
    }

    if (check(N))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}