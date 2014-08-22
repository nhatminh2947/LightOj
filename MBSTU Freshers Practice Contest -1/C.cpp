//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: C - Problem in Triangle
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

double dist(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    freopen("C.INP","r",stdin);
    freopen("C.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        int x1,x2,x3,y1,y2,y3;
        scanf(" %d %d %d %d %d %d ",&x1,&y1,&x2,&y2,&x3,&y3);
        double a=dist(x1,y1,x2,y2);
        double b=dist(x1,y1,x3,y3);
        double c=dist(x3,y3,x2,y2);
        if(((a+b)>c) && ((b+c)>a) && ((a+c)>b))
        {
            double p=a+b+c;
            p/=2;
            double s=sqrt(p*(p-a)*(p-b)*(p-c));
            printf("Area for Data Set #%d is %.2lf\n",t,s);
        }
        else printf("Data Set #%d: Not Valid\n",t);
    }
    return 0;
}
