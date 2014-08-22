//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1031 - Easy Game
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
#define maxN 100

int n;
int a[maxN+5];
int dp[5][maxN+5][maxN+5];
int sum[maxN+5][maxN+5];

int solve(int i, int lf, int rg)
{
    if(lf > rg) return 0;
    if(dp[i][lf][rg] != INF) return dp[i][lf][rg];
    
    int ans;
    if(i == 0)
    {
        ans = -INF;
        for(int k = lf ; k <= rg ; k++)
        {
            printf("i = %d lf = %d rg = %d ----> ",i,lf,rg);
            printf("i = %d lf = %d rg = %d\n",1-i,k+1,rg);
            ans = max(ans,sum[lf][k] - solve(1-i,k+1,rg));
        }
        //DEBUG(ans);
        for(int k = rg ; k >= lf ; k--)
        {
            printf("i = %d lf = %d rg = %d ----> ",i,lf,rg);
            printf("i = %d lf = %d rg = %d\n",1-i,lf,k-1);
            ans = max(ans,sum[k][rg] - solve(1-i,lf,k-1));
        }
        //DEBUG(ans);
    }
    else
    {
        ans = INF;
        for(int k = lf ; k <= rg ; k++)
        {
            printf("i = %d lf = %d rg = %d ----> ",i,lf,rg);
            printf("i = %d lf = %d rg = %d\n",1-i,lf,k-1);
            ans = min(ans,sum[lf][k] + solve(1-i,k+1,rg));
        }
        //DEBUG(ans);
        for(int k = rg ; k >= lf ; k--)
        {
            printf("i = %d lf = %d rg = %d ----> ",i,lf,rg);
            printf("i = %d lf = %d rg = %d\n",1-i,lf,k-1);
            ans = min(ans,sum[k][rg] + solve(1-i,lf,k-1));
        }
        //DEBUG(ans);
    }
    DEBUG(ans);
    return dp[i][lf][rg] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1031 - Easy Game.INP","r",stdin);
    freopen("1031 - Easy Game.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        
        fr(i,1,n) scanf(" %d ",&a[i]);
        
        int ans = solve(0,1,n);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
