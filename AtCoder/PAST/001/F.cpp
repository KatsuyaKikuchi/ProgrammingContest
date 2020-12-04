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
    string S;
    cin >> S;
    vector<string> v;
    string s = "";
    REP(i, S.length()) {
        s.push_back(S[i]);
        if (s.size() > 1 && (S[i] < 'a' || S[i] > 'z')) {
            s[0] = s[0] - ('A' - 'a');
            s[s.length() - 1] = s[s.length() - 1] - ('A' - 'a');
            v.push_back(s);
            s = "";
        }
    }

    sort(v.begin(), v.end());
    REP(i, v.size()) {
        v[i][0] = v[i][0] + ('A' - 'a');
        v[i][v[i].size() - 1] = v[i][v[i].size() - 1] + ('A' - 'a');
        cout << v[i];
    }
    cout << endl;
    return 0;
}