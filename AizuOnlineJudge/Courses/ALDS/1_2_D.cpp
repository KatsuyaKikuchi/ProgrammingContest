#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
ll A[1000005];

ll insertSort(ll g, ll cnt) {
    for (ll i = g; i < N; ++i) {
        ll v = A[i];
        ll j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = v;
    }
    return cnt;
}

void shellSort() {
    ll cnt = 0;
    vector<ll> v;
    ll t = 1LL;
    while (t <= N) {
        v.push_back(t);
        t *= 2LL;
    }

    cout << v.size() << endl;
    for (int i = v.size() - 1; i >= 0; --i) {
        cnt = insertSort(v[i], cnt);
        cout << v[i];
        if (i > 0)
            cout << " ";
    }
    cout << endl;
    cout << cnt << endl;
    REP(i, N) {
        cout << A[i] << endl;
    }
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    shellSort();
    return 0;
}