#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> T(N, 0);
    REP(i, N) {
        cin >> A[i];
        A[i]--;
        T[A[i]]++;
    }
    ll mx = -1;
    REP(i, N) {
        if (T[i] == 0)
            break;
        mx = i;
    }
    string ret = "";
    bool can = true;
    ll left = 0, right = N - 1;
    for (ll n = N - 1; n >= 1; --n) {
        ll len = N - 1 - n;
        if (mx < len) {
            ret.push_back('0');
            continue;
        }

        if (can)
            ret.push_back('1');
        else
            ret.push_back('0');
        if (T[len] > 1)
            can = false;
        if (A[left] != len && A[right] != len)
            can = false;
        if (A[left] == len)
            left++;
        else if (A[right] == len)
            right--;
    }
    {
        bool can = true;
        REP(i, N) {
            if (T[i] == 0)
                can = false;
        }
        if (can)
            ret.push_back('1');
        else
            ret.push_back('0');
    }

    reverse(ret.begin(), ret.end());
    return ret;
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