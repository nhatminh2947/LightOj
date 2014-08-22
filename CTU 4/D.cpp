//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: D - Calm Down
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
double R,n;

int main()
{
    //freopen("D.INP","r",stdin);
    //freopen("D.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %lf %lf ",&R,&n);
        
        if(n==2)
        {
            printf("Case %d: %.7lf\n",t,R/2);
            continue;
        }
        
        double A=2*PI/n;
        
        double B=(PI-A)/2;
        
        double BC,AB,AC;
        
        AB=AC=R/sin(B);
        
        BC=2*cos(B)*AB;
        
        //cout<<AB<<" "<<AC<<" "<<BC<<endl;
        
        double S=R*BC/2;
        
        double r = 2*S/(AB+AC+BC);
        
        printf("Case %d: %.7lf\n",t,r);
    }
    return 0;
}
