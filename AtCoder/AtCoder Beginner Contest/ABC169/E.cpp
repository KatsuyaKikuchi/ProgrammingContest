#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> t;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        t.push_back(A[i].first);
        t.push_back(A[i].second);
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    vector<ll> v(t.size() + 5, 0);
    REP(i, N) {
        ll s = lower_bound(t.begin(), t.end(), A[i].first) - t.begin();
        ll e = lower_bound(t.begin(), t.end(), A[i].second) - t.begin();
        v[s]++;
        v[e + 1]--;
    }

    REP(i, v.size() - 1) {
        v[i + 1] += v[i];
    }
    sort(A, A + N, [](pll a, pll b) { return a.second < b.second; });

    if (N % 2 == 1) {
        ll n = (N + 1) / 2;
        ll num = 0;
        ll s = INF;
        ll e = 0;
        ll index = 0;
        REP(i, t.size()) {
            //cout << v[i] << " ";
            ll x = t[i];
            while (x > A[index].second) {
                num++;
                index++;
            }

            if (num < n && num + v[i] >= n) {
                s = std::min(s, x);
                e = std::max(e, x);
            }
        }
        //cout << endl;
        // cout << s << " " << e << endl;
        cout << e - s + 1 << endl;
    }
    else {
        ll n = N / 2;
        ll num = 0;
        pll a(INF, 0), b(INF, 0);
        ll index = 0;
        REP(i, t.size()) {
            ll x = t[i];
            while (x > A[index].second) {
                num++;
                index++;
            }

            if (num < n && num + v[i] >= n) {
                a.first = std::min(a.first, x);
                a.second = std::max(a.second, x);
            }
            if (num < n + 1 && num + v[i] >= n + 1) {
                b.first = std::min(b.first, x);
                b.second = std::max(b.second, x);
            }
        }
        //cout << a.first << " " << a.second << endl;
        //cout << b.first << " " << b.second << endl;
        ll s = a.first + b.first;
        ll e = a.second + b.second;
        cout << e - s + 1 << endl;
    }
    return 0;
}