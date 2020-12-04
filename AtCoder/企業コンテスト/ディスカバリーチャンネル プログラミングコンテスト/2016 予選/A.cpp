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
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S = "DiscoPresentsDiscoveryChannelProgrammingContest2016";
    ll N;
    cin >> N;
    REP(i, S.length()) {
        cout << S[i];
        if ((i + 1) % N == 0 || i + 1 == S.length())
            cout << endl;
    }

    return 0;
}