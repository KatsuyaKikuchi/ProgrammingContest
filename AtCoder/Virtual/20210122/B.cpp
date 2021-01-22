#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char win(char a, char b) {
    if (a == 'R') {
        if (b == 'P')
            return b;
        return a;
    }
    if (a == 'P') {
        if (b == 'S')
            return b;
        return a;
    }
    if (b == 'R')
        return b;
    return a;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    string S;
    cin >> N >> K >> S;
    S += S;
    REP(_, K) {
        string T = "";
        for (ll i = 0; i < S.length(); i += 2) {
            T.push_back(win(S[i], S[i + 1]));
        }
        S = T + T;
    }
    cout << S[0] << endl;
    return 0;
}