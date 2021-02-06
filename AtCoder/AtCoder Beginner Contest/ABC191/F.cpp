#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[2005];

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    ll mn = INF;
    REP(i, N) {
        mn = std::min(mn, A[i]);
    }
    std::unordered_map<ll, ll> mp;
    REP(i, N) {
        ll n = 1;
        while (n * n <= A[i] && n <= mn) {
            if (A[i] % n == 0) {
                {
                    auto it = mp.find(n);
                    if (it == mp.end()) {
                        mp[n] = A[i];
                    }
                    else {
                        it->second = gcd(it->second, A[i]);
                    }
                }
                ll x = A[i] / n;
                if (x <= mn) {
                    auto it = mp.find(x);
                    if (it == mp.end()) {
                        mp[x] = A[i];
                    }
                    else {
                        it->second = gcd(it->second, A[i]);
                    }
                }
            }
            n++;
        }
    }
    ll ans = 0;
    for (auto &p : mp) {
        if (p.first == p.second)
            ans++;
    }
    cout << ans << endl;
    return 0;
}