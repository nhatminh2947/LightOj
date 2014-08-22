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

int main()
{
    //freopen("E.INP","r",stdin);
    //freopen("E.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        int a[4],b[4][10];
        char s[100];
        printf("Case %d: ",t);
        
        for(int i=0;i<4;i++)
            for(int j=0;j<10;j++)
                b[i][j]=0;
        gets(s);
        
        int len=strlen(s);
        int cnt=0,k=0;
        a[0]=a[1]=a[2]=a[3]=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='.')
                cnt++;
            else
                a[cnt]=a[cnt]*10+(s[i]-'0');
        }
        
        gets(s);
        len=strlen(s);
        cnt=0,k=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='.')
            {
                cnt++;
                k=0;
            }
            else
            {
                b[cnt][k++]=(s[i]-'0');
            }
        }
        
        bool yes=true;
        for(int i=0;i<4 && yes;i++)
        {
            int tmp[10];
            for(int j=0;j<8;j++)
                tmp[j]=0;
            int k=7;
            while(a[i])
            {
                tmp[k--]=a[i]%2;
                a[i]/=2;
            }
            for(int j=0;j<8 && yes;j++)
            {
                if(tmp[j]!=b[i][j])
                    yes=false;
            }
        }
        
        if(yes) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
