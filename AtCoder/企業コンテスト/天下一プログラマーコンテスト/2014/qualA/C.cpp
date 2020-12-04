#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[15];
bool U[15];

bool check(const string &s, const string &t) {
    ll N = s.length();
    REP(i, N) {
        if (s[i] == t[i])
            continue;
        if (s[i] == '*' || t[i] == '*')
            continue;
        return false;
    }
    return true;
}

string calc(const string &s, const string &t) {
    ll N = s.length();
    string ret = "";
    REP(i, N) {
        if (s[i] == t[i]) {
            ret.push_back(s[i]);
        }
        else if (s[i] == '*') {
            ret.push_back(t[i]);
        }
        else if (t[i] == '*') {
            ret.push_back(s[i]);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> S[i];
    }

    vector<string> v;
    REP(i, N) {
        if (U[i])
            continue;
        string s = S[i];
        U[i] = true;
        FOR(j, N, i + 1) {
            if (U[j])
                continue;
            if (!check(s, S[j]))
                continue;
            s = calc(s, S[j]);
            U[j] = true;
        }
        v.push_back(s);
    }

    cout << v.size() << endl;

    return 0;
}