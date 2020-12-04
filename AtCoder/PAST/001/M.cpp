#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, M;
pll A[1005];
pll B[105];

bool check(double t) {
    {
        //! 手持ちのみ
        vector<double> v;
        REP(i, N) {
            v.push_back(A[i].second - t * A[i].first);
        }
        sort(v.begin(), v.end(), [](double a, double b) { return a > b; });
        double sum = 0;
        REP(i, 5) {
            sum += v[i];
        }
        if (sum >= 0)
            return true;
    }
    REP(m, M) {
        //! mを入れる
        vector<double> v;
        REP(i, N) {
            v.push_back(A[i].second - t * A[i].first);
        }
        v.push_back(B[m].second - t * B[m].first);
        sort(v.begin(), v.end(), [](double a, double b) { return a > b; });
        double sum = 0;
        REP(i, 5) {
            sum += v[i];
        }
        if (sum >= 0)
            return true;
    }

    return false;
}

int main() {
    cin >> N >> M;
    ll sum = 0;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        sum += A[i].second;
    }
    REP(i, M) {
        cin >> B[i].first >> B[i].second;
    }

    double ok = 0, ng = 5000005;
    REP(q, 100) {
        double mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }

    cout << OF64 << ok << endl;
    return 0;
}