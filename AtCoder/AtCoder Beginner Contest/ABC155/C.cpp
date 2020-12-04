#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

map<string, ll> M;

int main() {
    ll N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }
    sort(S.begin(), S.end());
    ll max = 0;

    REP(i, N) {
        M[S[i]]++;
        max = std::max(max, M[S[i]]);
    }

    S.erase(unique(S.begin(), S.end()), S.end());
    REP(i, S.size()) {
        if (M[S[i]] == max)
            cout << S[i] << endl;
    }
    return 0;
}