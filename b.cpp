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

const int H = 30, W = 30;
int a[H][W];
vp ans;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inside(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    rep(i, H) {
        rep(j, W) {
            cin >> a[i][j];
        }
    }

    rep(x, H) {
        rep(y, W) {
            while (a[x][y] > 0) {
                // ans.emplace_back(P(x, y));
                cout << x + 1 << " " << y + 1 << endl;
                a[x][y]--;
                if (a[x][y] == 0) break;
                rep(k, 4) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (inside(nx, ny) && a[nx][ny] == a[x][y]) {
                        // ans.emplace_back(P(nx, ny));
                        cout << nx + 1 << " " << ny + 1 << endl;
                        a[nx][ny]--;
                        break;
                    }
                }
            }
            // rep(i, H) {
            //     rep(j, W) {
            //         cout << a[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }
    }

    // rep(i, ans.size()) {
    //     cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    // }
}
