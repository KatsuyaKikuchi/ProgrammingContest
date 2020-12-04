#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> v(N);
    ll s = N / 2;
    ll n = 1;
    v[s] = A[0];
    if (N % 2 == 0) {
        REP(i, N - 1) {
            if (i % 2 == 0)
                v[s - n] = A[i + 1];
            else {
                v[s + n] = A[i + 1];
                n++;
            }
        }
    }
    else {
        REP(i, N - 1) {
            if (i % 2 == 0)
                v[s + n] = A[i + 1];
            else {
                v[s - n] = A[i + 1];
                n++;
            }
        }
    }

    REP(i, N) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}