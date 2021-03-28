#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define TEST 0

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

#if TEST
vector<ll> test;
ll nq;

ll testQuery(vector<ll> v) {
    if (nq <= 0)
        return -1;
    nq--;
    vector<ll> m(3);
    REP(i, 3) {
        REP(j, test.size()) {
            if (test[j] == v[i]) {
                m[i] = j;
                break;
            }
        }
    }
    ll mid = m[0] + m[1] + m[2] - std::max({m[0], m[1], m[2]}) - std::min({m[0], m[1], m[2]});
    return test[mid];
}

ll testResult(vector<ll> v) {
#if false
    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;
#endif
    if (nq <= 0)
        return -1;
    if (test.size() != v.size())
        return -1;
    {
        bool e = true;
        REP(i, v.size()) {
            if (v[i] != test[i])
                e = false;
        }
        if (e)
            return true;
    }
    {
        bool e = true;
        reverse(test.begin(), test.end());
        REP(i, v.size()) {
            if (v[i] != test[i])
                e = false;
        }
        if (e)
            return true;
    }
    reverse(test.begin(), test.end());

    return -1;
}

#endif

ll query(const vector<ll> &v, ll &Q) {
#if TEST
    return testQuery(v);
#else
    if (Q <= 0)
        return -1;
    Q--;
    REP(i, v.size()) {
        cout << v[i] + 1 << " ";
    }
    cout << endl;
    ll ret;
    cin >> ret;
    return ret - 1;
#endif
}

ll result(const vector<ll> &ans) {
#if TEST
    return testResult(ans);
#else
    REP(i, ans.size()) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
    ll ret;
    cin >> ret;
    return ret;
#endif
}

bool solve(ll N, ll Q) {
    vector<ll> ans = {0, 1, 2};
    {
        vector<ll> v = {0, 1, 2};
        ll c = query(v, Q);
        if (c == 0)
            swap(ans[0], ans[1]);
        if (c == 2)
            swap(ans[1], ans[2]);
    }

    FOR(n, N, 3) {
        // 半開区間で管理
        ll left = 0, right = ans.size() + 1;
        while (abs(right - left) > 1) {
            vector<ll> v = {n};
            ll len = right - left - 1;
            ll num = len / 3;
            ll ml = left + num;
            ll mr = ml + std::max(num, 1LL);
            if (len <= 2) {
                if (left == ans.size() - 1) {
                    ml = left - 1;
                    mr = left;
                }
                else {
                    ml = left;
                    mr = left + 1;
                }
            }

            v.push_back(ans[ml]);
            v.push_back(ans[mr]);
            ll c = query(v, Q);
            if (c < 0)
                return false;
            if (c == ans[ml]) {
                right = ml + 1;
            }
            else if (c == ans[mr]) {
                left = mr + 1;
            }
            else {
                left = ml + 1;
                right = mr + 1;
            }
        }
        ans.insert(ans.begin() + left, n);
#if false
        cout << "ans:";
        REP(j, ans.size()) {
            cout << ans[j] + 1 << " ";
        }
        cout << endl;
#endif
    }

    ll ret = result(ans);
    return ret >= 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T, N, Q;
#if TEST

    Q = 50;
    vector<ll> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    N = v.size();

    ll count = 0;
    do {
        test.resize(N);
        REP(i, N) {
            test[i] = v[i];
        }
        nq = Q;
        if (!solve(N, Q)) {
            cout << "out!";
            REP(i, N) {
                cout << test[i] << " ";
            }
            cout << endl;
            break;
        }
        cout << count++ << endl;
    } while (next_permutation(v.begin(), v.end()));
    cout << "end" << endl;
#else
    cin >> T >> N >> Q;
    REP(_, T) {
        if (!solve(N, Q / T))
            break;
    }
#endif
    return 0;
}