#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    REP(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    vector<Vertex> V(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first < b.first; });
    REP(i, N) {
       // cout << A[i] << " " << V[i].node.size() - 1 << endl;
        q.push(pll(A[i], V[i].node.size() - 1));
    }


    REP(_, N - 1) {
        cout << sum << " ";
        while (!q.empty()) {
            pll t = q.top();
            if (t.second > 0)
                break;
            q.pop();
        }
        if (!q.empty()) {
            pll t = q.top();
            q.pop();
            sum += t.first;
            t.second--;
            q.push(t);
        }
    }
    cout << endl;
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