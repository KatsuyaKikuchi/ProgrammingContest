#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Queue {
    Queue() {
        mBack = 0;
        mFront = 0;
    }

    void enqueue(ll x) {
        Q[mBack++] = x;
    }

    ll front() {
        if (mBack == mFront) {
            return INF;
        }
        return Q[mFront];
    }

    void dequeue() {
        if (mFront == mBack)
            return;
        mFront++;
    }

    ll Q[200005];
    ll mBack;
    ll mFront;
};

Queue Queues[1005];

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
            Queues[t].enqueue(x);
        }
        else if (q == 1) {
            ll t;
            cin >> t;
            ll front = Queues[t].front();
            if (front == INF)
                continue;
            cout << Queues[t].front() << endl;
        }
        else {
            ll t;
            cin >> t;
            Queues[t].dequeue();
        }
    }

    return 0;
}