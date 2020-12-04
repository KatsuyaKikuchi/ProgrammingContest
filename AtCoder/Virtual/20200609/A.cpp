#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool check(string &s, string &t) {
    if (s.length() != t.length())
        return false;
    REP(i, s.length()) {
        if (t[i] == '*')
            continue;
        if (s[i] != t[i])
            return false;
    }
    return true;
}

string solve(ll n) {
    string ret = "";
    REP(i, n) {
        ret.push_back('*');
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    getline(cin, S);

    vector<string> v;
    S.push_back(' ');
    string s = "";
    REP(i, S.length()) {
        if (S[i] == ' ') {
            v.push_back(s);
            s = "";
            continue;
        }
        s.push_back(S[i]);
    }

    ll N;
    cin >> N;
    REP(i, N) {
        string t;
        cin >> t;
        REP(j, v.size()) {
            if (check(v[j], t))
                v[j] = solve(v[j].length());
        }
    }

    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}