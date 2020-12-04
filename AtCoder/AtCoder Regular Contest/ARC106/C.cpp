#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll takahashi(vector<pll> v) {
    sort(v.begin(), v.end(), [](pll a, pll b) { return a.second < b.second; });
    ll ret = 0;
    ll r = -1;
    REP(i, v.size()) {
        if (v[i].first > r) {
            ret++;
            r = v[i].second;
        }
    }

    return ret;
}

ll aoki(vector<pll> v) {
    sort(v.begin(), v.end(), [](pll a, pll b) { return a.first < b.first; });
    ll ret = 0;
    ll r = -1;
    REP(i, v.size()) {
        if (r < v[i].first) {
            ret++;
            r = v[i].second;
        }
    }
    return ret;
}


struct TestCase {
    TestCase() {
        std::random_device rnd;
        mMt = std::mt19937(rnd());
    }

    int get(int low, int height) {
        if (low > height)
            swap(low, height);
        int d = height - low;
        if (d == 0)
            return low;
        std::uniform_int_distribution<> rand(0, d);
        return low + rand(mMt);
    }

    std::mt19937 mMt;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    //    while (true)
    {
        ll N, M;
        cin >> N >> M;
        //TestCase tst = TestCase();
        // N = tst.get(1, 20);
        // M = tst.get(0, std::max(N - 2, 0LL));

        if (N - abs(M) <= 1) {
            //   cout << -1 << endl;
            //  return 0;
        }
        vector<pll> ans;
        if (M == 0) {
            //! aoki == takahashi
            REP(i, N) {
                ans.push_back(pll(2 * i + 1, 2 * i + 2));
            }
        }
        else if (M < 0) {
            cout << -1 << endl;
            return 0;
        }
        else {
            //! aoki < takahashi
            ll p = N - 1;
            ll q = p - M;
            if (q <= 0) {
                cout << -1 << endl;
                return 0;
            }
            ll x = q - 1;
            p -= x;
            q -= x;

            ll inf = (ll) 1e7;
            {
                ans.push_back(pll(1, inf));
                ll n = 2;
                while (p > 0) {
                    ans.push_back(pll(n, n + 1));
                    n += 2;
                    p--;
                }
            }
            {
                ll n = inf + 1;
                while (x > 0) {
                    ans.push_back(pll(n, n + 1));
                    n += 2;
                    x--;
                }
            }
        }
#if false
        ll m = takahashi(ans) - aoki(ans);
        if (m != M || ans.size() != N) {
            cout << "yabai!" << endl;
            cout << N << " " << M << endl;
            cout << "--------" << endl;
            REP(i, ans.size()) {
                cout << ans[i].first << " " << ans[i].second << endl;
            }
            break;
        }
#endif

        REP(i, ans.size()) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }

    return 0;
}