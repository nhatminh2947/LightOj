//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1143 - Knights in FEN
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

//8 huong
//int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

//horse
int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

//int dx[] = {-1, 0, 0, 1};
//int dy[] = { 0,-1, 1, 0};

const char d[10][10] =
{
    {'1','1','1','1','1'},
    {'0','1','1','1','1'},
    {'0','0',' ','1','1'},
    {'0','0','0','0','1'},
    {'0','0','0','0','0'}
};

struct chess
{
    char a[10][10];
    
    chess(){};
    
    int difHorse()
    {
        int dif = 0;
    
        rep(i,5) rep(j,5) dif += (a[i][j] != d[i][j]);
        
        return dif/2;
    }
    
    bool operator < (const chess k) const
    {
        rep(i,5) rep(j,5) if(a[i][j] != k.a[i][j]) return a[i][j] < k.a[i][j];
        return false;
    }
};

chess a;
int lim;
map<chess,int> vis;
bool ok;

bool inside(int y, int x)
{
    return (0 <= y && y < 5 && 0 <= x && x < 5);
}

void idaSearch(int step, int y, int x, chess state)
{
    int dif = state.difHorse();
    
    if(dif == 0)
    {
        lim = min(lim,step);
        ok = true;
        return;
    }
    
    if(step + dif >= lim) return;
    
    rep(i,8)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        if(inside(yy,xx))
        {
            swap(state.a[yy][xx],state.a[y][x]);
            if(state.difHorse() <= dif)
                idaSearch(step+1,yy,xx,state);
            swap(state.a[yy][xx],state.a[y][x]);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1143 - Knights in FEN.INP","r",stdin);
    freopen("1143 - Knights in FEN.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    getchar();
    
    fr(t,1,tcs)
    {
        vis.clear();
        int y,x;
        
        rep(i,5)
        {
            gets(a.a[i]);
            rep(j,5) if(a.a[i][j] == ' ')
            {
                y = i;
                x = j;
            }
        }
        
        lim = 15;
        ok = false;
        idaSearch(0,y,x,a);
        
        printf("Case %d:",t);
        if(!ok) puts(" Unsolvable in less than 16 move(s).");
        else printf(" Solvable in %d move(s).\n",lim);
    }
    
    return 0;
}

