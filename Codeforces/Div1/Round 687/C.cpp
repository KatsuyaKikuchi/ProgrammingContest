#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll C[500005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> C[i];
    }
    sort(C, C + N, greater<ll>());
    queue<ll> A, B;
    REP(i, N) {
        if (C[i] < 0) {
            A.push(C[i]);
        }
        else
            B.push(C[i]);
    }
    ll score = 0;
    ll sum = 0;
    while (!B.empty()) {
        score += sum;
        sum += B.front();
        B.pop();
    }

    while (!A.empty()) {
        if (sum + A.front() < 0) {
            score += sum;
            A.front() += sum;
            break;
        }
        score += sum;
        sum += A.front();
        A.pop();
    }

    vector<vector<ll>> v(K + 1);
    ll p = 0;
    while (!A.empty()) {
        v[p].push_back(A.front());
        A.pop();
        p = (p + 1) % (K + 1);
    }

    REP(i, v.size()) {
        ll s = 0;
        REP(j, (ll) v[i].size() - 1) {
            s += v[i][j];
            score += s;
        }
    }

    cout << score << endl;
    return 0;
}