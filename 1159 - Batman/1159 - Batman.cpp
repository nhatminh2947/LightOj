//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1159 - Batman
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

int dp[55][55][55];
int n,m,o;
char a[55],b[55],c[55];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1159 - Batman.INP","r",stdin);
    freopen("1159 - Batman.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        getchar();
        
        gets(a+1);
        gets(b+1);
        gets(c+1);
        
        n = strlen(a+1);
        m = strlen(b+1);
        o = strlen(c+1);
        
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
                for(int k = 1 ; k <= o ; k++)
                {
                    if(a[i] == b[j] && b[j] == c[k])
                    {
                        dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                    }
                    else dp[i][j][k] =  max(dp[i-1][ j ][ k ],
                                        max(dp[i-1][j-1][ k ],
                                        max(dp[i-1][ j ][k-1],
                                        max(dp[ i ][j-1][ k ],
                                        max(dp[ i ][j-1][k-1],dp[ i ][ j ][k-1])))));
                }
        
        printf("Case %d: %d\n",t,dp[n][m][o]);
    }
    
    return 0;
}
