#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<vector<ll>> values;

void dfs(int value, vector<ll> &v, ll len) {
    if (v.size() == len || value >= 10) {
        return;
    }
    dfs(value + 1, v, len);
    ll size = v.size();
    while (v.size() < len) {
        v.push_back(value);
        values.push_back(v);
        dfs(value + 1, v, len);
    }
    while (v.size() > size) {
        v.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, B;
    cin >> N >> B;
    ll len = 0;
    while (pow(10LL, len) <= N) {
        len++;
    }

    vector<ll> t;
    dfs(0, t, len);
    ll ans = 0;
    for (auto &value:values) {
        ll p = 1;
        vector<ll> v(10, 0);
        for (auto &val : value) {
            if (val < 0)
                continue;
            p *= val;
            v[val]++;
        }

        ll n = p + B;
        if (n > N)
            continue;
        while (n > 0) {
            v[n % 10]--;
            n /= 10;
        }

        bool e = true;
        REP(i, v.size()) {
            if (v[i] != 0)
                e = false;
        }
        if (e) {
            ans++;
#if false
            cout << p + B << endl;
            for (auto &val : value) {
                cout << val << " ";
            }
            cout << endl;
#endif
        }
    }
    cout << ans << endl;

    return 0;
}