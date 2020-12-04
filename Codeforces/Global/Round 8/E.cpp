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
    vector<ll> to;
    vector<ll> from;
    ll cntF = 0;
    ll cntT = 0;
    ll index;
};

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

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<pll> A(M);
    vector<Vertex> V(N);
    vector<bool> U(N, false);
    REP(i, M) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    REP(i, A.size()) {
        ll f = A[i].first - 1, t = A[i].second - 1;
        V[f].to.push_back(t);
        V[t].from.push_back(f);
    }
    vector<ll> ans;
#if false
    for (int i = N - 1; i >= 0; --i) {
        V[i].index = i;
        if ((V[i].to.size() - V[i].cntT > 1 && V[i].from.size() - V[i].cntF > 1)) {
            ans.push_back(i);
            for (auto &n : V[i].from) {
                V[n].cntT++;
            }
            for (auto &n : V[i].to) {
                V[n].cntF++;
            }
            U[i] = true;
        }
    }

    for (int i = N - 1; i >= 0; --i) {
        if (U[i])
            continue;
        V[i].index = i;
        if ((V[i].to.size() - V[i].cntT > 1 && V[i].from.size() - V[i].cntF > 0) ||
            (V[i].to.size() - V[i].cntT > 0 && V[i].from.size() - V[i].cntF > 1)) {
            ans.push_back(i);
            for (auto &n : V[i].from) {
                V[n].cntT++;
            }
            for (auto &n : V[i].to) {
                V[n].cntF++;
            }
            U[i] = true;
        }
    }


    for (int i = N - 1; i >= 0; --i) {
        if (U[i])
            continue;
        if ((V[i].to.size() - V[i].cntT > 0 && V[i].from.size() - V[i].cntF > 0)) {
            ans.push_back(i);
            for (auto &n : V[i].from) {
                V[n].cntT++;
            }
            for (auto &n : V[i].to) {
                V[n].cntF++;
            }
            U[i] = true;
        }
    }
#endif
    REP(i,N)
    {
        if(V[i].to.size()==2)
    }

#if false
    SegmentTree<pll> seg([](pll a, pll b) {
        if (a.first < b.first)
            return b;
        return a;
    }, pll(-1, -1));
    seg.init(N + 5);
    REP(i, N) {
        seg.set(i, pll(V[i].to.size() + V[i].from.size(), i));
    }

    REP(_, N) {
        pll mn = seg.get(0, N);
        if (mn.first <= 1)
            break;
        ans.push_back(mn.second);
        for (auto &n : V[mn.second].from) {
            pll t = seg.get(n, n);
            seg.set(n, pll(t.first - 1, n));
        }
        for (auto &n : V[mn.second].to) {
            pll t = seg.get(n, n);
            seg.set(n, pll(t.first - 1, n));
        }
        seg.set(mn.second, pll(-1, -1));
    }
#endif

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        solve();
    }
    return 0;
}