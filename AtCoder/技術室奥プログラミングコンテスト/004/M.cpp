#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<ll> L, R;

string query(vector<ll> v) {
    sort(v.begin(), v.end());
    cout << "? " << v.size();
    REP(i, v.size()) {
        cout << " " << v[i];
    }
    cout << endl;
    string ret;
    cin >> ret;
    return ret;
}

vector<ll> calc(vector<ll> v0, vector<ll> v1) {
    vector<ll> v[2];
    REP(i, v0.size()) {
        v[i % 2].push_back(v0[i]);
    }
    vector<ll> t;
    REP(i, v[0].size()) {
        t.push_back(v[0][i]);
    }
    REP(i, v1.size()) {
        t.push_back(v1[i]);
    }
    string ret = query(t);
    if (ret == "Rabbit")
        return v[0];
    return v[1];
}

int main() {
    ll N;
    cin >> N;
    vector<ll> base;
    REP(i, N) {
        base.push_back(i + 1);
    }

    //! 最初の1回は3分割して確認
    {
        vector<ll> v[3];
        REP(i, base.size()) {
            v[i % 3].push_back(base[i]);
        }

        vector<ll> t;
        REP(i, v[0].size()) {
            t.push_back(v[0][i]);
        }
        REP(i, v[1].size()) {
            t.push_back(v[1][i]);
        }
        string ret0 = query(t);
        if (ret0 == "Rabbit") {
            string ret1 = query(v[0]);
            string ret2 = query(v[1]);
            if (ret1 == "Rabbit") {
                base = v[0];
            }
            else if (ret2 == "Rabbit") {
                base = v[1];
            }
            else {
                L = v[0];
                R = v[1];
            }
        }
        else {
            string ret1 = query(v[2]);
            if (ret1 == "Rabbit") {
                base = v[2];
            }
            else {
                vector<ll> t1;
                REP(i, v[0].size()) {
                    t1.push_back(v[0][i]);
                }
                REP(i, v[2].size()) {
                    t1.push_back(v[2][i]);
                }
                string ret2 = query(t1);
                if (ret2 == "Rabbit") {
                    L = v[0];
                    R = v[2];
                }
                else {
                    L = v[1];
                    R = v[2];
                }
            }
        }
    }

    while (L.size() == 0 || R.size() == 0) {
        vector<ll> v[2];
        REP(i, base.size()) {
            v[i % 2].push_back(base[i]);
        }
        string ret0 = query(v[0]);
        string ret1 = query(v[1]);
        if (ret0 == "Rabbit") {
            base = v[0];
        }
        else if (ret1 == "Rabbit") {
            base = v[1];
        }
        else {
            L = v[0];
            R = v[1];
        }
    }

    while (L.size() > 1 || R.size() > 1) {
        if (L.size() > 1) {
            L = calc(L, R);
        }
        if (R.size() > 1) {
            R = calc(R, L);
        }
    }

    cout << "! " << std::min(L[0], R[0]) << " " << std::max(L[0], R[0]) << endl;
    return 0;
}