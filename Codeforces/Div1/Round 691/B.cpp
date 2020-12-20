#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
pll A[105];

int dp0[105][10005];
int dp1[105][10005];


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

    {
#if true
        cin >> N;
        REP(i, N) {
            cin >> A[i].first >> A[i].second;
        }
#else
        TestCase tst;
        N = 100;
        REP(i, N) {
            A[i].first = 100;//tst.get(1, 100);
            A[i].second = 100;//tst.get(0, A[i].first);
        }
#endif

        memset(dp0, -1, sizeof(dp0));
        dp0[0][0] = 0;
        REP(i, N) {
            memset(dp1, -1, sizeof(dp1));
            REP(j, i + 1) {
                REP(k, 10001) {
                    dp1[j][k] = std::max(dp1[j][k], dp0[j][k]);
                    if (k + A[i].first <= 10000 && dp0[j][k] >= 0) {
                        dp1[j + 1][k + A[i].first] = std::min((int) (k + A[i].first),
                                                              std::max(dp1[j + 1][k + A[i].first],
                                                                       dp0[j][k] + A[i].second));
                    }
                }
            }

            swap(dp0, dp1);
        }

        ll s = 0;
        REP(i, N) {
            s += A[i].second;
        }
        REP(i, N) {
            double ans = 0;
            REP(j, 10001) {
                if (dp0[i + 1][j] < 0)
                    continue;
                double t = std::min((double) (j), dp0[i + 1][j] + (s - dp0[i + 1][j]) / 2.0);
                ans = std::max(ans, t);
            }
            cout << OF64 << ans << " ";
        }
        cout << endl;
    }
    return 0;
}