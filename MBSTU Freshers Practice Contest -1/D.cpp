//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: D - Help the Editor !!!
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

char str[50];

int main()
{
    //freopen("D.INP","r",stdin);
    //freopen("D.OUT","w",stdout);
    while(gets(str))
    {
        int len=strlen(str);
        int cnt1=0;
        int cnt2=0;
        
        if(str[0]=='a' || str[0]=='A' || str[0]=='e' || str[0]=='E' || str[0]=='i' || str[0]=='I' 
            || str[0]=='o' || str[0]=='O' || str[0]=='u' || str[0]=='U')
            {
                cnt1++;
                str[0]='*';
            }
        else if(('a'<=str[0] && str[0]<='z') || ('A'<=str[0] && str[0]<='Z'))
            {
                cnt2++;
                str[0]='#';
            }
        
        for(int i=1;i<len;i++)
        {
            if(str[i-1]==' ' || str[i-1]=='.' || ('0'<=str[i-1] && str[i-1]<='9'))
            {
                if(str[i]=='a' || str[i]=='A' || str[i]=='e' || str[i]=='E' || str[i]=='i' || str[i]=='I' 
                || str[i]=='o' || str[i]=='O' || str[i]=='u' || str[i]=='U')
                {
                    cnt1++;
                    str[i]='*';
                }
                else if(('a'<=str[i] && str[i]<='z') || ('A'<=str[i] && str[i]<='Z'))
                {
                    cnt2++;
                    str[i]='#';
                }
            }
        }
        puts(str);
        printf("Number of * is: %d.\n",cnt1);
        printf("Number of # is: %d.\n",cnt2);
        printf("\n");
    }
    return 0;
}
