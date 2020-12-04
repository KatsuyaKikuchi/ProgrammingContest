#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, 2) {
        cin >> S[i];
    }

    ll index = 1;
    ll ans = 3;
    if (S[0][0] != S[1][0]) {
        index++;
        ans *= 2;
    }
    while (index < N) {
        if (S[0][index] == S[1][index]) {
            if (S[0][index - 1] == S[1][index - 1])
                ans *= 2;
        }
        else {
            if (S[0][index - 1] == S[1][index - 1])
                ans *= 2;
            else
                ans *= 3;
            index++;
        }
        ans %= MOD;
        index++;
    }
    cout << ans << endl;
    return 0;
}