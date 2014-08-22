//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: K - Waking
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

int F[305][305];
int m,n;
char s1[305],s2[305];

void DP()
{
    m = strlen(s1);
    n = strlen(s2);
    for(int i = 0 ; i <= n ; i++)
        F[i][0] = i;
    for(int j = 0 ; j <= m ; j++)
        F[0][j] = j;
        
    for(int i = 1 ; i <= m ; i++)
        for(int j = 1 ; j <= n ; j++)
        {
            if(s1[i-1] == s2[j-1]) F[i][j] = F[i-1][j-1];
            else F[i][j] = min(F[i][j-1],F[i-1][j]) + 1;
        }
    
    printf("%d\n",F[m][n]);
}

int main()
{
    //freopen("K - Waking.INP","r",stdin);
    //freopen("K - Waking.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %s %s ",&s1,&s2);
        
        printf("Case %d: ",t);
        DP();
    }
    return 0;
}
