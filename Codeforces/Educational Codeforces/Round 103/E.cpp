#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll parse(const string &s) {
    ll ret = 0;
    REP(i, s.size()) {
        ret *= 28LL;
        ll c = s[i] - 'a' + 1;
        if (s[i] == '_')
            c = 27;
        ret += c;
    }
    return ret;
}

bool match(const string &a, const string &b) {
    ll n = a.length();
    REP(i, n) {
        if (a[i] == '_' || b[i] == '_')
            continue;
        if (a[i] != b[i])
            return false;
    }
    return true;
}

struct Vertex {
    vector<ll> nxt;
    ll count = 0;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    std::map<ll, ll> mp;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
        ll p = parse(S[i]);
        mp[p] = i + 1;
    }

    bool check = true;
    vector<Vertex> V(N);
    ll b = pow(2LL, K);
    REP(i, M) {
        string s;
        ll n;
        cin >> s >> n;
        n--;
        check = (check && match(s, S[n]));
        REP(bit, b) {
            string tmp = s;
            REP(j, K) {
                if ((bit >> j) & 1)
                    tmp[j] = '_';
            }
            ll p = parse(tmp);
            auto it = mp.find(p);
            if (it == mp.end())
                continue;
            ll idx = it->second - 1;
            if (idx == n)
                continue;
            V[n].nxt.push_back(idx);
            V[idx].count++;
        }
    }
    vector<ll> ans;

    queue<ll> q;
    REP(i, N) {
        if (V[i].count == 0)
            q.push(i);
    }
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        ans.push_back(t + 1);
        REP(i, V[t].nxt.size()) {
            ll nxt = V[t].nxt[i];
            if (--V[nxt].count == 0)
                q.push(nxt);
        }
    }

    check = (check && ans.size() == N);
    if (!check) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    REP(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}