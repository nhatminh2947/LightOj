//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: G - The Lion and the Unicorn
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
#define maxN 123456
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

using namespace std;

int main()
{
    //freopen("G - The Lion and the Unicorn.INP","r",stdin);
    //freopen("G - The Lion and the Unicorn.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        printf("Case %d: ",t);
        double r,h;
        scanf(" %lf %lf ",&r,&h);
        
        double V = PI * r * r * h;
        printf("%.2lf %.2lf\n",2*V/3,V/3);
    }
    return 0;
}
