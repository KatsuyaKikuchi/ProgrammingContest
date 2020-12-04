#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    string s;
    string w;
};

ll N, K;
vector<Data> D;
vector<string> S;

bool check(vector<ll> &v) {
    REP(i, K) {
        auto &d = D[i];
        ll s = 0;
        REP(j, d.s.length()) {
            ll n = d.s[j] - '1';
            string t = "";
            REP(k, v[n]) {
                t.push_back(d.w[s + k]);
            }
            if (S[n].length() > 0 && S[n] != t)
                return false;
            S[n] = t;
            s += v[n];
        }
        if (s != d.w.length())
            return false;
    }
    return true;
}

bool dfs(vector<ll> &v) {
    if (v.size() == N) {
        S.assign(N, "");
        if (!check(v))
            return false;
        REP(i, S.size()) {
            cout << S[i] << endl;
        }
        return true;
    }

    REP(i, 3) {
        v.push_back(i + 1);
        if (dfs(v))
            return true;
        v.pop_back();
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, K) {
        Data d;
        cin >> d.s >> d.w;
        D.push_back(d);
    }

    vector<ll> v;
    dfs(v);
    return 0;
}