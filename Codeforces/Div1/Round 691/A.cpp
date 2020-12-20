#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, M;
ll A[200005];
ll B[200005];

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

vector<ll> test() {
    vector<ll> ret(M);
    REP(i, M) {
        ll g = A[0] + B[i];
        REP(j, N) {
            g = gcd(g, A[j] + B[i]);
        }
        ret[i] = g;
    }
    return ret;
}


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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    //REP(_, 10000)
    {
#if true
        cin >> N >> M;
        REP(i, N) {
            cin >> A[i];
        }
        REP(i, M) {
            cin >> B[i];
        }
#else
        TestCase tst;
        N = tst.get(1, 20);
        M = tst.get(1, 20);
        REP(i, N) {
            A[i] = tst.get(1, 100);
        }
        REP(i, M) {
            B[i] = tst.get(1, 100);
        }
#endif

        sort(A, A + N);
        ll g = 0;
        REP(i, N - 1) {
            ll n = A[i + 1] - A[i];
            if (g == 0) {
                g = n;
            }
            else if (n > 0) {
                g = gcd(g, n);
            }
        }

        vector<ll> ans(M);
        REP(i, M) {
            if (g == 0)
                ans[i] = A[0] + B[i];
            else
                ans[i] = gcd(A[0] + B[i], g);
        }

#if false
        auto t = test();
        bool e = true;
        REP(i, M) {
            if (t[i] != ans[i]) {
                e = false;
                break;
            }
        }
        if (!e) {
            cout << "No!" << endl;
            REP(i, N) {
                cout << A[i] << " ";
            }
            cout << endl;
            REP(i, M) {
                cout << B[i] << " ";
            }
            cout << endl;

            REP(i, M) {
                cout << t[i] << " " << ans[i] << endl;
            }
        }
#else
        REP(i,M)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
#endif
    }


    return 0;
}