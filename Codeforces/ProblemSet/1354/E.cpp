#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

Vertex V[5005];
ll C[5005];
bool dp[5005][5005];
ll A[5005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    REP(i, N) {
        C[i] = INF;
    }

    vector<pll> v;
    vector<ll> s;
    REP(i, N) {
        if (C[i] < INF)
            continue;
        C[i] = 0;
        queue<pll> q;
        q.push(pll(i, 0));
        pll p(0, 0);
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            if (t.second % 2 == 0)
                p.first++;
            else
                p.second++;
            ll cost = t.second + 1;
            for (auto &n:V[t.first].node) {
                if (C[n] < INF) {
                    if (C[n] % 2 != cost % 2) {
                        cout << "NO" << endl;
                        return 0;
                    }
                    continue;
                }
                C[n] = cost;
                q.push(pll(n, cost));
            }
        }
        v.push_back(p);
        s.push_back(i);
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    REP(i, v.size()) {
        REP(j, Y + 1) {
            if (!dp[i][j])
                continue;
            if (j + v[i].first <= Y)
                dp[i + 1][j + v[i].first] = true;
            if (j + v[i].second <= Y)
                dp[i + 1][j + v[i].second] = true;
        }
    }

    if (!dp[v.size()][Y]) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    memset(A, 0, sizeof(A));
    for (ll i = v.size() - 1; i >= 0; --i) {
        ll c = 0;
        if (Y - v[i].second >= 0 && dp[i][Y - v[i].second]) {
            c = 1;
            Y -= v[i].second;
        }
        else {
            c = 0;
            Y -= v[i].first;
        }

        queue<ll> q;
        q.push(s[i]);
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            if (C[t] % 2 == c)
                A[t] = 2;
            else {
                if (X-- > 0)
                    A[t] = 1;
                else
                    A[t] = 3;
            }

            for (auto &n : V[t].node) {
                if (A[n] > 0)
                    continue;
                q.push(n);
            }
        }
    }

    REP(i, N) {
        cout << A[i];
    }
    cout << endl;

    return 0;
}