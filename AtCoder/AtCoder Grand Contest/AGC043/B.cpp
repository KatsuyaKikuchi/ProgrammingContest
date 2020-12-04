#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[1000006];

struct TestCase {
    TestCase() {
        std::random_device rnd;
        mMt = std::mt19937(rnd());
    }

    int get(int low, int height) {
        if (low > height)
            swap(low, height);
        int d = height - low;
        if (d == 0)
            return low;
        std::uniform_int_distribution<> rand(0, d);
        return low + rand(mMt);
    }

    std::mt19937 mMt;
};

ll solve(string &S) {
    ll N = S.length();
    vector<ll> v(N);
    REP(i, N) {
        v[i] = S[i] - '0';
    }

    ll ans = 0;
    ll m = INF;
    bool use = false;
    REP(i, N - 1) {
        vector<ll> t(N - i - 1);
        ll z = 0;
        ll max = 0;
        REP(j, N - i - 1) {
            t[j] = abs(v[j] - v[j + 1]);
            max = std::max(t[j], max);
            if (t[j] == 0)
                z++;
        }
        if (z >= t.size() - 1 && !use) {
            ans = max;
            use = true;
            m = std::min(m, i);
        }
        v.swap(t);
    }

    cout << m << endl;
    cout << endl;
    if (ans != v[0]) {
        return -1;
    }
    return v[0];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    TestCase test;
    while (true) {
        ll N = test.get(10, 10);
        string S = "";
        REP(i, N) {
            S.push_back((char) (test.get(1, 3) + '0'));
        }

        ll n = solve(S);
        if (n < 0) {
            cout << "error" << endl;
            cout << S << endl;
            break;
        }
        //if (n == 1)
        {
            //cout << n << ":" << S << endl;
            //break;
        }
    }
    return 0;
}