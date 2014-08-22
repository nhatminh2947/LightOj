//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1147 - Tug of War
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

int tcs,n;
int dp[105][105];
int a[105];
bool vis[105];

int solve(int id, int u)
{
    if(id == (n+1)/2)
        return a[u];
    
    if(dp[id][u] != 1) return dp[id][u];
    int ans = 0;
    fr(i,1,n)
    {
        if(!vis[i])
        {
            vis[i] = true;
            int tmp = solve(id+1,i) + a[id];
            if(tmp < 
            vis[i] = false;
        }
    }
    
    return dp[id][u] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1147 - Tug of War.INP","r",stdin);
    freopen("1147 - Tug of War.OUT","w",stdout);
    #endif
    
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        
        fr(i,1,n) scanf(" %d ",&a[i]);
        
        fr(i,0,n) fr(j,0,n) dp[i][j] = -1;
        fr(i,0,n) vis[i] = false;
        
        
    }
    
    return 0;
}
