#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];
string S[2] = {"matsu", "prd"};

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    ll xr = 0;
    ll s = 0;
    ll t = 0;
    REP(i, N) {
        xr ^= (A[i].second);
        t += A[i].first;
        s += A[i].second;
    }

    ll ans;
    if (s >= t) {
        if (xr == 0)
            ans = 1;
        else
            ans = 0;
    }
    else {
        if ((s + t) % 2 == 0)
            ans = 1;
        else
            ans = 0;
    }
    cout << S[ans] << endl;
    return 0;
}