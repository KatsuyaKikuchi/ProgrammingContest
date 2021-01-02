#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int counter = 0;

int my_gcd(int a, int b) {
    if (b == 0)
        return a;
    counter++;
    return my_gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> v{1, 1};
    while (v.size() < 100) {
        ll n = v.size() - 1;
        v.push_back(v[n] + v[n - 1]);
    }
    REP(i, v.size() - 1) {
        counter = 0;
        my_gcd(v[i + 1], v[i]);
        if (counter == N) {
            cout << v[i + 1] << " " << v[i] << endl;
            break;
        }
    }
    return 0;
}