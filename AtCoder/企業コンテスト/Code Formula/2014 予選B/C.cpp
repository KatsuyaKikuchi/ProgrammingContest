#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[30];

bool calc(vector<pll> &v, string s, string t) {
    REP(i, v.size()) {
        swap(s[v[i].first], s[v[i].second]);
    }

    REP(i, s.size()) {
        if (t[i] != s[i])
            return false;
    }
    return true;
}

bool U[10];

bool check(string S, string T) {
    ll N = S.length();
    vector<ll> v;
    REP(i, N) {
        if (S[i] == T[i])
            continue;
        v.push_back(i);
    }

    if (v.size() > 6)
        return false;
    vector<pll> t;
    REP(i, v.size()) {
        FOR(j, v.size(), i + 1) {
            t.push_back(pll(i, j));
        }
    }

    REP(i, N) {
        C[S[i] - 'a']++;
    }
    U[1] = U[3] = true;
    REP(i, 27) {
        if (C[i] > 1)
            U[0] = U[2] = true;
    }

    string ts = "", tt = "";
    REP(i, v.size()) {
        ts.push_back(S[v[i]]);
        tt.push_back(T[v[i]]);
    }

    vector<pll> m;
    if (calc(m, ts, tt) && U[m.size()]) {
        return true;
    }
    REP(i, t.size()) {
        m.push_back(t[i]);
        if (calc(m, ts, tt) && U[m.size()]) {
            return true;
        }
        REP(j, t.size()) {
            m.push_back(t[j]);
            if (calc(m, ts, tt) && U[m.size()]) {
                return true;
            }
            REP(k, t.size()) {
                m.push_back(t[k]);
                if (calc(m, ts, tt) && U[m.size()]) {
                    return true;
                }
                m.pop_back();
            }
            m.pop_back();
        }
        m.pop_back();
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    if (check(S, T))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}