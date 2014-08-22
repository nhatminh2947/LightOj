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
int n;
int data[105];


int main()
{
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        for(int i=1;i<=n;i++)
            scanf(" %d ",&data[i]);
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(data[i]!=i)
            {
                for(int j=n;j>i;j--)
                    if(data[j]==i)
                    {
                        swap(data[i],data[j]);
                        break;
                    }
                cnt++;
            }
        printf("Case %d: %d\n",t,cnt);
    }
    return 0;
}
