#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

class Prime {
public:
    Prime(ll n) {
        mPrimeTbl.clear();
        vector<bool> u(n, false);
        for (ll i = 2; i <= n; ++i) {
            if (u[i])
                continue;
            mPrimeTbl.push_back(i);
            for (ll p = i; p <= n; p += i)
                u[p] = true;
        }
    }

    ~Prime() {}

    ll num() {
        return static_cast<ll>(mPrimeTbl.size());
    }

    ll get(ll index) {
        return mPrimeTbl[index];
    }

private:
    vector<ll> mPrimeTbl;
};


vector<ll> calc(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != 1 && i * i != n) {
                ret.push_back(n / i);
            }
        }
    }
    ret.push_back(n);
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    if (N == 2) {
        cout << 1 << endl;
        return 0;
    }

    vector<ll> ans;
    {
        vector<ll> v = calc(N - 1);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        REP(i, v.size()) {
            if (v[i] > 1)
                ans.push_back(v[i]);
        }
    }
    {
        vector<ll> v = calc(N);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        REP(i, v.size()) {
            if (v[i] == 1)
                continue;
            ll n = N;
            while (n % v[i] == 0)
                n /= v[i];
            if (n % v[i] == 1)
                ans.push_back(v[i]);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;

    return 0;
}