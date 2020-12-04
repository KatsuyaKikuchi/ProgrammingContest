#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[7] = {1, 3, 5, 7, 8, 10, 12};
ll B[4] = {4, 6, 9, 11};
ll C[1] = {2};

int main() {
    ll x, y;
    cin >> x >> y;
    {
        bool X = false;
        bool Y = false;
        REP(i, 7) {
            if (A[i] == x)
                X = true;
            if (A[i] == y)
                Y = true;
        }
        if (X && Y) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    {
        bool X = false;
        bool Y = false;
        REP(i, 4) {
            if (B[i] == x)
                X = true;
            if (B[i] == y)
                Y = true;
        }
        if (X && Y) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    {
        bool X = false;
        bool Y = false;
        REP(i, 1) {
            if (C[i] == x)
                X = true;
            if (C[i] == y)
                Y = true;
        }
        if (X && Y) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}