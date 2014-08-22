//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: B - Log Calculator
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

int main()
{
    //freopen("B.INP","r",stdin);
    //freopen("B.OUT","w",stdout);
    double a,b;
    while(scanf(" %lf %lf ",&a,&b)==2)
    {
        double ans=log(a)/log(b);
        printf("%.4lf\n",ans);
    }
    return 0;
}
