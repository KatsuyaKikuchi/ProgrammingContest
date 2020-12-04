#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

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
    sort(A.begin(), A.end());

    vector<ll> B(N, -1);

    ll index = 0;
    {
        ll t = 1;
        while (t < N) {
            B[t] = A[index++];
            t += 2;
        }
    }
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first > b.first; });
    REP(i, N) {
        if (B[i] > 0)
            continue;
        ll m = 0;
        if (i > 0)
            m = std::max(m, B[i - 1]);
        if (i < N - 1)
            m = std::max(B[i + 1], m);
        q.push(pll(m, i));
    }

    queue<ll> q0;
    FOR(i, N, index) {
        ll a = A[i];
        pll t = q.top();
        if (t.first >= a) {
            q0.push(A[i]);
            continue;
        }
        q.pop();
        B[t.second] = a;
    }

    REP(i, N) {
        if (B[i] < 0) {
            ll t = q0.front();
            q0.pop();
            B[i] = t;
        }
    }

    ll ans = 0;
    FOR(i, N - 1, 1) {
        if (B[i - 1] > B[i] && B[i] < B[i + 1])
            ans++;
    }
    cout << ans << endl;
    REP(i, N) {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}