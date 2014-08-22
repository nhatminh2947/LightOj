//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: F - Hidden Secret!
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
int c1[50],c2[50];
char s1[105];
char s2[105];

int main()
{
    //freopen("F.INP","r",stdin);
    //freopen("F.OUT","w",stdout);
    scanf("%d",&tcs);
    getchar();
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d: ",t);
        gets(s1);
        gets(s2);
        
        int l1=strlen(s1);
        int l2=strlen(s2);
        
        for(int i=0;i<50;i++)
            c1[i]=c2[i]=0;
        
        for(int i=0;i<l1;i++)
        {
            if('A'<=s1[i] && s1[i]<='Z')
                c1[s1[i]-'A']++;
            else if('a'<=s1[i] && s1[i]<='z')
                c1[s1[i]-'a']++;
        }
        
        for(int i=0;i<l2;i++)
        {
            if('A'<=s2[i] && s2[i]<='Z')
                c2[s2[i]-'A']++;
            else if('a'<=s2[i] && s2[i]<='z')
                c2[s2[i]-'a']++;
        }
        
        bool yes=true;
        for(int i=0;i<27;i++)
            if(c1[i]!=c2[i])
            {
                yes=false;
                break;
            }
            
        if(yes) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
