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
ll B[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
        A[i]--;
    }
    REP(i, N) {
        B[i] = INF;
    }
    ll index = 0;
    ll num = 0;
    while (true) {
        if (B[index] < INF) {
            //cout << index << endl;
            break;
        }
        B[index] = num++;
        index = A[index];
        K--;
        if (K == 0) {
            cout << index + 1 << endl;
            return 0;
        }
    }

    ll base = index;
    REP(i, N) {
        B[i] = INF;
    }
    num = 0;
    while (true) {
        B[index] = num++;
        index = A[index];
        if (index == base) {
            break;
        }
    }

    K %= num;
    REP(i, N) {
        if (K == B[i]) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}