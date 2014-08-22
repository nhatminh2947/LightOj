//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code:
// Verdict:
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int tcs,r,c,q;
char data[505][505];
bool vis[505][505];
queue< pair<int,int> > path;
int res[505][505];
int cnt;

int dx[]={-1, 0, 0, 1};
int dy[]={ 0,-1, 1, 0};

bool inside(int y,int x)
{
    return (1<=x && x<=c && 1<=y && y<=r);
}

void BFS(int y,int x)
{
    cnt=0;
    path.push(make_pair(y,x));
    queue< pair<int,int> > q;
    q.push(make_pair(y,x));
    vis[y][x]=true;
    if(data[y][x]=='C') cnt++;
    while(!q.empty())
    {
        int ty=q.front().first;
        int tx=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=tx+dx[i];
            int yy=ty+dy[i];
            if(inside(yy,xx) && !vis[yy][xx] && (data[yy][xx]=='.' || data[yy][xx]=='C'))
            {
                path.push(make_pair(yy,xx));
                vis[yy][xx]=true;
                if(data[yy][xx]=='C')
                    cnt++;
                q.push(make_pair(yy,xx));
            }
        }
    }
}

int main()
{
    //freopen("B.INP","r",stdin);
    //freopen("B.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d %d %d ",&r,&c,&q);
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                res[i][j]=0;
                vis[i][j]=false;
                scanf(" %c ",&data[i][j]);
            }
        
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                if(!vis[i][j] && data[i][j]!='#')
                {
                    BFS(i,j);
                    while(!path.empty())
                    {
                        res[path.front().first][path.front().second]=cnt;
                        path.pop();
                    }
                }
            }
        
        printf("Case %d:\n",t);
        
        for(int i=0;i<q;i++)
        {
            int y,x;
            scanf(" %d %d ",&y,&x);
            printf("%d\n",res[y][x]);
        }
    }
    return 0;
}
