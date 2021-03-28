#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;


string solve(vector<vector<ll>> &board, pll g) {
    pll dir = pll(0, 1);
    ll N = 20;
    while (true) {
        ll type = board[g.first][g.second];
        if (type == 1) {
            dir = pll(dir.second, dir.first);
        }
        else if (type == 2) {
            dir = pll(-dir.second, -dir.first);
        }
        board[g.first][g.second] = 0;
        ll nx = g.first + dir.first, ny = g.second + dir.second;
        if (nx < 0 || nx >= N || ny < 0 || ny >= 20)
            break;
        g = pll(nx, ny);
    }

    string ret = "";

    g.first++;
    while (g.first > 0) {
        ll n = g.first % 10;
        ret.push_back(n + '0');
        g.first /= 10;
    }
    ret.push_back(g.second + 'A');
    reverse(ret.begin(), ret.end());
    return ret;
}

string solve(string &S) {
    ll N = 20;
    vector<vector<ll>> board(N, vector<ll>(N, 0));
    ll h = 0, w = 0;
    ll type = 0;
    REP(i, S.length()) {
        if (S[i] < '0' || S[i] > '9') {
            if (h > 0) {
                board[h - 1][w] = type;
            }
            if (S[i] >= 'a' && S[i] <= 'z') {
                type = 1;
                w = S[i] - 'a';
            }
            else {
                type = 2;
                w = S[i] - 'A';
            }
            h = 0;
        }
        else {
            h = h * 10 + S[i] - '0';
        }
    }

    REP(i, 9) {
        solve(board, pll(i, 0));
    }
    return solve(board, pll(9, 0));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string A = "E1h1I1K1l1o1p1Q1R1T1A2E2F2k2l2n2o2r2S2t2B3C3D3E3L3M3N3O3Q3R3a4C4f4g4H4i4J4k4O4S4d5E5F5g5I5m5N5O5R5S5C6E6h6n6O6p6Q6R6s6t6a7d7f7j7K7P7Q7r7S7T7A8b8C8D8E8F8g8l8M8o8A9c9d9e9f9h9J9k9N9t9C10D10e10f10G10i10J10K10n10s10a11C11D11f11j11l11p11q11r11S11A12c12D12e12F12h12K12L12O12p12d13E13f13K13l13P13Q13R13s13t13B14C14D14H14m14o14Q14r14S14T14H15I15J15k15l15m15N15p15r15S15B16h16i16J16K16n16o16p16R16s16k17L17M17N17o17p17q17R17S17T17a18C18D18E18f18h18i18J18m18o18b19e19F19G19J19k19L19p19q19r19A20b20c20d20k20L20Q20R20S20T20";
    string B = "e1i1j1M1N1o1P1Q1R1s1a2D2F2g2i2J2k2N2o2R2F3H3I3j3K3L3O3R3S3t3b4d4f4G4H4N4O4q4R4S4c5D5E5F5G5i5M5n5Q5R5a6B6c6k6n6O6p6Q6r6S6A7B7c7D7E7F7P7Q7r7t7e8F8G8k8l8M8N8r8s8T8a9d9h9i9J9k9l9m9R9t9b10C10E10H10i10m10N10P10q10S10a11B11C11d11e11f11g11J11M11O11b12d12E12f12G12H12i12k12L12r12b13d13e13g13h13I13k13m13n13q13E14F14i14k14M14N14o14p14q14r14c15e15F15H15M15N15O15q15R15T15a16B16f16G16h16M16n16o16Q16R16a17B17C17E17h17I17j17l17O17r17E18F18h18I18J18M18n18O18R18s18d19F19g19h19K19l19M19r19S19t19B20C20D20i20J20K20l20M20O20T20";
    string C = "A1B1c1D1e1F1g1H1O1Q1A2b2C2E2G2H2I2o2R2s2a3B3C3e3g3m3q3R3s3T3e4H4I4J4K4l4m4n4s4t4h5j5k5l5m5N5O5p5q5S5a6c6D6E6k6l6m6P6q6r6A7D7g7H7k7L7P7Q7r7T7C8D8f8n8o8P8Q8r8s8T8A9b9d9E9F9G9H9N9p9R9c10d10E10G10N10p10q10r10s10T10i11J11K11l11m11N11O11R11S11T11A12b12c12H12i12K12l12m12n12O12c13d13e13F13G13J13K13N13q13R13B14c14g14i14K14l14m14n14o14q14a15B15c15d15h15M15n15o15P15S15C16E16j16k16L16n16O16P16Q16t16a17b17C17E17h17I17J17O17R17T17d18f18J18k18L18M18N18P18q18T18c19d19e19f19J19K19M19q19R19T19A20B20d20k20l20M20N20R20s20T20";

    vector<string> ans;
    ans.push_back(solve(A));
    ans.push_back(solve(B));
    ans.push_back(solve(C));
    REP(i, ans.size()) {
        cout << ans[i];
        if (i < ans.size() - 1)
            cout << ",";
    }
    cout << endl;

    return 0;
}