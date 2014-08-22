//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: C - Juice in the Glass
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

int tcs;

int main()
{
    //freopen("C.INP","r",stdin);
    //freopen("C.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d: ",t);
        double r1,r2,h,p;
        scanf(" %lf %lf %lf %lf ",&r1,&r2,&h,&p);
        
        double R = ( -(h*r1-p*r1+p*r2) + sqrt( (h*r1-p*r1+p*r2)*(h*r1-p*r1+p*r2) + 4*h*(p*r1*r1 + h*r2*r2 + h*r1*r2 - p*r2*r2) ) ) / (2*h);
        
        double S = (PI * p * (r2*r2 + R*R + r2*R)) / 3;
        
        printf("%.7lf\n",S);
        
    }
    return 0;
}
