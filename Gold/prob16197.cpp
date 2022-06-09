#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int n,m;
char board[20][20];
char chk0[20][20];
char chk1[20][20];
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
vector<pair<int, int>> coin;
int ans = 11;
void dfs(int cnt, int c0x, int c0y, int c1x, int c1y){
    if(cnt > 10)
        return;
    for(int i=0;i<4;i++){
        bool c0fall = false;
        bool c1fall = false;
        int nc0x = c0x + dx[i]; int nc0y = c0y + dy[i];
        int nc1x = c1x + dx[i]; int nc1y = c1y + dy[i];
        if(nc0x < 0 || nc0x >= n || nc0y < 0 || nc0y >= m)
            c0fall = true;
        if(nc1x < 0 || nc1x >= n || nc1y < 0 || nc1y >= m)
            c1fall = true;
        if(c0fall && c1fall) // 둘 다 떨어짐
            continue;
        if(!c0fall && !c1fall){ // 둘 다 안떨어짐
            bool c0wall = false;
            bool c1wall = false;
            if(board[nc0x][nc0y] == '#')
                c0wall = true;
            if(board[nc1x][nc1y] == '#')
                c1wall = true;
            if(c0wall && c1wall) // 둘 다 가려는 곳이 벽임
                continue;
            if(c0wall){
                nc0x = c0x;
                nc0y = c0y;
            }
            if(c1wall){
                nc1x = c1x;
                nc1y = c1y;
            }
            dfs(cnt+1, nc0x, nc0y, nc1x, nc1y);
        } else {
            ans = min(ans, cnt+1);
            return;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 'o'){
                coin.push_back(make_pair(i,j));
            }
        }
    }
    
    dfs(0, coin[0].first, coin[0].second, coin[1].first, coin[1].second);   
    
    if(ans == 11)
        cout << -1;
    else
        cout << ans;
    return 0;
}