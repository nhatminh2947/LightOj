//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1057 - Collecting Gold
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

char a[21][21];
int dp[20][40000];
int dist[21][21];

int mask;
int n,m,tcs,g;
int x,y;
vii v;

int solve(int pos, int st)
{
    if(st == mask-1)
    {
        int delX = abs(v[pos].ff - y);
        int delY = abs(v[pos].ss - x);
                
        int cross = min(delX,delY);
        int d = cross + abs(delX - cross) + abs(delY - cross);
        
        return d;
    }
    
    if(dp[pos][st] != -1) return dp[pos][st];
    
    int ans = INF;
    for(int i = 0 ; i < g ; i++)
    {
        int k = 1 << i;
        if(k & st) continue;
        ans = min(ans, dist[pos][i] + solve(i, k | st));
    }
    
    return dp[pos][st] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1057 - Collecting Gold.INP","r",stdin);
    freopen("1057 - Collecting Gold.OUT","w",stdout);
    #endif
    
    scanf(" %d ",&tcs);
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&n,&m);
        
        fr(i,1,n) gets(a[i]+1);
        
        v.clear();
        g = 0;
        fr(i,1,n)
            fr(j,1,m)
            {
                if(a[i][j] == 'x')
                {
                    y = i;
                    x = j;
                }
                else if(a[i][j] == 'g')
                {
                    v.pb(mp(i,j));
                    g++;
                }
            }
        
        mask = 1 << g;
        
        rep(i,g)
            rep(j,mask)
                dp[i][j] = -1;
        
        rep(i,sz(v))
            for(int j = i+1 ; j < sz(v) ; j++)
            {
                int delX = abs(v[i].ff - v[j].ff);
                int delY = abs(v[i].ss - v[j].ss);
                
                int cross = min(delX,delY);
                dist[i][j] = dist[j][i] = cross + abs(delX - cross) + abs(delY - cross);
                //DEBUG(dist[i][j]);
            }
            
        int ans = INF;
        for(int i = 0 ; i < g ; i++)
        {
            int delX = abs(v[i].ff - y);
            int delY = abs(v[i].ss - x);
                
            int cross = min(delX,delY);
            int d = cross + abs(delX - cross) + abs(delY - cross);
            
            ans = min(ans,d + solve(i, 1<<i));
        }
        
        if(ans == INF) ans = 0;
        printf("Case %d: %d\n",t,ans);
        
    }
    
    return 0;
}
