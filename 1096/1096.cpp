//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1096 - nth Term
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

const long long Mod=10007;

struct Matrix
{
    int A[5][5];
    Matrix()
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                A[i][j]=0;
    }
    Matrix multi(Matrix &m)
    {
        Matrix res;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                {
                    res.A[i][j]+=((A[i][k]%Mod)*(m.A[k][j]%Mod))%Mod;
                    res.A[i][j]%=Mod;
                }
            }
        }
        return res;
    }
};

int tcs;
int n;
long l;
int a,b,c;

Matrix powMat(Matrix A,int i)
{
    if(i<=1)
        return A;
    
    Matrix tmp = powMat(A,i/2);
    tmp = tmp.multi(tmp);
    
    if(i%2)
        return tmp.multi(A);
    
    return tmp;
    
}

void solve()
{
    if(n<=2)
    {
        printf("0\n");
        return;
    }
    
    Matrix A;
        
    A.A[0][0]=0;A.A[0][1]=1;A.A[0][2]=0;A.A[0][3]=0;
    A.A[1][0]=0;A.A[1][1]=0;A.A[1][2]=1;A.A[1][3]=0;
    A.A[2][0]=b;A.A[2][1]=0;A.A[2][2]=a;A.A[2][3]=1;
    A.A[3][0]=0;A.A[3][1]=0;A.A[3][2]=0;A.A[3][3]=1;
    
    Matrix ans = powMat(A,n-2);
    
    printf("%d\n",((ans.A[2][3]%Mod)*(c%Mod))%Mod);
}

int main()
{
    //freopen("1096.INP","r",stdin);
    //freopen("1096.OUT","w",stdout);
    
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d: ",t);
        scanf(" %d %d %d %d ",&n,&a,&b,&c);
        
        solve();
    }
    return 0;
}
