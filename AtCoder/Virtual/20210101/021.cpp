#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<string> s;
    string str, t;

    getline(cin, str);

    stringstream ss{str};

    while (getline(ss, t, ' ')) {
        s.push_back(t);
    }
    ll N;
    cin >> N;
    REP(i, N) {
        string p;
        cin >> p;
        REP(j, s.size()) {
            if (s[j].length() != p.length())
                continue;
            bool e = true;
            REP(k, p.length()) {
                if (p[k] == '*')
                    continue;
                if (p[k] != s[j][k])
                    e = false;
            }
            if (e) {
                REP(k, s[j].length()) {
                    s[j][k] = '*';
                }
            }
        }
    }

    REP(i, s.size()) {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}