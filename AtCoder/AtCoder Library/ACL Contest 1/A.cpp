#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
struct Data {
    pll p;
    ll index;
};
Data A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        cin >> A[i].p.first >> A[i].p.second;
        A[i].index = i;
    }

    atcoder::dsu uf(N);
    {
        sort(A, A + N, [](Data a, Data b) { return a.p.first < b.p.first; });
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q(
                [](pll a, pll b) { return a.first > b.first; });
        q.push(pll(INF, INF));
        REP(i, N) {
            pll mn(A[i].p.second, A[i].index);
            while (q.top().first < A[i].p.second) {
                pll t = q.top();
                q.pop();
                uf.merge(A[i].index, t.second);
                if (mn.first > t.first)
                    mn = t;
            }
            q.push(mn);
        }
    }
    {
        sort(A, A + N, [](Data a, Data b) { return a.p.first > b.p.first; });
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q(
                [](pll a, pll b) { return a.first < b.first; });
        q.push(pll(-1, -1));
        REP(i, N) {
            pll mx(A[i].p.second, A[i].index);
            while (q.top().first > A[i].p.second) {
                pll t = q.top();
                q.pop();
                uf.merge(A[i].index, t.second);
                if (mx.first < t.first)
                    mx = t;
            }
            q.push(mx);
        }
    }

    REP(i, N) {
        cout << uf.size(i) << endl;
    }
    return 0;
}