#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<string> ans;
ll S[300][300];

void push(string &s, ll len) {
    ans.push_back(s);
    REP(i, len) {
        REP(j, i) {
            if (s[i] == s[j]) {
                S[i][j]++;
                S[j][i]++;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll p = pow(2LL, N);

    memset(S, 0, sizeof(S));
    REP(i, p) {
        S[i][i] = INF;
    }
    while (true) {
        vector<ll> v;
        while (v.size() < p / 2) {
            pll x(-1, INF);
            REP(i, p) {
                ll sum = 0;
                REP(j, v.size()) {
                    sum += S[i][v[j]];
                }
                if (x.second > sum)
                    x = pll(i, sum);
            }
            v.push_back(x.first);
        }
        string s = "";
        REP(i, p) {
            s.push_back('A');
        }
        REP(i, v.size()) {
            s[v[i]] = 'B';
        }
        push(s, p);
        bool e = true;
        REP(i, p) {
            FOR(j, p, i + 1) {
                if (S[i][j] != S[0][1]) {
                    e = false;
                }
            }
            if (!e)
                break;
        }
        if (e)
            break;
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}