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

void solve(string &s) {
    if (s.length() == 1) {
        cout << "YES" << endl;
        REP(i, 26) {
            cout << (char) (i + 'a');
        }
        cout << endl;
        return;
    }
    vector<Vertex> v(26);
    REP(i, s.length() - 1) {
        ll p = s[i] - 'a';
        ll n = s[i + 1] - 'a';
        bool exist = false;
        REP(j, v[p].node.size()) {
            if (v[p].node[j] == n)
                exist = true;
        }
        if (exist)
            continue;

        if (v[p].node.size() == 2 || v[n].node.size() == 2) {
            cout << "NO" << endl;
            return;
        }
        v[p].node.push_back(n);
        v[n].node.push_back(p);
    }
    ll si = -1;
    REP(i, 26) {
        if (v[i].node.size() == 1)
            si = i;
    }
    if (si < 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<bool> u(26, false);
    queue<ll> q;
    q.push(si);
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        cout << (char) (t + 'a');
        u[t] = true;
        REP(i, v[t].node.size()) {
            ll n = v[t].node[i];
            if (u[n])
                continue;
            q.push(n);
        }
    }
    REP(i, 26) {
        if (u[i])
            continue;
        cout << (char) (i + 'a');
    }
    cout << endl;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        string S;
        cin >> S;
        solve(S);
    }
    return 0;
}