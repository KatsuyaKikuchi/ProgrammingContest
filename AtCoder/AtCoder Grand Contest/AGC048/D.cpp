#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool check(vector<ll> &v) {
    ll N = v.size();
    if (N == 1)
        return true;
    if (N == 2) {
        if (v[0] > v[1])
            return true;
        return false;
    }
    if (N == 3) {
        if (v[0] > v[1] + v[2] || v[1] >= v[2])
            return true;
        return false;
    }

    ll sum = 0;
    FOR(i, N, 1) {
        sum += v[i];
    }
    if (sum < v[0])
        return true;

    {
        vector<ll> t;
        REP(i, N) {
            t.push_back(v[i]);
        }
        reverse(t.begin(), t.end());
        t.pop_back();

        if (!check(t))
            return true;
    }

    bool f = false;
    if (v[0] > v[N - 1]) {
        vector<ll> t;
        REP(i, N) {
            t.push_back(v[i]);
        }
        reverse(t.begin(), t.end());
        if (--t[N - 1] == 0)
            t.pop_back();

        if (!check(t))
            return true;
    }


    return false;
}

string solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    if (check(A))
        return "First";
    return "Second";
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