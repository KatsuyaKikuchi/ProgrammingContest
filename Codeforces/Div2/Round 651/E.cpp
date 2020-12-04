#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

template<typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    SegmentTree(F func, T id)
            : merge(func), identity(id) {}

    void init(ll n) {
        offset = 1;
        while (offset < n)
            offset <<= 1;
        node.assign(offset << 1, identity);
    }

    void build(const vector<T> &v) {
        int n = static_cast<int>(v.size());
        init(n);
        for (int i = 0; i < n; ++i) {
            node[offset + i] = v[i];
        }
        for (int i = offset - 1; i >= 0; --i) {
            node[i] = merge(node[(i << 1) | 0], node[(i << 1) | 1]);
        }
    }

    void set(int index, T value) {
        index += offset;
        node[index] = value;
        while (index >>= 1) {
            node[index] = merge(node[(index << 1) | 0], node[(index << 1) | 1]);
        }
    }

    //! [left, right]
    T get(int left, int right) {
        left += offset;
        right += offset + 1;

        T val = identity;
        while (left < right) {
            if (left & 1)
                val = merge(val, node[left++]);
            if (right & 1)
                val = merge(val, node[--right]);

            left >>= 1;
            right >>= 1;
        }
        return val;
    }

    T identity;
    F merge;
    vector<T> node;
    int offset;
};

bool check(string &s, string &t) {
    ll n = s.length();
    ll si = 0, ti = 0;
    REP(i, n) {
        if (s[i] == '1')
            si++;
        if (t[i] == '1')
            ti++;
    }
    return si == ti;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    if (!check(S, T)) {
        cout << -1 << endl;
        return 0;
    }

    SegmentTree<ll> seg0([](ll a, ll b) { return std::min(a, b); }, INF);
    SegmentTree<ll> seg1([](ll a, ll b) { return std::min(a, b); }, INF);
    seg0.init(N + 5);
    seg1.init(N + 5);
    REP(i, N) {
        if (S[i] == T[i])
            continue;
        if (S[i] == '1')
            seg0.set(i, i);
        else
            seg1.set(i, i);
    }

    ll ans = 0;
    while (true) {
        ll m0 = seg0.get(0, N);
        ll m1 = seg1.get(0, N);
        if (m0 == INF || m1 == INF)
            break;

        ans++;
        if (m0 < m1) {
            ll idx = 0;
            while (idx < INF) {
                ll p0 = seg0.get(idx, N);
                if (p0 == INF)
                    break;
                ll p1 = seg1.get(p0, N);
                if (p1 == INF)
                    break;
                idx = p1;
                seg0.set(p0, INF);
                seg1.set(p1, INF);
            }
        }
        else {
            ll idx = 0;
            while (idx < INF) {
                ll p0 = seg1.get(idx, N);
                if (p0 == INF)
                    break;
                ll p1 = seg0.get(p0, N);
                if (p1 == INF)
                    break;
                idx = p1;
                seg1.set(p0, INF);
                seg0.set(p1, INF);
            }
        }
    }

    cout << ans << endl;

    return 0;
}