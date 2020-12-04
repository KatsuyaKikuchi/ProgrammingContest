#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[55];

string solve(vector<string> &S) {
    ll N = S.size();
    vector<string> p, s, m;
    REP(i, N) {
        string pre = "";
        REP(j, S[i].size()) {
            if (S[i][j] == '*')
                break;
            pre.push_back(S[i][j]);
        }
        if (pre.length() > 0)
            p.push_back(pre);

        string suf = "";
        REP(j, S[i].size()) {
            if (S[i][S[i].size() - 1 - j] == '*')
                break;
            suf.push_back(S[i][S[i].size() - 1 - j]);
        }
        if (suf.size() > 0)
            s.push_back(suf);

        string mid = "";
        for (ll j = pre.size(); j < S[i].size() - suf.size(); ++j) {
            if (S[i][j] == '*')
                continue;
            mid.push_back(S[i][j]);
        }
        if (mid.size() > 0)
            m.push_back(mid);
    }

#if false
    cout << "pre" << endl;
    REP(i, p.size()) {
        cout << p[i] << endl;
    }
    cout << "mid" << endl;
    REP(i, m.size()) {
        cout << m[i] << endl;
    }
    cout << "suf" << endl;
    REP(i, s.size()) {
        cout << s[i] << endl;
    }
#endif

    string ret = "";
    {
        string pre = "";
        memset(U, 0, sizeof(U));
        ll index = 0;
        while (true) {
            char c = '#';
            REP(i, p.size()) {
                if (U[i])
                    continue;
                if (p[i].size() == index + 1)
                    U[i] = true;
                if (c == '#' || c == p[i][index]) {
                    c = p[i][index];
                    continue;
                }
                return "*";
            }
            if (c == '#')
                break;
            index++;
            pre.push_back(c);
        }
        ret += pre;
    }
    REP(i, m.size()) {
        ret += m[i];
    }
    {
        string suf = "";
        memset(U, 0, sizeof(U));
        ll index = 0;
        while (true) {
            char c = '#';
            REP(i, s.size()) {
                if (U[i])
                    continue;
                if (s[i].size() == index + 1)
                    U[i] = true;
                if (c == '#' || c == s[i][index]) {
                    c = s[i][index];
                    continue;
                }
                return "*";
            }
            if (c == '#')
                break;
            index++;
            suf.push_back(c);
        }
        reverse(suf.begin(), suf.end());
        ret += suf;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(q, Q) {
        ll N;
        cin >> N;
        vector<string> S(N);
        REP(i, N) {
            cin >> S[i];
        }
        cout << "Case #" << q + 1 << ": " << solve(S) << endl;
    }
    return 0;
}