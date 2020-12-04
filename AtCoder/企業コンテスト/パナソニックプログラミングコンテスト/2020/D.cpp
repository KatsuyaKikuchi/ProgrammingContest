#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<string> v;
ll N;

inline void dfs(vector<ll> &u) {
    if (u.size() == N - 1) {
        string s = "a";
        char c = 'b';
        REP(i, u.size()) {
            if (s.size() > u[i]) {
                s.push_back(s[u[i]]);
            }
            else {
                s.push_back(c);
                c = (char) (c + 1);
            }
        }
        v.push_back(s);
        return;
    }

    for (ll i = 0; i <= u.size() + 1; ++i) {
        bool exist = false;
        for (ll j = u.size() - 1; j > i; --j) {
            if (u[j] == i) {
                exist = true;
                break;
            }
        }
        if (exist)
            continue;
        u.push_back(i);
        dfs(u);
        u.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;

    v.clear();
    vector<ll> u;
    dfs(u);

    sort(v.begin(), v.end());
    //cout << v.size() << endl;
    v.erase(unique(v.begin(), v.end()), v.end());
    //cout << v.size() << endl;
    REP(i, v.size()) {
        cout << v[i] << endl;
    }
    return 0;
}