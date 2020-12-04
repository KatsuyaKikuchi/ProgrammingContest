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

ll solve() {
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    vector<Vertex> v(20);
    REP(i, N) {
        if (S[i] == T[i])
            continue;
        ll s = S[i] - 'a';
        ll t = T[i] - 'a';
        bool e = false;
        for (auto &n : v[s].node) {
            if (n == t) {
                e = true;
                break;
            }
        }
        if (!e)
            v[s].node.push_back(t);
    }

    ll ret = 0;
    REP(i, v.size()) {
        ret += v[i].node.size();
    }

    REP(i, v.size()) {
        for (auto &n : v[i].node) {
            vector<bool> U(20, false);
            queue<ll> q;
            REP(j, v[i].node.size()) {
                if (n == v[i].node[j])
                    continue;
                q.push(v[i].node[j]);
                U[v[i].node[j]] = true;
            }

            U[i] = true;
            bool e = false;
            while (!q.empty()) {
                ll t = q.front();
                q.pop();
                for (auto &nxt :v[t].node) {
                    if (U[nxt])
                        continue;
                    U[nxt] = true;
                    if (nxt == n) {
                        e = true;
                        break;
                    }
                    q.push(nxt);
                }

                if (e)
                    break;
            }

            if (e)
                ret--;
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}