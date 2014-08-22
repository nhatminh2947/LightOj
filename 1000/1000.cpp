//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 1000 - Greetings from LightOJ
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

int tcs,a,b;

int main()
{
    //freopen("1000.INP","r",stdin);
    //freopen("1000.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        scanf(" %d %d ",&a,&b);
        printf("Case %d: %d\n",i,a+b);
    }
    return 0;
}
