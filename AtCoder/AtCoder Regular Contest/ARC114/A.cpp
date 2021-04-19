#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    Prime p(52);
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = INF;
    ll M = p.num();
    REP(bit, pow(2LL, M)) {
        ll cnt = 0;
        REP(i, N) {
            REP(j, M) {
                if (((bit >> j) & 1) == 0)
                    continue;

                if (A[i] % p.get(j) == 0) {
                    cnt++;
                    break;
                }
            }
        }

        if (cnt != N)
            continue;

        ll t = 1;
        REP(i, M) {
            if ((bit >> i) & 1)
                t *= p.get(i);
        }
        ans = std::min(ans, t);
    }
    cout << ans << endl;

    return 0;
}