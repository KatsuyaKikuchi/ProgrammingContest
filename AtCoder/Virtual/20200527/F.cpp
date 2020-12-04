#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll L[200005];
ll R[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    memset(R, 0, sizeof(R));
    for (ll i = N - 1; i >= 0; --i) {
        R[i] = std::max(R[i], R[i + 1]);
        if (S[i] == 'o') {
            ll x = i + C + 1;
            if (x <= N)
                R[i] = std::max(R[i], R[x] + 1);
            else
                R[i] = 1;
        }
    }

    vector<ll> v;
    ll index = 0;
    ll n = 0;
    while (index < N) {
        if (S[index] == 'x') {
            index++;
            continue;
        }
        if (n + R[index + 1] < K)
            v.push_back(index + 1);
        n++;
        index += C + 1;
    }
    REP(i, v.size()) {
        cout << v[i] << endl;
    }
    return 0;
}