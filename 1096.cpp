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

int tcs;
int a,b,c;
int n;
long long A[10][10];
long long M[10][10];

void mul(long long res[10][10],long long a[10][10],long long b[10][10])
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            res[i][j]=0;
            for(int k=0;k<4;k++)
                res[i][j]+=a[i][k]*b[k][j];
        }
}

void mul_M(long long M[10][10],int n)
{
    long long N[10][10];
    if(n<=2) return;
    if(n%2==0)
    {
        mul_M(M,n/2);
        mul(N,M,M);
        
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                M[i][j]=N[i][j];
    }
    else
    {
        mul_M(M,n-1);
        mul(N,M,A);
        
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                M[i][j]=N[i][j];
    }
}

int main()
{
    freopen("1096.INP","r",stdin);
    freopen("1096.OUT","w",stdout);
    
    A[0][1]=0;A[0][2]=1;A[0][3]=0;A[0][4]=0;
    A[1][1]=0;A[1][2]=0;A[1][3]=1;A[1][4]=0;
    A[2][1]=b;A[2][2]=0;A[2][3]=a;A[2][4]=1;
    A[3][1]=0;A[3][2]=0;A[3][3]=0;A[3][4]=1;
    
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d %d %d ",&a,&b,&c);
        
        long long res[10][10];
        res[0][1]=0;res[0][2]=1;res[0][3]=0;res[0][4]=0;
        res[1][1]=0;res[1][2]=0;res[1][3]=1;res[1][4]=0;
        res[2][1]=b;res[2][2]=0;res[2][3]=a;res[2][4]=1;
        res[3][1]=0;res[3][2]=0;res[3][3]=0;res[3][4]=1;
        
        mul_M(res,n);
        
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
                printf("%d ",res[i][j]);
            printf("\n");
        }
        
    }
    return 0;
}
