//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: B - Meeting the Red Queen
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
#define maxN 123456
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

using namespace std;

typedef struct
{
    int x,y;
}coor;

coor A,Q;
int tcs;
int R,C;
char data[20][20];

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};

bool inside(coor tmp)
{
    return (1 <= tmp.x && tmp.x <= C && 1 <= tmp.y && tmp.y <= R);
}

int BFS()
{
    queue< pair<int, pair<coor,coor> > > q;
    
    q.push(mp(0,mp(A,Q)));
    
    while(!q.empty())
    {
        int cnt = q.front().ff;
        coor a = q.front().ss.ff;
        coor b = q.front().ss.ss;
        
        data[b.y][b.x] = '.';
        if(a.x == b.x && a.y == b.y)
            return cnt;
        
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++)
        {
            coor tmp1,tmp2;
            tmp1.x = a.x + dx[i];
            tmp1.y = a.y + dy[i];
            
            if(tmp1.x == b.x && tmp1.y == b.y)
                return cnt;
            
            if(i % 2 == 0)
            {
                tmp2.x = b.x + dx[i+1];
                tmp2.y = b.y + dy[i+1];
            }
            else
            {
                tmp2.x = b.x + dx[i-1];
                tmp2.y = b.y + dy[i-1];
            }
            
            if(inside(tmp1) && data[tmp1.y][tmp1.x] == '.')
            {
                data[tmp1.y][tmp1.x] = 'A';
                if(data[tmp2.y][tmp2.x] == '.' && inside(tmp2))
                {
                    data[tmp2.y][tmp2.x] = 'Q';
                    q.push(mp(cnt+1,mp(tmp1,tmp2)));
                }
                else
                    q.push(mp(cnt+1,mp(tmp1,b)));
                
                //for(int r = 1; r <= R ; r++)
//                {
//                    for(int c = 1 ; c <= C ; c++)
//                        printf("%c",data[r][c]);
//                    printf("\n");
//                }
//                printf("\n");
            }
        }
    }
    return -1;
}

int main()
{
    freopen("B - Meeting the Red Queen.INP","r",stdin);
    freopen("B - Meeting the Red Queen.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d %d ",&R,&C);
        for(int r = 1; r <= R ; r++)
            for(int c = 1 ; c <= C ; c++)
            {
                scanf(" %c ",&data[r][c]);
                if(data[r][c] == 'A')
                {
                    A.y = r;
                    A.x = c;
                }
                if(data[r][c] == 'Q')
                {
                    Q.y = r;
                    Q.x = c;
                }
            }
        int res = BFS();
        printf("Case %d: ",t);
        if(res == -1) printf("impossible\n");
        else printf("%d\n",res);
    }
    return 0;
}
