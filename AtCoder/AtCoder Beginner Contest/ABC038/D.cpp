#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

class SegmentTree {
public:
    SegmentTree(int n) {
        ll cnt = 1;
        while (cnt < n)
            cnt <<= 1;
        node.resize(2 * cnt - 1);
        REP(i, 2 * cnt - 1) {
            node[i] = 0;
        }
        mN = cnt - 1;
    }

    ~SegmentTree() {
        node.resize(0);
    }

    //! 0-index get
    ll get(int left, int right, int l = 0, int r = -1, int index = 0) {
        if (r == -1)
            r = mN;

        if (r < left || right < l)
            return 0;
        if (left <= l && r <= right)
            return node[index];
        return std::max(get(left, right, l, (l + r) / 2, 2 * index + 1),
                        get(left, right, (l + r) / 2 + 1, r, 2 * index + 2));
    }

    //! 0-index set
    void set(int index, ll value) {
        node[mN + index] = value;
        //! update
        int par = (mN + index);
        while (par > 0) {
            par = (par - 1) / 2;
            node[par] = std::max(node[2 * par + 1], node[2 * par + 2]);
        }
    }

private:
    ll mN;
    vector<ll> node;
    const ll inf = (ll) 1e15;
};

pll A[100005];

int main() {
    ll N;
    cin >> N;
    vector<ll> h;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        h.push_back(A[i].second);
    }
    sort(A, A + N, [](pll a, pll b) { return a.first == b.first ? a.second > b.second : a.first < b.first; });
    sort(h.begin(), h.end());
    h.erase(unique(h.begin(), h.end()), h.end());

    SegmentTree seg(h.size() + 5);
    REP(i, N) {
        ll index = lower_bound(h.begin(), h.end(), A[i].second) - h.begin();
        ll max = seg.get(0, index - 1);
        seg.set(index, max + 1);
    }

    cout << seg.get(0, h.size() + 1) << endl;
    return 0;
}