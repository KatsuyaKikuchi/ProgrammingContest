#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<pll> v;
    vector<ll> B(N, 0);
    REP(i, N) {
        B[A[i] - 1]++;
    }

    bool e = true;
    ll max = 1;
    REP(i, N) {
        if (B[i] > 2)
            e = false;
        if (i > 0 && B[i] > B[i - 1])
            e = false;

        if (B[i] > 0)
            max = std::max(max, i + 1);
    }

    if (e) {
        {
            vector<ll> a;
            REP(i, max) {
                a.push_back(A[i]);
            }
            sort(a.begin(), a.end());
            bool success = a[0] == 1;
            REP(i, a.size() - 1) {
                if (a[i] + 1 != a[i + 1])
                    success = false;
            }
            if (success)
                v.push_back(pll(max, N - max));
        }
        if (max != N - max) {
            vector<ll> a;
            REP(i, N - max) {
                a.push_back(A[i]);
            }
            sort(a.begin(), a.end());
            bool success = a[0] == 1;
            REP(i, a.size() - 1) {
                if (a[i] + 1 != a[i + 1])
                    success = false;
            }
            if (success)
                v.push_back(pll(N - max, max));
        }
    }

    cout << v.size() << endl;
    REP(i, v.size()) {
        cout << v[i].first << " " << v[i].second << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}