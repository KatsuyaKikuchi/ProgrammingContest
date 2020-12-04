#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[300005];
ll SL[100005];
ll SR[100005];

int main() {
    ll N;
    cin >> N;

    REP(i, 3 * N) {
        cin >> A[i];
    }
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q0([](ll a, ll b) { return a > b; });
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q1([](ll a, ll b) { return a < b; });
    ll sl = 0, sr = 0;
    REP(i, N) {
        q0.push(A[i]);
        q1.push(A[3 * N - 1 - i]);
        sl += A[i];
        sr += A[3 * N - 1 - i];
    }
    SL[0] = sl;
    SR[N] = sr;
    REP(i, N) {
        {
            ll a = A[N + i];
            ll t = q0.top();
            if (a > t) {
                q0.pop();
                q0.push(a);
                sl += (a - t);
            }
        }
        {
            ll a = A[2 * N - 1 - i];
            ll t = q1.top();
            if (a < t) {
                q1.pop();
                q1.push(a);
                sr += (a - t);
            }
        }

        SL[i + 1] = sl;
        SR[N - 1 - i] = sr;
    }

    ll ans = -INF;
    REP(i, N + 1) {
        ans = std::max(SL[i] - SR[i], ans);
    }
    cout << ans << endl;
    return 0;
}