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
bool U[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> v(N, -1);
    memset(U, 0, sizeof(U));
    ll n = 0;
    REP(i, N) {
        if (n != A[i]) {
            v[i] = n;
            U[n] = true;
            n = A[i];
        }
    }
    U[n] = true;

    ll index = 0;
    REP(i, N) {
        while (U[index])
            index++;
        if (index < A[i]) {
            cout << -1 << endl;
            return 0;
        }
        if (v[i] < 0) {
            v[i] = index;
            U[index] = true;
        }
    }

    REP(i, N) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}