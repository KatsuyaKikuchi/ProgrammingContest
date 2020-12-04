#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll index;
    pll x;
};

ll L[100005];
Data A[100005];
pll B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll S, N, M;
    cin >> S >> N >> M;
    REP(i, N) {
        cin >> L[i];
    }
    REP(i, M) {
        cin >> A[i].x.first >> A[i].x.second;
        A[i].index = i;
    }

    sort(A, A + M, [](Data a, Data b) { return a.x.first + a.x.second < b.x.first + b.x.second; });
    priority_queue<ll, vector<ll>, greater<ll>> q;
    REP(i, N - 1) {
        q.push(L[i + 1] - L[i] - 1);
    }

    ll s = 0;
    REP(i, M) {
        ll l = A[i].x.first + A[i].x.second;
        while (!q.empty() && l >= q.top()) {
            s += q.top();
            q.pop();
        }

        B[i].first = s + q.size() * l + std::min(L[0] - 1, A[i].x.first) + std::min(S - L[N - 1], A[i].x.second);
        B[i].second = A[i].index;
    }

    sort(B, B + M, [](pll a, pll b) { return a.second < b.second; });
    REP(i, M) {
        cout << B[i].first + N << endl;
    }
    return 0;
}