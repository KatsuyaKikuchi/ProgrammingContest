#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll sum = 0;
    REP(i, N) {
        if (i % 2 == 0)
            sum += A[i];
    }

    ll ret = sum;
    {
        ll dif = 0;
        ll s = 0;
        ll index = 0;
        while (index < N - 1) {
            dif += A[index + 1] - A[index];
            while (dif < 0) {
                dif -= A[s + 1] - A[s];
                s += 2;
            }
            ret = std::max(ret, sum + dif);
            index += 2;
        }
    }
    {
        ll dif = 0;
        ll s = 1;
        ll index = 1;
        while (index < N - 1) {
            dif += A[index] - A[index + 1];
            while (dif < 0) {
                dif -= A[s] - A[s + 1];
                s += 2;
            }
            ret = std::max(ret, sum + dif);
            index += 2;
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}