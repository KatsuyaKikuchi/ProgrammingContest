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

ll getHash(ll n) {
    while (n >= 10) {
        ll m = 0;
        while (n > 0) {
            m += (n % 10);
            n /= 10;
        }
        n = m;
    }
    return n;
}

bool U[15];

int main() {
    ll K, N;
    cin >> K >> N;
    Prime prime(N + 1);

    ll ans = 0;
    ll max = 0;
    for (int i = 0; i < prime.num(); ++i) {
        ll p = prime.get(i);
        if (p < K)
            continue;
        if (p > N)
            break;
        memset(U, 0, sizeof(U));
        ll m = 0;
        for (int j = i; j < prime.num(); ++j) {
            ll h = getHash(prime.get(j));
            if (prime.get(j) > N)
                break;
            if (!U[h]) {
                m++;
                U[h] = true;
                continue;
            }
            break;
        }
        if (m >= max) {
            max = m;
            ans = p;
        }
    }
    cout << ans << endl;
    return 0;
}