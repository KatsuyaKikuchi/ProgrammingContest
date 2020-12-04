#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B;
    cin >> A >> B;
    REP(i, A) {
        ll p;
        cin >> p;
        T[(p + 9) % 10] = 1;
    }
    REP(i, B) {
        ll p;
        cin >> p;
        T[(p + 9) % 10] = 2;
    }
    FOR(i, 10, 6) {
        if (T[i] == 0)
            cout << "x";
        if (T[i] == 1)
            cout << ".";
        if (T[i] == 2)
            cout << "o";
        cout << " ";
    }
    cout << endl;
    cout << " ";
    FOR(i, 6, 3) {
        if (T[i] == 0)
            cout << "x";
        if (T[i] == 1)
            cout << ".";
        if (T[i] == 2)
            cout << "o";
        cout << " ";
    }
    cout << endl;
    cout << "  ";
    FOR(i, 3, 1) {
        if (T[i] == 0)
            cout << "x";
        if (T[i] == 1)
            cout << ".";
        if (T[i] == 2)
            cout << "o";
        cout << " ";
    }
    cout << endl;
    cout << "   ";
    FOR(i, 1, 0) {
        if (T[i] == 0)
            cout << "x";
        if (T[i] == 1)
            cout << ".";
        if (T[i] == 2)
            cout << "o";
        cout << " ";
    }
    cout << endl;
    return 0;
}