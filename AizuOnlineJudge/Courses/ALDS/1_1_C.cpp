#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

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
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    Prime p(100000);
    ll ans = 0;
    ll M = p.num();
    REP(i, N) {
        bool isPrime = true;
        for (int j = 0; j < M && p.get(j) * p.get(j) <= A[i]; j++)
        {
            if (A[i] % p.get(j) == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            ans++;
    }
    cout << ans << endl;
    return 0;
}