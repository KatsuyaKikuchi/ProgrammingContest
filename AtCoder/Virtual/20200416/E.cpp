#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
ll A, B, Q;
ll T[100005], S[100005];

ll solve(ll x) {
    ll s = 0, t = 0;
    {
        ll ng = A;
        while (abs(s - ng) > 1) {
            ll mid = (ng + s) / 2;
            if (S[mid] <= x)
                s = mid;
            else
                ng = mid;
        }
    }
    {
        ll ng = B;
        while (abs(t - ng) > 1) {
            ll mid = (ng + t) / 2;
            if (T[mid] <= x)
                t = mid;
            else
                ng = mid;
        }
    }

    ll ret = INF;
    vector<ll> ps, pt;
    ps.push_back(S[s]);
    s = std::min(s + 1, A - 1);
    ps.push_back(S[s]);
    pt.push_back(T[t]);
    t = std::min(t + 1, B - 1);
    pt.push_back(T[t]);

    ret = std::min({ret,
                    abs(x - ps[0]) + abs(ps[0] - pt[0]),
                    abs(x - ps[0]) + abs(ps[0] - pt[1]),
                    abs(x - pt[0]) + abs(pt[0] - ps[0]),
                    abs(x - pt[0]) + abs(pt[0] - ps[1]),
                    abs(x - ps[1]) + abs(ps[1] - pt[0]),
                    abs(x - ps[1]) + abs(ps[1] - pt[1]),
                    abs(x - pt[1]) + abs(pt[1] - ps[0]),
                    abs(x - pt[1]) + abs(pt[1] - ps[1])});

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> A >> B >> Q;
    REP(i, A) {
        cin >> S[i];
    }
    REP(i, B) {
        cin >> T[i];
    }
    sort(S, S + A);
    sort(T, T + B);

    REP(i, Q) {
        ll x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}