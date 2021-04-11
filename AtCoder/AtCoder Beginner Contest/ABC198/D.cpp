#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[3];
ll N[3];

ll num(string &s, vector<ll> &v, const vector<char> &c) {
    ll ret = 0;
    map<char, ll> mp;
    REP(i, c.size()) {
        mp[c[i]] = v[i];
    }
    REP(i, s.length()) {
        ret = ret * 10LL + mp[s[i]];
        if (ret == 0)
            return -1;
    }
    return ret;
}

bool dfs(vector<ll> &v, const vector<char> &c, vector<bool> &used, ll index = 0) {
    if (index == c.size()) {
        vector<ll> t(3);
        REP(i, 3) {
            t[i] = num(S[i], v, c);
            if (t[i] < 0)
                return false;
        }
        bool e = (t[0] + t[1] == t[2]);
        if (e) {
            cout << t[0] << endl;
            cout << t[1] << endl;
            cout << t[2] << endl;
        }
        return e;
    }

    bool enable = false;
    REP(i, 10) {
        if (used[i])
            continue;
        used[i] = true;
        v[index] = i;
        enable = enable || dfs(v, c, used, index + 1);
        used[i] = false;
        if (enable)
            break;
    }
    return enable;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 3) {
        cin >> S[i];
        N[i] = S[i].length();
    }
    vector<char> v;
    REP(i, 3) {
        REP(j, N[i]) {
            v.push_back(S[i][j]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    if (v.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    vector<ll> t(v.size(), 0);
    vector<bool> u(10, false);
    ll b = dfs(t, v, u);
    if (!b) {
        cout << "UNSOLVABLE" << endl;
    }
    return 0;
}