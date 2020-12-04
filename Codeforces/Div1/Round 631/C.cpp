#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool func0(vector<ll> &A, ll index) {
    ll left = index * 2, right = index * 2 + 1;
    if (left > A.size())
        return true;

    if (A[left - 1] == A[right - 1])
        return false;

    if (A[left - 1] > A[right - 1])
        return func0(A, left);
    return func0(A, right);
}

void func1(vector<ll> &A, ll index) {
    ll left = index * 2, right = index * 2 + 1;
    if (left > A.size()) {
        A[index - 1] = 0;
        return;
    }
    if (A[left - 1] > A[right - 1]) {
        A[index - 1] = A[left - 1];
        func1(A, left);
        return;
    }
    A[index - 1] = A[right - 1];
    func1(A, right);
}

void solve(ll H, ll G, vector<ll> &A) {
    ll N = A.size();
    ll M = pow(2LL, G) - 1;
    ll index = 1;
    ll sum = 0;
    REP(i, N) {
        sum += A[i];
    }
    vector<ll> ans(N - M);
    REP(i, N - M) {
        while (!func0(A, index)) {
            index++;
        }
        ans[i] = index;
        sum -= A[index - 1];
        func1(A, index);
    }

    cout << sum << endl;
    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll H, G;
        cin >> H >> G;
        ll N = pow(2LL, H);
        vector<ll> A(N - 1);
        REP(i, N - 1) {
            cin >> A[i];
        }
        solve(H, G, A);
    }
    return 0;
}