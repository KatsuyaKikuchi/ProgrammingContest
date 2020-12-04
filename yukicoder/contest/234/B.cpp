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

int main() {
    ll N;
    cin >> N;
    ll S = 0;
    REP(i, N) {
        cin >> A[i];
        S += A[i] * (N - 1);
    }
    S /= (N - 1);
    vector<ll> v;
    REP(i, N) {
        v.push_back(S - (A[i] * (N - 1)));
    }

    REP(i, N) {
        cout << v[i];
        if (i < N - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}