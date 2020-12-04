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
ll B[100005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> B[i];
        A[B[i] - 1] = i;
    }

    ll n = 0;
    REP(i, N) {
        if (B[i] - 1 == i)
            continue;
        n++;
        ll index = A[i];
        ll tmp = B[i];
        B[i] = B[index];
        B[index] = tmp;
        A[B[index] - 1] = index;
    }

    if ((N - n) % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}