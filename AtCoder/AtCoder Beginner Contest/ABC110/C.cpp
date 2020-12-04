#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char C[30];
bool U[30];

bool check(string S, string T) {
    ll N = S.length();
    REP(i, 27) {
        C[i] = (char) ('a' + i);
    }
    memset(U, 0, sizeof(U));
    REP(i, N) {
        char s = C[S[i] - 'a'];
        char t = T[i];
        if (s == t)
            continue;

        if (U[t - 'a'] || U[s - 'a'])
            return false;
        ll si = -1, ti = -1;
        REP(j, 27) {
            if (C[j] == s)
                si = j;
            if (C[j] == t)
                ti = j;
        }

        C[si] = t;
        C[ti] = s;
        U[t - 'a'] = true;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S, T;
    cin >> S >> T;
    if (check(S, T))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}