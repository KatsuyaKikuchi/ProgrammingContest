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
    string s;
    getline(std::cin, s);
    vector<string> S;
    string tmp = "";
    REP(i, s.length()) {
        if (s[i] == ' ') {
            S.push_back(tmp);
            tmp.clear();
            continue;
        }
        tmp.push_back(s[i]);
    }
    S.push_back(tmp);

    ll N;
    cin >> N;
    vector<string> T(N);
    REP(i, N) {
        cin >> T[i];
    }

    vector<string> ans;
    REP(i, S.size()) {
        REP(j, N) {
            if (S[i].size() != T[j].size())
                continue;
            bool dif = false;
            REP(n, S[i].length()) {
                if (S[i][n] != T[j][n] && T[j][n] != '*')
                    dif = true;
            }

            if (dif)
                continue;

            string t = "";
            REP(n, S[i].length()) {
                t.push_back('*');
            }
            ans.push_back(t);
            break;
        }

        if (ans.size() <= i)
            ans.push_back(S[i]);
    }

    REP(i, ans.size()) {
        cout << ans[i];
        if (i < ans.size() - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}