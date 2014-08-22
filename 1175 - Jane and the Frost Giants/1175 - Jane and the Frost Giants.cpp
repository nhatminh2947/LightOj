//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1175 - Jane and the Frost Giants
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

char a[205][205];
int step[5][205][205];
int n,m;
queue<ii> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};

inline bool inside(int y, int x)
{
    return (1 <= y && y <= n && 1 <= x && x <= m);
}

inline void BFS(int k)
{
    while(!q.empty())
    {
        int y = q.front().ff;
        int x = q.front().ss;
        
        q.pop();
        
        rep(i,4)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if(inside(yy,xx) && step[k][yy][xx] == INF && a[yy][xx] == '.')
            {
                step[k][yy][xx] = step[k][y][x] + 1;
                q.push(mp(yy,xx));
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1175 - Jane and the Frost Giants.INP","r",stdin);
    freopen("1175 - Jane and the Frost Giants.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&n,&m);
        
        while(!q.empty()) q.pop();
        
        fr(i,1,n) gets(a[i]+1);
        
        fr(i,1,n)
            fr(j,1,m)
            {
                step[1][i][j] = INF;
                if(a[i][j] == 'J')
                {
                    q.push(mp(i,j));
                    step[1][i][j] = 0;
                }
            }
        
        BFS(1);
        while(!q.empty()) q.pop();
        fr(i,1,n)
            fr(j,1,m)
            {
                step[2][i][j] = INF;
                if(a[i][j] == 'F')
                {
                    q.push(mp(i,j));
                    step[2][i][j] = 0;
                }
            }
        BFS(2);
        
        int ans = INF;
        for(int i = 1 ; i <= n ; i++)
        {
            if(step[1][i][1] < step[2][i][1])
                ans = min(ans,step[1][i][1]);
            if(step[1][i][m] < step[2][i][m])
                ans = min(ans,step[1][i][m]);
        }
        
        for(int j = 1 ; j <= m ; j++)
        {
            if(step[1][1][j] < step[2][1][j])
                ans = min(ans,step[1][1][j]);
            if(step[1][n][j] < step[2][n][j])
                ans = min(ans,step[1][n][j]);
        }
            
        printf("Case %d: ",t);
        if(ans == INF) puts("IMPOSSIBLE");
        else printf("%d\n",ans+1);
    }
    
    return 0;
}
