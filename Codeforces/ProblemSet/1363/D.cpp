#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll query(vector<ll> &v) {
    cout << "? ";
    cout << v.size();
    REP(i, v.size()) {
        cout << " " << v[i];
    }
    cout << endl;

    ll ret;
    cin >> ret;
    return ret;
}

string result(vector<ll> &v) {
    cout << "!";
    REP(i, v.size()) {
        cout << " " << v[i];
    }
    cout << endl;
    string ret;
    cin >> ret;
    return ret;
}

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> S;
    REP(i, K) {
        ll c;
        cin >> c;
        vector<ll> t(c);
        REP(j, c) {
            cin >> t[j];
        }
        S.push_back(t);
    }

    stack<ll> s0, s1;
    REP(i, N) {
        s0.push(i + 1);
    }
    vector<ll> A(N, -1);
    ll mx = 0;
    {
        vector<ll> q;
        REP(i, N) {
            q.push_back(i + 1);
        }
        mx = query(q);
    }

    while (s0.size() > 1) {
        vector<ll> q;
        ll num = s0.size();
        REP(_, num / 2) {
            ll t = s0.top();
            s0.pop();
            q.push_back(t);
            s1.push(t);
        }
        ll ret = query(q);
        if (mx == ret)
            swap(s0, s1);
        while (!s1.empty()) {
            s1.pop();
        }
    }

    vector<ll> ans(K);
    ll b = s0.top();
    REP(i, K) {
        bool exist = false;
        REP(j, S[i].size()) {
            if (S[i][j] == b)
                exist = true;
        }
        if (!exist) {
            ans[i] = mx;
            continue;
        }

        vector<bool> U(N, true);
        REP(j, S[i].size()) {
            U[S[i][j] - 1] = false;
        }
        vector<ll> q;
        REP(j, N) {
            if (U[j])
                q.push_back(j + 1);
        }
        ans[i] = query(q);
    }

    {
        string ret = result(ans);
        if (ret == "Correct")
            return;
    }
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