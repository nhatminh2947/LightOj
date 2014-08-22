//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1115 - Filling the Regions
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

//8 huong
//int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

//horse
//int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
//int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

const int dx[] = {-1, 0, 0, 1};
const int dy[] = { 0,-1, 1, 0};

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

char a[55][55], ans[55][55];
int cnt[55][55], outSide[55][55];
int n,m;
bool vis[55][55], ok[300];

bool inside(int y, int x)
{
    return (1 <= y && y <= n && 1 <= x && x <= m);
}

bool inside1(int y, int x)
{
    return (0 <= y && y <= n+1 && 0 <= x && x <= m+1);
}

void DFS_outSide(int y, int x)
{
    if(outSide[y][x]) return;
    if(a[y][x] == '.') outSide[y][x] = '.';
    else outSide[y][x] = a[y][x];
    
    rep(i,4)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(inside1(yy,xx) && !outSide[yy][xx] && (a[yy][xx] == a[y][x] || (a[y][x] == '.' && a[yy][xx] != '.')))
            DFS_outSide(yy,xx);
    }
}

void DFS(int y, int x, char c)
{
    if(vis[y][x]) return;
    vis[y][x] = true;
    ans[y][x] = c;
    cnt[y][x]++;
    
    rep(i,4)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        if(inside(yy,xx) && !vis[yy][xx] && ((!outSide[yy][xx] && a[yy][xx] != c) || a[yy][xx] == c))
        {
            DFS(yy,xx,c);
        }
    }
}

void init()
{
    fr(i,0,n+1) a[i][0] = a[i][m+1] = '.';
    fr(j,0,m+1) a[0][j] = a[n+1][j] = '.';
    fr(i,0,n+1) fr(j,0,m+1) outSide[i][j] = false, cnt[i][j] = 0;
    fr(i,'A','Z') ok[i] = false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1115 - Filling the Regions.INP","r",stdin);
    freopen("1115 - Filling the Regions.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        read2(n,m);
        
        init();
        
        fr(i,1,n) fr(j,1,m)
        {
            read(a[i][j]);
            ans[i][j] = '.';
        }
        
        DFS_outSide(0,0);
        
        fr(i,1,n) fr(j,1,m)
        {
            if('A' <= outSide[i][j] && outSide[i][j] <= 'Z' && !ok[a[i][j]])
            {
                ok[a[i][j]] = true;
                fr(u,1,n) fr(v,1,n) vis[u][v] = false;
                
                DFS(i,j,a[i][j]);
            }
        }
        
        printf("Case %d:\n",t);
        fr(i,1,n)
        {
            fr(j,1,n)
            {
                if(outSide[i][j]) printf("%c",a[i][j]);
                else if(cnt[i][j] == 1) printf("%c",ans[i][j]);
                else printf(".");
            }
            puts("");
        }
    }
    
    return 0;
}

