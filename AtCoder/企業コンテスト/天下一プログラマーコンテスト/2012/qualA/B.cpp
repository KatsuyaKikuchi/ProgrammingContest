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
    string S;
    getline(cin, S);
    ll N = S.length();
    vector<string> v;
    v.push_back("");
    REP(i, N) {
        if (S[i] == ' ') {
            v.push_back("");
            continue;
        }
        auto &b = v.back();
        b.push_back(S[i]);
    }

    REP(i, v.size()) {
        if (v[i].length() == 0)
            continue;
        if (i > 0)
            cout << ",";
        cout << v[i];
    }
    cout << endl;
    return 0;
}