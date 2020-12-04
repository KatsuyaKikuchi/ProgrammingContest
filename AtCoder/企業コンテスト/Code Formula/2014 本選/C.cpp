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
    vector<string> v;
    ll N = S.length();
    REP(i, N) {
        if (S[i] != '@')
            continue;
        string s = "";

        FOR(j, N, i + 1) {
            if (S[j] == '@' || S[j] == ' ')
                break;
            s.push_back(S[j]);
        }
        if (s.length() > 0)
            v.push_back(s);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    REP(i, v.size()) {
        cout << v[i] << endl;
    }
    return 0;
}