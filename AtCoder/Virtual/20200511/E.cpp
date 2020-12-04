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

Vertex V[1005];
ll C[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string start, end;
    cin >> start >> end;
    ll N;
    cin >> N;
    vector<string> S;
    S.push_back(start);
    REP(i, N) {
        string s;
        cin >> s;
        S.push_back(s);
    }
    S.push_back(end);
    N = S.size();

    REP(i, N) {
        FOR(j, N, i + 1) {
            ll dif = 0;
            REP(n, S[i].length()) {
                if (S[i][n] == S[j][n])
                    continue;
                dif++;
            }

            if (dif <= 1) {
                V[i].node.push_back(j);
                V[j].node.push_back(i);
            }
        }
    }
    REP(i, N) {
        C[i] = INF;
    }
    C[0] = 0;
    queue<pll> q;
    q.push(pll(0, 0));
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ll cost = t.second + 1;
        REP(i, V[t.first].node.size()) {
            ll n = V[t.first].node[i];
            if (C[n] <= cost)
                continue;
            C[n] = cost;
            q.push(pll(n, cost));
        }
    }

    if (C[N - 1] == INF) {
        cout << -1 << endl;
        return 0;
    }
    vector<string> ans;
    ll index = N - 1;
    while (C[index] > 0) {
        ans.push_back(S[index]);
        REP(i, V[index].node.size()) {
            ll n = V[index].node[i];
            if (C[n] == C[index] - 1) {
                index = n;
                break;
            }
        }
    }
    ans.push_back(start);

    cout << ans.size() - 2 << endl;
    reverse(ans.begin(), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}