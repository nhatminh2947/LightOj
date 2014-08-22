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
double x,y;

int main()
{
    freopen("D.INP","r",stdin);
    freopen("D.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d: ",t);
        scanf(" %lf : %lf ",&x,&y);
        double k=x/y;
        
        double d=atan2(x,y)*180/PI;
        double n=180-2*d;
        
        double a = 200 / ((n*PI*sqrt(1+1/((x*x)/(y*y))))/180+1);
        
        cout<<a<<endl;
    }
    return 0;
}
