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
    ll prev = -1;
    ll nxt = -1;
    ll value = INF;
};

Data D[500005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    ll index = 1;
    ll cursor = 0;
    REP(_, Q) {
        ll q;
        cin >> q;
        if (q == 0) {
            ll x;
            cin >> x;
            ll p = D[cursor].prev;
            D[cursor].prev = index;
            D[index].nxt = cursor;
            D[index].value = x;
            D[index].prev = p;
            if (p >= 0)
                D[p].nxt = index;
            cursor = index;
            index++;
        }
        else if (q == 1) {
            ll d;
            cin >> d;
            if (d > 0) {
                REP(i, abs(d)) {
                    cursor = D[cursor].nxt;
                }
            }
            else {
                REP(i, abs(d)) {
                    cursor = D[cursor].prev;
                }
            }
        }
        else {
            if (D[cursor].nxt >= 0)
                D[D[cursor].nxt].prev = D[cursor].prev;
            if (D[cursor].prev >= 0)
                D[D[cursor].prev].nxt = D[cursor].nxt;
            cursor = D[cursor].nxt;
        }

#if false
        vector<ll> v;
        ll tmp = 0;
        while (D[tmp].prev != -1) {
            ll p = D[tmp].prev;
            v.push_back(D[p].value);
            tmp = p;
        }
        reverse(v.begin(), v.end());
        REP(i, v.size()) {
            cout << v[i] << " ";
        }
        cout << endl;
#endif
    }

    vector<ll> v;
    cursor = 0;
    while (D[cursor].prev != -1) {
        ll p = D[cursor].prev;
        v.push_back(D[p].value);
        cursor = p;
    }
    reverse(v.begin(), v.end());
    REP(i, v.size()) {
        cout << v[i] << endl;
    }
    return 0;
}