#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Query {
    ll i;
    ll j;
    ll x;
};

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> T(N);
    ll target = 0;
    REP(i, N) {
        cin >> A[i];
        target += A[i];
        T[i] = A[i];
    }

    if (target % N != 0) {
        cout << -1 << endl;
        return;
    }
    target /= N;

    //cout << target << endl;
    vector<Query> q;
    FOR(i, N, 1) {
        if (A[i] % (i + 1) != 0) {
            ll d = i + 1 - A[i] % (i + 1);
            Query t{0, i, d};
            q.push_back(t);
            A[0] -= d;
            A[i] += d;
        }

        {
            ll d = A[i] / (i + 1);
            Query t{i, 0, d};
            q.push_back(t);
            A[i] -= d * (i + 1);
            A[0] += d * (i + 1);
        }
    }

    FOR(i, N, 1) {
        ll d = target;
        Query t{0, i, d};
        q.push_back(t);
        A[i] += d;
        A[0] -= d;
    }

    cout << q.size() << endl;
    REP(i, q.size()) {
        cout << q[i].i + 1 << " " << q[i].j + 1 << " " << q[i].x << endl;
    }

#if false
    REP(i, q.size()) {
        ll p = q[i].i + 1;
        ll x = q[i].x;
        T[q[i].i] -= x * p;
        T[q[i].j] += x * p;
    }
    REP(i, N) {
        cout << T[i] << " ";
    }
    cout << endl;
#endif
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