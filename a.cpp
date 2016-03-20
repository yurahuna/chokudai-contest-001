// 自明解
// ステップ3に行かず、山を1つずつ崩す

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pll> vp;
typedef vector<ll> vll;

const int H = 3, W = 3;
int a[H][W];
vp ans;
vp t_ans;
bool done[H][W];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void addAns() {
    rep(i, t_ans.size()) {
        ans.emplace_back(t_ans[i]);
    }
}

void dfs(int x, int y) {

    rep(k, 4) {
        int nx = x + dx[k], ny = y + dy[k];
        if (inside(nx, ny) && a[nx][ny] == a[x][y] - 1) {
            t_ans.emplace_back(P(nx, ny));
            dfs(nx, ny);
            if (t_ans.size() > t_max) {
                addAns();
            }
            t_ans.pop_back();
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    rep(i, H) {
        rep(j, W) {
            cin >> a[i][j];
        }
    }

    rep(i, H) {
        rep(j, W) {
            dfs(i, j);
        }
    }
}
