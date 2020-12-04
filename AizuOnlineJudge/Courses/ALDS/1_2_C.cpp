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
    string n;
    ll index;
};

ll N;

bool checkStable(vector<Data> v) {
    REP(i, N) {
        FOR(j, N, i) {
            if (v[i].n[1] != v[j].n[1])
                break;
            if (v[i].index > v[j].index)
                return false;
        }
    }
    return true;
}

void bubble(vector<Data> v) {
    REP(i, N) {
        for (ll j = N - 1; j > i; --j) {
            if (v[j].n[1] < v[j - 1].n[1])
                swap(v[j], v[j - 1]);
        }
    }
    REP(i, N - 1) {
        cout << v[i].n << " ";
    }
    cout << v[N - 1].n << endl;
    if (checkStable(v))
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;
}

void select(vector<Data> v) {
    auto copy = v;
    REP(i, N) {
        ll mi = i;
        FOR(j, N, i) {
            if (v[j].n[1] < v[mi].n[1])
                mi = j;
        }
        swap(v[i], v[mi]);
    }
    REP(i, N - 1) {
        cout << v[i].n << " ";
    }
    cout << v[N - 1].n << endl;
    if (checkStable(v))
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;
}

int main() {
    cin >> N;
    vector<Data> v;
    REP(i, N) {
        Data d;
        cin >> d.n;
        d.index = i;
        v.push_back(d);
    }

    bubble(v);
    select(v);

    return 0;
}