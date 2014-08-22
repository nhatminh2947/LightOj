//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1337 - The Crystal Maze
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) (int)s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

char a[505][505];
int vis[505][505];
int ans[250005];
int n,m,q;

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};

inline bool inside(int y, int x)
{
    return (1 <= y && y <= n && 1 <= x && x <= m);
}

inline void BFS(int k, int r, int c)
{
    queue<ii> q;
    q.push(mp(r,c));
    vis[r][c] = k;
    while(!q.empty())
    {
        int y = q.front().ff;
        int x = q.front().ss;
        //printf("y = %d x = %d\n",y,x);
        ans[k] += a[y][x] == 'C';
        q.pop();
        
        rep(i,4)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if(inside(yy,xx) && vis[yy][xx] == 0 && a[yy][xx] != '#')
            {
                vis[yy][xx] = k;
                q.push(mp(yy,xx));
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1337 - The Crystal Maze.INP","r",stdin);
    freopen("1337 - The Crystal Maze.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    fr(t,1,tcs)
    {
        scanf(" %d %d %d ",&n,&m,&q);
        
        fr(i,1,n)
        {
            gets(a[i]+1);
            fr(j,1,m) vis[i][j] = 0;
        }
        
        ans[0] = 0;
        int cnt = 0;
        fr(i,1,n)
            fr(j,1,m)
            {
                if(vis[i][j] == 0 && a[i][j] != '#')
                {
                    cnt++;
                    ans[cnt] = 0;
                    BFS(cnt,i,j);
                }
            }
        
        printf("Case %d:\n",t);
        rep(i,q)
        {
            int y,x;
            scanf(" %d %d ",&y,&x);
            
            printf("%d\n",ans[vis[y][x]]);
        }
    }
    
    return 0;
}
