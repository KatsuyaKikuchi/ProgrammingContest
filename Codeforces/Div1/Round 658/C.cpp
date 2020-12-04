#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool check(vector<ll> &A, vector<ll> &B, ll X, ll Y) {
    ll x = 0;
    ll N = A.size();
    REP(i, N) {
        if (A[i] == B[i])
            x++;
    }
    map<ll, ll> MA, MB;
    REP(i, N) {
        MA[A[i]]++;
        MB[B[i]]++;
    }

    ll y = 0;
    REP(i, N + 1) {
        y += std::min(MA[i + 1], MB[i + 1]);
    }

    //    ll y = 0;
    return x == X && y == Y;
}

void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N), B(N);
    vector<stack<ll>> stack(N + 1);
    REP(i, N) {
        cin >> A[i];
        B[i] = A[i];
        stack[A[i] - 1].push(i);
    }
    vector<bool> U(N + 1, false);
    map<ll, ll> Map;
    REP(i, A.size()) {
        U[A[i] - 1] = true;
        Map[A[i]]++;
    }

    ll x = -1;
    REP(i, N + 1) {
        if (!U[i]) {
            x = i + 1;
            break;
        }
    }
    ll mx = 0;
    REP(i, A.size()) {
        mx = std::max(mx, Map[A[i]]);
    }
    ll cnt = 0;
    REP(i, N + 1) {
        if (Map[i + 1] > 0)
            cnt++;
    }

#if false
    {
        //! swap最大回数
        ll swap = N - mx;
        //! remove 最大回数
        ll remove = N - Y;
        if (swap * 2 + remove < N - X) {
            cout << "NO" << endl;
            return;
        }
        if ((N - X) % 2 == 1) {
            if (cnt <= 2 && remove == 0) {
                cout << "NO" << endl;
                return;
            }
            if (Y == N && X == N - 1) {
                cout << "NO" << endl;
                return;
            }
        }
    }
#endif

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) {
        return a.second < b.second;
    });
    REP(i, N + 1) {
        ll num = Map[i + 1];
        if (num > 0)
            q.push(pll(i, num));
    }

    ll remove = N - Y;
    if ((N - X - remove) % 2 == 1 && cnt <= 2)
        remove--;
    REP(_, remove) {
        pll t = q.top();
        q.pop();

        ll index = stack[t.first].top();
        stack[t.first].pop();

        B[index] = mx;

        t.second--;
        q.push(t);
    }

    //! swap;
    ll swap = (N - X - remove) / 2;
    ll change = N - X - (swap * 2 + remove);
    REP(i, N) {
        if (swap == 0)
            break;
        if (B[i] != A[i])
            continue;

        while (!q.empty()) {
            pll t = q.top();
            q.pop();
            if (t.first == B[i] - 1) {
                if (q.empty())
                    break;
                pll tmp = q.top();
                q.pop();
                q.push(t);
                t = tmp;
            }
            bool exist = false;
            while (!stack[t.first].empty()) {
                ll tp = stack[t.first].top();
                if (B[tp] == A[tp]) {
                    exist = true;
                    break;
                }
                stack[t.first].pop();
            }

            if (exist) {
                ll tp = stack[t.first].top();
                stack[t.first].pop();
                ll tmp = B[i];
                B[i] = B[tp];
                B[tp] = tmp;
                swap--;
                break;
            }
        }
    }

    if (change > 0 && cnt <= 2) {
        cout << "NO" << endl;
        return;
    }

    if (change > 0) {
        REP(i, N) {
            if (B[i] == A[i])
                continue;

            bool exist = false;
            FOR(j, N, i + 1) {
                if (B[j] == A[j])
                    continue;
                if (B[i] == A[j] || B[j] == A[i])
                    continue;
                exist = true;
                ll tmp = B[i];
                B[i] = B[j];
                B[j] = tmp;
                break;
            }
            if (exist)
                break;
        }
    }

    REP(_, (N - Y) - remove) {
        REP(i, N) {
            if (B[i] == A[i])
                continue;
            B[i] = mx;
            break;
        }
    }
    if (!check(A, B, X, Y)) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    REP(i, B.size()) {
        cout << B[i] << " ";
    }
    cout << endl;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}