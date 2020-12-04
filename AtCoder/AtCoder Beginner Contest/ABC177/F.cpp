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
    vector<pll> node;
    vector<ll> lazy;

public:
    LazySegmentTree(vector<pll> v) {
        int sz = (int) v.size();
        n = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, INF);

        for (int i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (int i = sz + n - 1; i < node.size(); ++i)
            node[i] = pll(INF, -INF);
        for (int i = n - 2; i >= 0; i--) {
            ll l = abs(node[i * 2 + 1].first - node[i * 2 + 1].second);
            ll r = abs(node[i * 2 + 2].first - node[i * 2 + 2].second);
            if (l > r)
                node[i] = node[i * 2 + 2];
            else
                node[i * 2 + 1];
        }
    }

    // k 番目のノードについて遅延評価を行う
    void eval(int k, int l, int r) {

        if (lazy[k] != INF) {
            node[k].second = std::min(lazy[k], node[k].second);
            if (r - l > 1) {
                lazy[2 * k + 1] = std::min(lazy[k], lazy[2 * k + 1]);
                lazy[2 * k + 2] = std::min(lazy[2 * k + 2], lazy[k]);
            }
            lazy[k] = INF;
        }
    }

    void set(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;

        // k 番目のノードに対して遅延評価を行う
        eval(k, l, r);

        // 範囲外なら何もしない
        if (b <= l || r <= a)
            return;

        // 完全に被覆しているならば、遅延配列に値を入れた後に評価
        if (a <= l && r <= b) {
            lazy[k] = std::min(lazy[k], x);
            eval(k, l, r);
        }

            // そうでないならば、子ノードの値を再帰的に計算して、
            // 計算済みの値をもらってくる
        else {
            set(a, b, x, 2 * k + 1, l, (l + r) / 2);
            set(a, b, x, 2 * k + 2, (l + r) / 2, r);

            ll L = abs(node[k * 2 + 1].first - node[k * 2 + 1].second);
            ll R = abs(node[k * 2 + 2].first - node[k * 2 + 2].second);
            if (L > R)
                node[k] = node[k * 2 + 2];
            else
                node[k] = node[k * 2 + 1];

        }
    }

    pll get(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        if (b <= l || r <= a)
            return pll(INF, -INF);

        // 関数が呼び出されたら評価！
        eval(k, l, r);
        if (a <= l && r <= b)
            return node[k];
        pll vl = get(a, b, 2 * k + 1, l, (l + r) / 2);
        pll vr = get(a, b, 2 * k + 2, (l + r) / 2, r);

        if (abs(vl.first - vl.second) > abs(vr.first - vr.second))
            return vr;
        return vl;
    }
};

pll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;

    REP(i, H) {
        cin >> A[i].first >> A[i].second;
        A[i].first--;
        A[i].second--;
    }

    vector<pll> v;
    REP(i, W) {
        v.push_back(pll(i, i));
    }
    LazySegmentTree seg(v);

    REP(i, H) {
        ll mn = INF;
        pll p(INF, -INF);
        if (A[i].first > 0) {
            p = seg.get(0, A[i].first - 1);
            mn = std::min(mn, abs(p.first - p.second));
        }
        if (A[i].second < W - 1) {
            pll t = seg.get(A[i].second + 1, W - 1);
            mn = std::min(mn, abs(t.first - t.second));
        }

        if (mn >= INF)
            mn = -1;
        cout << mn << endl;

        seg.set(A[i].first, A[i].second, p.second);

    }


    return 0;
}