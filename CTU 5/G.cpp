//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: G - Secret Origins
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

int main()
{
    freopen("G.INP","r",stdin);
    freopen("G.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        int a;
        deque<int> tmp;
        scanf(" %d ",&a);
        int cnt=0;
        while(a)
        {
            int k=a%2;
            if(k==1) cnt++;
            tmp.push_front(k);
            a/=2;
        }
        
        int sz=tmp.size();
        int p;
        int m=0;
        for(p=1;p<sz;p++)
        {
            if(tmp[p]==1) m++;
            if(tmp[p]==0 && p[i-1]==1)
                break;
        }
        m--;
        
        if(p==sz)
            tmp.push_back(0);
        
        tmp[p]=1;
        for(int i=0;i<p;i++)
            tmp[i]=0;
        
        for(int i=0;i<m;i++)
            tmp[i]=1;
            
            
        sz=tmp.size();
        int res=0;
        for(int i=0;i<sz;i++)
            res=(res*10)*
    }
    return 0;
}
