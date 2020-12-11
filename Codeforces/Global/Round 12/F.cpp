#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> T(N, 0);
    REP(i, N) {
        cin >> A[i];
        A[i]--;
        T[A[i]]++;
    }

    REP(i, N) {
        if ((N + 1) / 2 < A[i])
            return -1;
    }

    vector<pll> v;
    ll f = 0;
    REP(i, N) {
        if (i == N - 1 || A[i] == A[i + 1]) {
            v.push_back(pll(f, i));
            f = i + 1;
        }
    }

    ll ret = v.size() - 1;
    vector<ll> v0;
    vector<pll> v1;
    REP(i, N) {
        if (v[i].first == v[i].second)
            v0.push_back(v[i].first);
        else
            v1.push_back(v[i]);
    }
    sort(v.begin(), v.end());

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}