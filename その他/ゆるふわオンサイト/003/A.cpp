#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[50005];
string T[50005];
string U[50005];

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    vector<string> v;
    map<string, ll> m;
    REP(i, A) {
        string s;
        cin >> s;
        v.push_back(s);
        m[s]++;
    }
    REP(j, B) {
        string s;
        cin >> s;
        m[s]++;
        if (m[s] <= 1)
            v.push_back(s);
    }
    ll ans = 0;
    REP(j, C) {
        string s;
        cin >> s;
        m[s]++;
        if (m[s] == 1)
            ans++;
    }

    cout << ans << endl;

    return 0;
}