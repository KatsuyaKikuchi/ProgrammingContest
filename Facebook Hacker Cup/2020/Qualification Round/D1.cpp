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

ll solve(ifstream& rs) {
    ll N, M;
    rs >> N >> M;
    vector<ll> A(N);
    REP(i, N) {
        rs >> A[i];
    }

    SegmentTree<ll> seg([](ll a, ll b) { return std::min(a, b); }, INF);
    seg.init(N + 5);
    seg.set(0, 0);
    FOR(i, N - 1, 1) {
        ll s = std::max(0LL, i - M);
        ll mn = seg.get(s, i - 1);
        if (mn == INF) {
            return -1;
        }
        if (A[i] == 0) {
            continue;
        }
        seg.set(i, mn + A[i]);
    }

    ll ret = seg.get(std::max(0LL, N - 1 - M), N - 2);
    if (ret == INF)
        return -1;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2020/Qualification Round/D1.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2020/Qualification Round/D1_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    rs >> Q;
    REP(i, Q) {
        ws << "Case #" << i + 1 << ": ";
        ws << solve(rs) << endl;
    }
    return 0;
}