//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1139 - 8 Puzzle
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
//int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
//int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

int a[5][5];
int ans;

int numCorrect(int state[5][5])
{
    int res = 0;
    
    fr(i,1,3) fr(j,1,3)
    {
        int k = (i-1)*3 + j;
        res += (k%9 == state[i][j]);
    }
    
    return res;
}

bool inside(int y, int x)
{
    return (1 <= y && y <= 3 && 1 <= x && x <= 3);
}

void idaSearch(int step, int y, int x, int state[5][5])
{
    int k = numCorrect(state);
    
    if(k == 0)
    {
        ans = min(ans,step);
        return;
    }
    
    if(step >= ans) return;
    
    rep(i,4)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        if(inside(yy,xx))
        {
            swap(state[y][x],state[yy][xx]);
            idaSearch(step+1,yy,xx,state);
            swap(state[y][x],state[yy][xx]);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1139 - 8 Puzzle.INP","r",stdin);
    freopen("1139 - 8 Puzzle.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        int y,x;
        
        fr(i,1,3) fr(j,1,3)
        {
            read(a[i][j]);
            if(a[i][j] == 0)
            {
                y = i;
                x = j;
            }
        }
        
        ans = INF;
        
        idaSearch(0,y,x,a);
        
        printf("Case %d:",t);
        if(ans == INF) puts(" impossible");
        else printf(" %d\n",ans);
    }
    
    return 0;
}


