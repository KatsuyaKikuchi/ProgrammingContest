#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int) v.size();
        n = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);

        for (int i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] += lazy[k];
            if (r - l > 1) {
                lazy[2 * k + 1] += lazy[k] / 2;
                lazy[2 * k + 2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        eval(k, l, r);
        if (b <= l || r <= a)
            return;
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }

    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        eval(k, l, r);
        if (b <= l || r <= a)
            return 0;
        if (a <= l && r <= b)
            return node[k];
        ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};

struct Vertex {
    vector<ll> node;
};

Vertex V[200005];
ll S[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
#if true
    memset(S, 0, sizeof(S));
    S[0] = 1;
    for (ll i = 1; i < N; ++i) {
        S[i] += S[i - 1] + 1;
        for (auto &n:V[i].node) {
            if (n < i)
                S[i]--;
        }
    }
#endif
#if false

    REP(i, N) {
        cout << S[i] << " ";
    }
    cout << endl;
#endif
    for (ll i = N - 2; i >= 0; --i) {
        S[i] += S[i + 1];
    }
#if false
    REP(i, N) {
        cout << S[i] << " ";
    }
    cout << endl;
#endif

    vector<ll> tmp(N + 5, 0);

    LazySegmentTree seg(tmp);
    ll ans = 0;
    REP(i, N) {
        ll t = seg.getsum(i, N);
       // cout << t << endl;
        ans -= t;
        ans += S[i];
        vector<ll> v;
        for (auto &n :V[i].node) {
            if (n > i)
                v.push_back(n);
        }

        //sort(v.begin(), v.end());
        seg.add(i, N, 1);
        REP(j, v.size()) {
            seg.add(v[j], N, -1);
        }
#if false
        if (v.size() > 0) {
            REP(j, v.size()) {
                if (j == 0)
                    t += (v[j] - (i + 1));
                else
                    t -= N - v[j];
            }
        }
        else {
            t += N - (i + 1);
        }
#else
#endif
    }
    cout << ans << endl;

    return 0;
}