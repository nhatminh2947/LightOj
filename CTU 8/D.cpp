//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: D
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

typedef struct int matrix[5][5];

matrix A;

matrix F(int n)
{
    matrix M[5][5];
    
    if(n%2==0)
    {
        M=F(n/2);
        return M;
    }
    if(n%==1)
    {
        M=F(n-1);
    }
}

int main()
{
    freopen("D.INP","r",stdin);
    freopen("D.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        int n,a,b,c;
        scanf(" %d %d %d %d ",&n,&a,&b,&c);
        
        A[1][1]=0;A[1][2]=1;A[1][3]=0;A[1][4]=0;
        A[2][1]=0;A[2][2]=0;A[2][3]=1;A[2][4]=0;
        A[3][1]=b;A[3][2]=a;A[3][3]=0;A[3][4]=c;
        
        
    }
    return 0;
}
