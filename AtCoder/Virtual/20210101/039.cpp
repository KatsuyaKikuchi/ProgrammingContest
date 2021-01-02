#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char get(char a, char b) {
    if (a == 'R') {
        if (b == 'P')
            return b;
        return a;
    }
    if (a == 'S') {
        if (b == 'R')
            return b;
        return a;
    }
    if (b == 'S')
        return b;
    return a;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    string T = S + S;
    REP(i, K) {
        string t = "";
        for (ll i = 0; i < T.size(); i += 2) {
            t.push_back(get(T[i], T[i + 1]));
        }
        T = t + t;
    }
    cout << T[0] << endl;
    return 0;
}