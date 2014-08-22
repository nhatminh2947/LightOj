//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: A - Bishops 
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
int r1,r2,c1,c2;

int main()
{
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d %d %d %d ",&r1,&c1,&r2,&c2);
        printf("Case %d: ",t);
        if(r1%2 == c1%2)
        {
            if(r2%2 == c2%2)
            {
                if(abs(r1-r2) == abs(c1-c2))
                    printf("1\n");
                else printf("2\n");
            }
            else printf("impossible\n");
        }
        else
        {
            if(r2%2 != c2%2)
            {
                if(abs(r1-r2) == abs(c1-c2))
                    printf("1\n");
                else printf("2\n");
            }
            else printf("impossible\n");
        }
    }
    return 0;
}
