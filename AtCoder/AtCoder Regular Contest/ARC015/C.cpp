#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

struct Vertex {
    vector<pll> to;
    vector<pll> from;
    string S;
};

struct Ans {
    string from, to;
    long long n;
};

struct Data {
    ll idx;
    long double val;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<Vertex> V;
    ll idx = 1;
    std::map<string, ll> m;
    REP(_, N) {
        string a, b;
        long long c;
        cin >> a >> c >> b;
        if (m[a] == 0) {
            m[a] = idx++;
            Vertex v;
            v.S = a;
            V.push_back(v);
        }
        if (m[b] == 0) {
            m[b] = idx++;
            Vertex v;
            v.S = b;
            V.push_back(v);
        }
        ll idx0 = m[a] - 1, idx1 = m[b] - 1;
        V[idx0].from.push_back(pll(idx1, c));
        V[idx1].to.push_back(pll(idx0, c));
    }

    Ans ans;
    ans.n = 0;
    ll M = V.size();
    REP(i, M) {
        vector<bool> seen(M, false);
        seen[i] = true;
        queue<Data> q;
        q.push(Data{i, 1.0});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            ll n = round(t.val);
            if (ans.n < n) {
                ans.n = n;
                ans.from = V[i].S;
                ans.to = V[t.idx].S;
            }
            for (auto &p: V[t.idx].to) {
                ll nxt = p.first;
                ll val = p.second;
                if (seen[nxt])
                    continue;
                seen[nxt] = true;
                long double v = t.val * val;
                q.push(Data{nxt, v});
            }
            for (auto &p: V[t.idx].from) {
                ll nxt = p.first;
                ll val = p.second;
                if (seen[nxt])
                    continue;
                seen[nxt] = true;
                long double v = t.val / val;
                q.push(Data{nxt, v});
            }
        }
    }
    cout << "1" << ans.to << "=" << ans.n << ans.from << endl;
    return 0;
}