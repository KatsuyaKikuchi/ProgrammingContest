#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve(ll N) {

    vector<ll> v;
    {
        ll p = 1;
        ll m = 0;
        while (true) {
            ll s = p + m;
            if (N < s)
                break;
            p *= 2LL;
            m++;
        }
        m--;
        p /= 2LL;

        ll n = N - (m + 1);
        for (ll i = m; i >= 0; --i) {
            if (n >= p - 1) {
                v.push_back(i + 1);
                n -= p - 1;
            }
            p /= 2LL;
        }
    }

    sort(v.begin(), v.end());
    ll r = 1, k = 1;
    ll row = 1;
    ll index = 0;
    while (v.size() > index) {
        cout << r << " " << k << endl;
        if (v[index] == row) {
            ll p = pow(2LL, (row - 1)) - 1;
            N -= p;
            //cout << p << ":" << N << endl;
            if (k == 1) {
                while (k < row) {
                    cout << r << " " << k + 1 << endl;
                    k++;
                }
            }
            else {
                while (k > 1) {
                    cout << r << " " << k - 1 << endl;
                    k--;
                }
            }
            index++;
        }
        row++;
        r++;
        if (k != 1)
            k++;
        N--;
    }

    while (N > 0) {
        cout << r << " " << k << endl;
        N--;
        r++;
        if (k != 1)
            k++;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(q, Q) {
        ll N;
        cin >> N;
        cout << "Case #" << q + 1 << ":" << endl;
        solve(N);
    }
    return 0;
}