#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[200005];

class Matrix {
public:
    Matrix(int r, int c, long long int id = 0)
            : mR(r), mC(c) {
        init(id);
    }

    void init(long long int id) {
        mMat.resize(mR, vector<long long int>(mC, id));
    }

    static Matrix Identity(int r, int c) {
        Matrix mat(r, c);
        for (int i = 0; i < std::min(r, c); ++i) {
            mat[i][i] = 1;
        }
        return mat;
    };

    void draw() {
        for (ll r = 0; r < mR; ++r) {
            for (ll c = 0; c < mC; c++) {
                cout << mMat[r][c] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &obj) {
        assert(this->mR == obj.mR);
        assert(this->mC == obj.mC);
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = this->mMat[r][c] + obj.mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator-(const Matrix &obj) {
        assert(this->mR == obj.mR);
        assert(this->mC == obj.mC);
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = this->mMat[r][c] - obj.mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator-() {
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = -this->mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator*(const Matrix &obj) {
        assert(this->mC == obj.mR);
        Matrix ret(this->mR, obj.mC);
        for (int r = 0; r < ret.mR; ++r) {
            for (int c = 0; c < ret.mC; ++c) {
                for (int i = 0; i < this->mC; ++i) {
                    ret.mMat[r][c] += this->mMat[r][i] * obj.mMat[i][c];
                }
            }
        }
        return ret;
    }

    Matrix &operator=(const Matrix &obj) {
        this->mR = obj.mR;
        this->mC = obj.mC;
        init(0);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                this->mMat[r][c] = obj.mMat[r][c];
            }
        }
        return *this;
    }

    vector<long long int> &operator[](int r) {
        assert(r < mR);
        return mMat[r];
    }

    int mR;
    int mC;
    vector<vector<long long int>> mMat;
};

struct OP {
    ll type;
    ll p;
};
struct Query {
    ll op;
    ll idx;
    ll origin;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    ll M;
    cin >> M;
    vector<OP> op(M);
    REP(i, M) {
        cin >> op[i].type;
        if (op[i].type >= 3) {
            cin >> op[i].p;
        }
    }
    ll Q;
    cin >> Q;
    vector<Query> query(Q);
    REP(i, Q) {
        cin >> query[i].op >> query[i].idx;
        query[i].origin = i;
        query[i].idx--;
    }

    Matrix mat = Matrix::Identity(3, 3);
    sort(query.begin(), query.end(), [](Query a, Query b) { return a.op < b.op; });
    vector<pll> ans(Q);
    ll idx = 0;
    REP(i, M + 1) {
        while (idx < Q && query[idx].op == i) {
            pll t = A[query[idx].idx];
            ans[query[idx].origin].first = t.first * mat[0][0] + t.second * mat[0][1] + mat[0][2];
            ans[query[idx].origin].second = t.first * mat[1][0] + t.second * mat[1][1] + mat[1][2];
            idx++;
        }
        if (i >= M)
            break;

        switch (op[i].type) {
            case 1: {
                Matrix rot(3, 3);
                rot[0][1] = 1;
                rot[1][0] = -1;
                rot[2][2] = 1;
                mat = rot * mat;
            }
                break;
            case 2: {
                Matrix rot(3, 3);
                rot[0][1] = -1;
                rot[1][0] = 1;
                rot[2][2] = 1;
                mat = rot * mat;
            }
                break;
            case 3: {
                ll p = op[i].p;
                Matrix m0 = Matrix::Identity(3, 3);
                Matrix m1 = Matrix::Identity(3, 3);
                Matrix m2 = Matrix::Identity(3, 3);
                m1[0][0] = -1;
                m0[0][2] = -p;
                m2[0][2] = p;
                mat = m2 * m1 * m0 * mat;
            }
                break;
            case 4: {
                ll p = op[i].p;
                Matrix m0 = Matrix::Identity(3, 3);
                Matrix m1 = Matrix::Identity(3, 3);
                Matrix m2 = Matrix::Identity(3, 3);
                m1[1][1] = -1;
                m0[1][2] = -p;
                m2[1][2] = p;
                mat = m2 * m1 * m0 * mat;
            }
                break;
        }
    }

    REP(i, Q) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}