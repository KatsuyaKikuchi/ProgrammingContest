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
    ll cnt = 0;
    pll s = pll(INF, -INF);
};

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    REP(i, N) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    vector<Data> D(B.size());
    REP(i, N) {
        A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        D[A[i]].cnt++;
        D[A[i]].s.first = std::min(D[A[i]].s.first, i);
        D[A[i]].s.second = std::max(D[A[i]].s.second, i);
    }
    //! memo
    //! 最初と最後だけLIS?
#if false
    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    REP(i, D.size()) {
        cout << "(" << D[i].cnt << "," << D[i].s.first << "," << D[i].s.second << ") ";
    }
    cout << endl;
#endif

    vector<bool> U(D.size());
    ll mx = 0;
    REP(i, D.size()) {
        if (U[i])
            continue;
        ll len = D[i].cnt;
        ll index = i;
        U[i] = true;
        while (index + 1 < D.size()) {
            if (D[index + 1].s.first < D[index].s.second)
                break;

            index++;
            len += D[index].cnt;
            U[index] = true;
        }
        mx = std::max(mx, len);
    }

    return N - mx;
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