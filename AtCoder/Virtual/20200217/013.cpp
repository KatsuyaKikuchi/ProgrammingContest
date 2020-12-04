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
    string S, T;
    cin >> S >> T;
    string s = "";
    vector<string> v;
    REP(i, S.length()) {
        if (i + T.length() > S.length())
            break;
        string t = s;
        bool exist = true;
        REP(j, T.size()) {
            if (S[i + j] != '?' && S[i + j] != T[j])
                exist = false;
            t.push_back(T[j]);
        }

        if (exist) {
            FOR(j, S.length(), i + T.length()) {
                t.push_back(S[j]);
                if (t[j] == '?')
                    t[j] = 'a';
            }
            v.push_back(t);
        }
        s.push_back(S[i]);
        if (s[i] == '?')
            s[i] = 'a';
    }

    sort(v.begin(), v.end());

    if (v.size() == 0)
        cout << "UNRESTORABLE" << endl;
    else
        cout << v[0] << endl;
    return 0;
}