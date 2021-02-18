#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll so = 0, se = 0;
    for (ll i = N - 1; i >= 0; --i) {
        if (i % 2 == 0 && A[i] > 0)
            se += A[i];
        else if (i % 2 == 1 && A[i] > 0)
            so += A[i];
    }

    if (so == 0 && se == 0) {
        ll mi = 0;
        REP(i, N) {
            if (A[mi] < A[i])
                mi = i;
        }
        cout << A[mi] << endl;
        cout << N - 1 << endl;
        for (ll i = N; i > mi + 1; --i) {
            cout << i << endl;
        }
        REP(_, mi) {
            cout << 1 << endl;
        }
        return 0;
    }

    vector<ll> v;
    ll ans = std::max(so, se);
    if (so > se) {
        A.erase(A.begin());
        v.push_back(1);
    }
    while (A.size() > 1) {
        if (A[0] < 0) {
            v.push_back(1);
            v.push_back(1);
            A.erase(A.begin());
            A.erase(A.begin());
        }
        else if (A.size() > 2 && A[2] < 0) {
            v.push_back(3);
            A.erase(A.begin() + 2);
            if (A.size() > 2)
                A.erase(A.begin() + 2);
        }
        else {
            v.push_back(2);
            A.erase(A.begin() + 1);
            if (A.size() > 1)
                A.erase(A.begin() + 1);
        }
    }
    cout << ans << endl;
    cout << v.size() << endl;
    REP(i, v.size()) {
        cout << v[i] << endl;
    }
    return 0;
}