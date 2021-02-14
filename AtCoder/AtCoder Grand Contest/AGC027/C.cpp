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
    ll N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<vector<ll>> V(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    vector<pll> C(N, pll(0, 0));
    queue<ll> q;
    vector<bool> enable(N, true);
    REP(i, N) {
        for (auto &nxt:V[i]) {
            if (S[nxt] == 'A')
                C[i].first++;
            else
                C[i].second++;
        }
        if (C[i].first == 0 || C[i].second == 0) {
            q.push(i);
            enable[i] = false;
        }
    }

    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        for (auto &nxt : V[t]) {
            if (!enable[nxt])
                continue;
            if (S[t] == 'A')
                C[nxt].first--;
            else
                C[nxt].second--;
            if (C[nxt].first == 0 || C[nxt].second == 0) {
                q.push(nxt);
                enable[nxt] = false;
            }
        }
    }

    REP(i, N) {
        if (enable[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}