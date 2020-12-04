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
ll C[30];

bool check(string s) {
    memset(C, 0, sizeof(C));
    REP(i, s.length()) {
        C[s[i] - 'a']++;
    }

    string t = "indeednow";
    REP(i, t.length()) {
        C[t[i] - 'a']--;
    }

    REP(i, 27) {
        if (C[i] != 0)
            return false;
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

    REP(i, N) {
        if (check(S[i]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}