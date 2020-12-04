#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[3];

bool check(vector<ll> v) {
    vector<ll> a0, a1, a2;
    REP(i, A[0]) {
        a0.push_back(v[i]);
    }
    REP(i, A[1]) {
        a1.push_back(v[i + a0.size()]);
    }
    REP(i, A[2]) {
        a2.push_back(v[i + a0.size() + a1.size()]);
    }

    REP(i, A[0] - 1) {
        if (a0[i + 1] < a0[i])
            return false;
    }
    REP(i, A[1] - 1) {
        if (a1[i + 1] < a1[i])
            return false;
    }
    REP(i, A[2] - 1) {
        if (a2[i + 1] < a2[i])
            return false;
    }

    REP(i, A[1]) {
        if (a1[i] < a0[i])
            return false;
    }
    REP(i, A[2]) {
        if (a2[i] < a1[i])
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N = 0;
    REP(i, 3) {
        cin >> A[i];
        N += A[i];
    }

    vector<ll> v(N);
    REP(i, N) {
        v[i] = i + 1;
    }

    ll ans = 0;
    do {
        if (check(v))
            ans++;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
    return 0;
}