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
    vector<ll> egde;
};

Vertex V[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        string s;
        cin >> s;
        REP(j, s.length()) {
            if (s[j] == '1')
                V[i].egde.push_back(j);
        }
    }
    vector<ll> S(N, 0);
    REP(i, N) {
        vector<ll> seen(N, false);
        queue<ll> q;
        q.push(i);
        seen[i] = true;
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            S[t]++;
            REP(j, V[t].egde.size()) {
                ll nxt = V[t].egde[j];
                if (seen[nxt])
                    continue;
                seen[nxt] = true;
                q.push(nxt);
            }
        }
    }
    double ans = 0;
    REP(i, N) {
        ans += 1.0 / S[i];
    }
    cout << OF64 << ans << endl;
    return 0;
}