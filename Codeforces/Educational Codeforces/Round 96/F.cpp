#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    pll range;
    ll value;
};

Data A[2005];
ll mn[2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i].range.first >> A[i].range.second >> A[i].value;
    }

    REP(i, N + 2) {
        mn[i] = INF;
    }
    mn[0] = 0;

    REP(i, N) {
        ll value = K;
        ll sum = 0;
        FOR(j, N, i) {
            sum += A[j].value;
            ll range = A[j].range.second - A[j].range.first + 1;
            if ((range - 1) * K + value < A[j].value)
                break;
            ll count = 1;
            if (A[j].value <= value) {
                value = value - A[j].value;
            }
            else {
                count += (A[j].value - value + K - 1) / K;
                value = (K - (A[j].value - value) % K) % K;
            }

            if (count == range && j < N - 1) {
                if (A[j].range.second == A[j + 1].range.first)
                    continue;
            }
            ll value = sum;
            if (j != N - 1)
                value = ((value + K - 1) / K) * K;
            mn[j + 1] = std::min(mn[j + 1], mn[i] + value);
        }
    }

    if (mn[N] == INF)
        cout << -1 << endl;
    else
        cout << mn[N] << endl;

    return 0;
}