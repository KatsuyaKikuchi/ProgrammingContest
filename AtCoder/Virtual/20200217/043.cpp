#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct UnionFind {
    UnionFind(int n) {
        mRank.assign(n, 0);
        mParent.resize(n);
        mCount.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            mParent[i] = i;
        }
    }

    int find(int x) {
        if (x == mParent[x])
            return x;
        return mParent[x] = find(mParent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int count(int x) {
        return mCount[find(x)];
    }

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (mRank[x] < mRank[y]) {
            mParent[x] = y;
            mCount[y] += mCount[x];
        }
        else {
            mParent[y] = x;
            mCount[x] += mCount[y];
            if (mRank[x] == mRank[y])
                mRank[x]++;
        }
    }

    vector<int> mRank;
    vector<int> mParent;
    vector<int> mCount;
};

map<pll, ll> M;

int main() {
    ll N, K, L;
    cin >> N >> K >> L;
    UnionFind uf0(N), uf1(N);
    REP(i, K) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        uf0.unit(a, b);
    }
    REP(i, L) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        uf1.unit(a, b);
    }

    REP(i, N) {
        ll p0 = uf0.find(i);
        ll p1 = uf1.find(i);
        M[pll(p0, p1)]++;
    }

    REP(i, N) {
        ll p0 = uf0.find(i);
        ll p1 = uf1.find(i);
        cout << M[pll(p0, p1)] << " ";
    }
    cout << endl;

    return 0;
}