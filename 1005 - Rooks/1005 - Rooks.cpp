//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1005 - Rooks
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

int tcs,n,k;
unsigned long long F[35][35];

void DP()
{
    for(int i = 1 ; i <= 30 ; i++)
        F[i][1] = i*i;
    for(int i = 0 ; i <= 30 ; i++)
        F[i][0] = 1;
    
    for(unsigned long long i = 2 ; i <= 30 ; i++)
        for(unsigned long long j = 2 ; j <= i ; j++)
            F[i][j] = F[i][1]*F[i-1][j-1]/j;
}

int main()
{
    freopen("1005 - Rooks.INP","r",stdin);
    freopen("1005 - Rooks.OUT","w",stdout);
    DP();
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        printf("Case %d: ",t);
        scanf(" %d %d ",&n,&k);
        if(k > n) printf("0\n");
        else cout << F[n][k] << endl;
    }
    return 0;
}
