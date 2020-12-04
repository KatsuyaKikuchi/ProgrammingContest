#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll S;
    ll T;
    ll P;
};

Data A[200005];
ll S[200010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, W;
    cin >> N >> W;
    memset(S, 0, sizeof(S));
    REP(i, N) {
        cin >> A[i].S >> A[i].T >> A[i].P;
    }
    REP(i, N) {
        S[A[i].S] += A[i].P;
        S[A[i].T] -= A[i].P;
    }

    ll n = 200005;
    REP(i, n) {
        //cout << S[i] << " ";
        if (S[i] > W) {
            cout << "No" << endl;
            return 0;
        }
        S[i + 1] += S[i];
    }
    //cout << endl;
    cout << "Yes" << endl;
    return 0;
}