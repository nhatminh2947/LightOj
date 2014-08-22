//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1004 - Monkey Banana Problem
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
#include <cctype>
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

int data[300][300];
int tcs,n;

int main()
{
    freopen("1004 - Monkey Banana Problem.INP","r",stdin);
    freopen("1004 - Monkey Banana Problem.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        
        for(int i = 0 ; i <= 2*n ; i++)
            for(int j = 0 ; j <= 2*n ; j++)
                data[i][j] = 0;
        
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= i ; j++)
                scanf(" %d ",&data[i][j]);
        
        for(int i = n+1 ; i <= 2*n-1 ; i++)
            for(int j = 1 ; j <= 2*n-i ; j++)
                scanf(" %d ",&data[i][j]);
        
        for(int i = 2 ; i <= n ; i++)
            for(int j = 1 ; j <= i ; j++)
                data[i][j] = max(data[i-1][j],data[i-1][j-1]) + data[i][j];
        
        for(int i = n+1 ; i <= 2*n-1 ; i++)
            for(int j = 1 ; j <= 2*n-i ; j++)
                data[i][j] = max(data[i-1][j],data[i-1][j+1]) + data[i][j];
            
        printf("Case %d: %d\n",t,data[2*n-1][1]);
    }
    return 0;
}
