//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code:
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int tcs,n;
int data[205][205];

void DP()
{
    int k=n*2-1;
    int i;
    for(i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int tmp=data[i][j];
            if(j!=i && data[i][j]<data[i-1][j]+tmp)
                data[i][j]=data[i-1][j]+tmp;
            if((j-1)!=0 && data[i][j]<data[i-1][j-1]+tmp)
                data[i][j]=data[i-1][j-1]+tmp;
        }
    }
    for(i;i<=k;i++)
    {
        for(int j=1;j<=k-i+1;j++)
        {
            int tmp=data[i][j];
            if(data[i][j]<data[i-1][j]+tmp)
                data[i][j]=data[i-1][j]+tmp;
            if(data[i][j]<data[i-1][j+1]+tmp)
                data[i][j]=data[i-1][j+1]+tmp;
        }
    }
    
}

int main()
{
    //freopen("C.INP","r",stdin);
    //freopen("C.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        int i;
        for(i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                scanf(" %d ",&data[i][j]);
        int k=2*n-1;
        for(i;i<=k;i++)
            for(int j=1;j<=k-i+1;j++)
                scanf(" %d ",&data[i][j]);
        DP();
        printf("Case %d: %d\n",t,data[k][1]);
    }
    return 0;
}
