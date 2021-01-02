#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i];
    }

    map<string, bool> mp0;
    map<string, bool> mp1;

    REP(i, N) {
        if (S[i][0] == '!') {
            string s = "";
            FOR(j, S[i].length(), 1) {
                s.push_back(S[i][j]);
            }
            if (mp0[s]) {
                cout << s << endl;
                return 0;
            }
            mp1[s] = true;
        }
        else {
            if (mp1[S[i]]) {
                cout << S[i] << endl;
                return 0;
            }
            mp0[S[i]] = true;
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}