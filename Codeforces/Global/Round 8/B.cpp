#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;


string S = "codeforces";

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> v(10, 1);
    ll index = 0;
    while (true) {
        ll n = 1;
        REP(i, v.size()) {
            n *= v[i];
        }
        if (n >= N)
            break;
        v[index]++;
        index = (index + 1) % v.size();
    }

    reverse(v.begin(), v.end());
    REP(i, v.size()) {
        REP(j, v[i]) {
            cout << S[i];
        }
    }
    cout << endl;
    return 0;
}