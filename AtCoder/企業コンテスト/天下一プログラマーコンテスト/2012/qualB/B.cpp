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
    cin >> S;
    string s = S;
    string pre = "", suf = "";
    while (!s.empty() && s.back() == '_') {
        s.pop_back();
        suf.push_back('_');
    }
    reverse(s.begin(), s.end());
    while (!s.empty() && s.back() == '_') {
        s.pop_back();
        pre.push_back('_');
    }
    reverse(s.begin(), s.end());
    vector<string> v;
    bool camel = false, snake = false;
    v.push_back("");
    REP(i, s.length()) {
        if (s[i] == '_') {
            v.push_back("");
            snake = true;
            continue;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            v.push_back("");
            camel = true;
        }
        auto &b = v.back();
        b.push_back(s[i]);
        if (b[0] >= '0' && b[0] <= '9')
            snake = camel = true;
    }

    if (snake && camel) {
        cout << S << endl;
        return 0;
    }

    REP(i, v.size()) {
        if (v[i].length() == 0) {
            cout << S << endl;
            return 0;
        }
    }

    cout << pre;
    REP(i, v.size()) {
        string t = v[i];
        if (i > 0) {
            if (snake)
                t[0] = t[0] - 'a' + 'A';
            else
                t[0] = t[0] - 'A' + 'a';
            if (camel)
                t = '_' + t;
        }
        cout << t;
    }
    cout << suf << endl;
    return 0;
}