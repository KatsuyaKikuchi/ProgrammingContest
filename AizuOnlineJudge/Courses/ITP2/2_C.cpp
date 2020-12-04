#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct PriorityQueue {

    PriorityQueue()
            : mLast(0) {
    }

    void push(ll x) {
        ll index = mLast;
        Q[mLast++] = x;
        while (index > 0) {
            ll parent = (index - 1) / 2;
            if (Q[parent] < Q[index])
                swap(Q[parent], Q[index]);
            index = parent;
        }
    }

    ll top() {
        if (mLast == 0)
            return INF;
        return Q[0];
    }

    void pop() {
        if (mLast == 0)
            return;
        Q[0] = Q[--mLast];
        ll index = 0;
        while (true) {
            ll left = index * 2 + 1, right = index * 2 + 2;
            if (left >= mLast)
                break;
            if (right >= mLast) {
                if (Q[index] < Q[left])
                    swap(Q[index], Q[left]);
                index = left;
                continue;
            }
            if (Q[left] < Q[right]) {
                if (Q[index] < Q[right])
                    swap(Q[index], Q[right]);
                index = right;
            }
            else {
                if (Q[index] < Q[left])
                    swap(Q[index], Q[left]);
                index = left;
            }
        }
    }

    void debug() {
        ll s = 0;
        ll p = 2;
        REP(i, mLast) {
            cout << Q[i] << " ";
            if (s == i) {
                cout << endl;
                s += p;
                p *= 2;
            }
        }
    }

    ll Q[200005];
    ll mLast = 0;
};

PriorityQueue PQ[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    REP(_, Q) {
        ll q;
        cin >> q;
        if (q == 0) {
            ll t, x;
            cin >> t >> x;
            PQ[t].push(x);
        }
        else if (q == 1) {
            ll t;
            cin >> t;
            ll top = PQ[t].top();
            if (top == INF)
                continue;
            cout << top << endl;
        }
        else {
            ll t;
            cin >> t;
            PQ[t].pop();
        }

    }

    return 0;
}