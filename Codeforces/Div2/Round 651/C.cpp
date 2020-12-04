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

bool solve(Prime &prime) {
    ll N;
    cin >> N;
    if (N == 1)
        return false;
    if (N % 2 == 1)
        return true;
    if (N == 2)
        return true;
    ll p = 2;
    while (p <= N) {
        if (p == N)
            return false;
        p *= 2LL;
    }

    ll t = N / 2;
    ll n = 2;
    while (n * n <= t) {
        if (t % n == 0)
            return true;
        n++;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    Prime p(100000);
    REP(_, T) {
        if (solve(p))
            cout << "Ashishgup" << endl;
        else
            cout << "FastestFinger" << endl;
    }
    return 0;
}