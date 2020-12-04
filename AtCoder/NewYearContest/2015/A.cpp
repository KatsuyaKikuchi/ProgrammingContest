#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N;
    cin >> N;
    string S;
    for (ll i = 0; (1LL << i) <= N; ++i) {
        S.push_back((char) (((N >> i) & 1) + '0'));
    }

    ll M = S.length();
    REP(i, M) {
        if (S[i] != S[M - 1 - i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}