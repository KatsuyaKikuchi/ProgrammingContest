#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    bool e = true;
    bool ex = false;
    REP(i, N) {
        if (A[i] != K)
            e = false;
        else
            ex = true;
        if (A[i] >= K)
            A[i] = K;
    }
    if (e)
        return "yes";
    if (!ex)
        return "no";
    REP(i, N) {
        if (A[i] != K)
            continue;
        ll d = 0;
        FOR(j, N, i + 1) {
            if (A[j] >= K)
                d--;
            else
                d++;
            if (d <= 0)
                return "yes";
            if (A[j] == K)
                break;
        }
    }
    for (ll i = N - 1; i >= 0; --i) {
        if (A[i] != K)
            continue;
        ll d = 0;
        for (ll j = i - 1; j >= 0; --j) {
            if (A[j] >= K)
                d--;
            else
                d++;
            if (d <= 0)
                return "yes";
            if (A[j] == K)
                break;
        }
    }
    return "no";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}