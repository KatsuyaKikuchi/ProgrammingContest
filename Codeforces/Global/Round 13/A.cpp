#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    ll cnt = 0;
    REP(i, N) {
        cin >> A[i];
        cnt += A[i];
    }

    REP(_, Q) {
        ll t, x;
        cin >> t >> x;
        if (t == 1) {
            x--;
            if (A[x] == 1)
                cnt--;
            else
                cnt++;
            A[x] = 1 - A[x];
        }
        else {
            if (cnt >= x)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }

    return 0;
}