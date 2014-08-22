//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: A - The Rolling Boulder
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

double I,E,V,A;
int tcs;

int main()
{
    freopen("A - The Rolling Boulder.INP","r",stdin);
    freopen("A - The Rolling Boulder.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        scanf(" %lf %lf %lf %lf ",&I,&E,&V,&A);
        double t1=(E-I)/V;
        double t2=sqrt(E*2/A);
        double t=t2-t1;
        if(t>=0) printf("Case %d: Indy escapes by %.1lf s\n",i,t);
        else printf("Case %d: Indy can't escape\n",i);
    }
    return 0;
}
