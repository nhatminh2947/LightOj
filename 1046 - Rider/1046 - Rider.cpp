//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1046 - Rider
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

char a[15][15];
int n,m;
int step[15][15];
int knight[15][15];
int total[15][15];

int dx[] = { 1, 1, 2, 2,-1,-1,-2,-2};
int dy[] = { 2,-2, 1,-1, 2,-2, 1,-1};

bool inside(int y, int x)
{
    return (1 <= y && y <= n && 1 <= x && x <= m);
}

void BFS(int k, int r, int c)
{
    fr(i,1,n)
        fr(j,1,m)
            step[i][j] = -1;
    
    queue<ii> q;
    q.push(mp(r,c));
    step[r][c] = 0;
    
    while(!q.empty())
    {
        int y = q.front().ff;
        int x = q.front().ss;
        
        knight[y][x]++;
        total[y][x] += ((step[y][x] + k - 1) / k);
        
        q.pop();
        
        rep(i,8)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if(inside(yy,xx) && step[yy][xx] == -1)
            {
                step[yy][xx] = step[y][x] + 1;
                q.push(mp(yy,xx));
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1046 - Rider.INP","r",stdin);
    freopen("1046 - Rider.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&n,&m);
        
        fr(i,1,n) gets(a[i]+1);
        
        int cnt = 0;
        fr(i,1,n)
            fr(j,1,m)
                total[i][j] = knight[i][j] = 0;
        
        fr(i,1,n)
            fr(j,1,m)
                if(a[i][j] != '.')
                {
                    cnt++;
                    BFS(a[i][j] - '0',i,j);
                }
        
        int ans = INF;
        fr(i,1,n)
            fr(j,1,m)
                if(knight[i][j] == cnt)
                    ans = min(ans,total[i][j]);
        
        if(ans == INF) ans = -1;
        printf("Case %d: %d\n",t,ans);
    }
    
    return 0;
}
