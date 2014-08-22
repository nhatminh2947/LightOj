//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: C - The Staff of Ra
// Verdict: Accepted
//******************************************************************
#include <iostream>
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
#define INF 999999999
#define PI 3,1415926535

using namespace std;

typedef struct
{
    int a,b;
}frac;

int a,b,s1,s2;
int tcs;
frac x,y,z;


int UCLN(int a,int b)
{
    if (a == b) return a;
    return (a > b) ? UCLN(a - b, b) : UCLN(b - a,a);
}

int main()
{
    //freopen("C - The Staff of Ra.INP","r",stdin);
    //freopen("C - The Staff of Ra.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        scanf(" %d %d %d %d ",&a,&b,&s1,&s2);
        x.a=s1*b;
        x.b=a-s1;
        int tmp=UCLN(x.a,x.b);
        x.a/=tmp;
        x.b/=tmp;
        
        y.a=s2*b;
        y.b=a-s2;
        tmp=UCLN(y.a,y.b);
        y.a/=tmp;
        y.b/=tmp;
        
        z.a=abs(x.a*y.b-y.a*x.b);
        z.b=x.b*y.b;
        tmp=UCLN(z.a,z.b);
        z.a/=tmp;
        z.b/=tmp;
        
        printf("Case %d: %d/%d\n",i,z.a,z.b);
    }
    return 0;
}
