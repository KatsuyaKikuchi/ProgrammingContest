#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll B[100005];

ll seen = -1;

ll get_r(ll index) {
    if (index >= seen)
        return A[index];

    ll a = A[seen];
    return a - (seen - index);
}

ll get_l(ll index) {
    if (index == -1) {
        return 0;
    }
    if (index <= seen)
        return A[index];

    ll a = 0;
    if (seen >= 0) {
        a = A[seen];
    }

    return a + (index - seen);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, L;
    cin >> N >> L;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    A[N] = L + 1;

    ll ans = 0;

    REP(i, N) {
        ll a = get_r(i);
        if (B[i] < a)
            continue;
        if (B[i] == a) {
            A[i] = a;
            continue;
        }

        FOR(j, N + 1, seen) {
            ll num = j - i;
            ll g = A[j] - num;
            if (g != B[i])
                continue;
            ans += num;
            seen = j;
            break;
        }

        if (get_r(i) != B[i]) {
            ans = -1;
            break;
        }
        A[i] = B[i];
    }

    if (ans < 0) {
        cout << -1 << endl;
        return 0;
    }

    seen = N;
    for (ll i = N - 1; i >= 0; --i) {
        ll a = get_l(i);
        if (B[i] >= a)
            continue;

        if (i == 0) {
            if (B[i] == 1)
                ans++;
            else
                ans = -1;
            break;
        }


        for (ll j = std::min(seen, i - 1); j >= -1; --j) {
            ll num = i - j;
            ll g = get_l(j) + num;
            if (g != B[i])
                continue;
            ans += num;
            seen = j;
            break;
        }

        if (get_l(i) != B[i]) {
            ans = -1;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}