#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string calc(string s, string &t) {
    string ret = s;
    ll n = s.size();
    if (n != t.size()) {
        return ret;
    }

    REP(i, n) {
        if (s[i] == t[i] || t[i] == '*') {
            ret[i] = '*';
            continue;
        }
        return s;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    getline(cin, S);
    vector<string> v;
    string s = "";
    S.push_back(' ');
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
            v[j] = calc(v[j], t);
        }
    }

    cout << v[0];
    REP(i, v.size() - 1) {
        cout << " " << v[i + 1];
    }
    cout << endl;
    return 0;
}