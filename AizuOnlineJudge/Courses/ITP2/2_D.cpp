#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct List {
    List() {
        first = new Node();
        last = new Node();

        first->nxt = last;
        last->prev = first;
    }

    ~List() {
        Node *nodePtr = first;
        while (nodePtr != nullptr) {
            Node *nxt = nodePtr->nxt;
            delete (nodePtr);
            nodePtr = nxt;
        }
    }

    void insert(ll x) {
        Node *newNodePtr = new Node();
        newNodePtr->value = x;
        Node *prevPtr = last->prev;
        newNodePtr->nxt = last;
        newNodePtr->prev = prevPtr;
        prevPtr->nxt = newNodePtr;
        last->prev = newNodePtr;
    }

    void dump() {
        Node *nodePtr = first->nxt;
        while (nodePtr != last) {
            cout << nodePtr->value;
            nodePtr = nodePtr->nxt;
            if (nodePtr == last)
                break;
            cout << " ";
        }
        cout << endl;
    }

    void splice(List &list) {
        Node *nodePtr = last->prev;

        nodePtr->nxt = list.first->nxt;
        last->prev = list.last->prev;
        list.first->nxt->prev = first;
        list.last->prev->nxt = last;

        list.first->nxt = list.last;
        list.last->prev = list.first;
    }

    struct Node {
        Node *prev = nullptr;
        Node *nxt = nullptr;
        ll value;
    };

    Node *first;
    Node *last;
};

List L[1005];

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
            L[t].insert(x);
        }
        else if (q == 1) {
            ll t;
            cin >> t;
            L[t].dump();
        }
        else {
            ll s, t;
            cin >> s >> t;
            L[t].splice(L[s]);
        }
    }
    return 0;
}