//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1169 - Monkeys on Twin Tower
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
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 123456
#define INF 1000111222

using namespace std;

int towel[5][1005];
int jump[5][1005];
int F[5][1005];
int tcs,n;

int main()
{
    //freopen("1169 - Monkeys on Twin Tower.INP","r",stdin);
    //freopen("1169 - Monkeys on Twin Tower.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        for(int i = 0 ; i < 2 ; i++)
            for(int j = 1 ; j <= n ; j++)
                scanf(" %d ",&towel[i][j]);
        
        for(int i = 0 ; i < 2 ; i++)
            for(int j = 1 ; j <= n-1 ; j++)
                scanf(" %d ",&jump[i][j]);
        
        F[0][1] = towel[0][1];
        F[1][1] = towel[1][1];
        
        for(int j = 2 ; j <= n ; j++)
        {
            F[0][j] = min((F[0][j-1] + towel[0][j]),(F[1][j-1] + jump[1][j-1] + towel[0][j]));
            F[1][j] = min((F[1][j-1] + towel[1][j]),(F[0][j-1] + jump[0][j-1] + towel[1][j]));
        }
        
        int ans = min(F[0][n],F[1][n]);
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
