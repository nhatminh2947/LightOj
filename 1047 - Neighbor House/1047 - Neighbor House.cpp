//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1047 - Neighbor House
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

int data[5][25];
int tcs,n;

int main()
{
    //freopen("1047 - Neighbor House.INP","r",stdin);
    //freopen("1047 - Neighbor House.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        
        for(int j = 0 ; j < n ; j++)
            for(int i = 0 ; i < 3 ; i++)
                scanf(" %d ",&data[i][j]);
        
        int m = INF;
        
        for(int j = 1 ; j < n ; j++)
            for(int i = 0 ; i < 3 ; i++)
                data[i][j] += min(data[(i+1)%3][j-1],data[(i+2)%3][j-1]);
        
        for(int i = 0 ; i < 3 ; i++)
            m = min(m,data[i][n-1]);
        
        printf("Case %d: %d\n",t,m);
    }
    return 0;
}
