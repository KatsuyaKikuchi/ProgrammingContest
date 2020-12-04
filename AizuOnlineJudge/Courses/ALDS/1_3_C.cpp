#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct DoubleLinkedList {
    struct Node {
        ll prev = -1;
        ll next = -1;

        ll value = -1;
    };

    DoubleLinkedList(ll num) {
        mNodeTbl.resize(num);
        FOR(i, num, 2) {
            mNodeStack.push(i);
        }
        mpFirst = &mNodeTbl[0];
        mpLast = &mNodeTbl[1];

        mpFirst->next = 1;
        mpLast->prev = 0;
    }

    ~DoubleLinkedList() {
    }

    void insert(ll x) {
        ll index = mNodeStack.top();
        mNodeStack.pop();
        Node *pNewNode = &mNodeTbl[index];

        pNewNode->prev = 0;
        pNewNode->next = mpFirst->next;
        pNewNode->value = x;

        mNodeTbl[mpFirst->next].prev = index;
        mpFirst->next = index;
    }

    void eraceIndex(ll x) {
        ll index = mpFirst->next;
        while (index != 1) {
            if (mNodeTbl[index].value == x) {
                erace(index);
                break;
            }
            index = mNodeTbl[index].next;
        }
    }

    void eraceLast() {
        ll index = mpLast->prev;
        erace(index);
    }

    void eraceFirst() {
        ll index = mpFirst->next;
        erace(index);
    }

    void erace(ll index) {
        Node *pNode = &mNodeTbl[index];

        mNodeTbl[pNode->prev].next = pNode->next;
        mNodeTbl[pNode->next].prev = pNode->prev;

        mNodeStack.push(index);
    }

    void print() {
        ll index = mpFirst->next;
        while (index != 1) {
            cout << mNodeTbl[index].value;
            index = mNodeTbl[index].next;
            if (index != 1)
                cout << " ";
        }
        cout << endl;
    }

    Node *mpFirst;
    Node *mpLast;

    vector<Node> mNodeTbl;

    stack<ll> mNodeStack;
};

string S[4] = {"insert", "delete", "deleteLast", "deleteFirst"};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    DoubleLinkedList lst(1000005);
    string com;
    REP(_, N) {
        cin >> com;
        if (com == S[0]) {
            ll x;
            cin >> x;
            lst.insert(x);
        }
        else if (com == S[1]) {
            ll n;
            cin >> n;
            lst.eraceIndex(n);
        }
        else if (com == S[2]) {
            lst.eraceLast();
        }
        else if (com == S[3]) {
            lst.eraceFirst();
        }
    }

    lst.print();
    return 0;
}