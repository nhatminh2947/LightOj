//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1110 - An Easy LCS
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
 
int tcs;
char a[105],b[105];
int dp[105][105];
string s[105][105];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1110 - An Easy LCS.INP","r",stdin);
    freopen("1110 - An Easy LCS.OUT","w",stdout);
    #endif
   
    scanf(" %d",&tcs);
    getchar();
    
    fr(t,1,tcs)
    {
        getchar();
        
        gets(a+1);
        gets(b+1);
       
        int n = strlen(a+1);
        int m = strlen(b+1);
        
        fr(i,0,n) s[i][0] = "";
        fr(j,0,m) s[0][j] = "";
        
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
            {
                if(a[i] == b[j])                        s[i][j] = s[i-1][j-1] + a[i];
                else if(sz(s[i-1][j]) > sz(s[i][j-1]))  s[i][j] = s[i-1][j];
                else if(sz(s[i-1][j]) < sz(s[i][j-1]))  s[i][j] = s[i][j-1];
                else                                    s[i][j] = min(s[i-1][j],s[i][j-1]);
            }
        
        printf("Case %d: ",t);
        if(!sz(s[n][m])) printf(":("); 
        else cout << s[n][m];
        puts("");
    }
   
    return 0;
}
