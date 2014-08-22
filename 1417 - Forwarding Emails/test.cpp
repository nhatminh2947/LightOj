//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1417 - Forwarding Emails
// Verdict: 
//******************************************************************

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>

#define mp make_pair
#define pb push_back
#define INF 1000111222
#define maxN 50000

using namespace std;

int main()
{
    freopen("1417 - Forwarding Emails.INP","w",stdout);
    //freopen("1417 - Forwarding Emails.OUT","w",stdout);
    
    int tcs = 1;
    printf("%d\n",tcs);
    int n = 50000;
    for(int t = 1 ; t <= tcs ; t++)
    {
        for(int i = 1 ; i <= n ; i++)
            printf("%d %d\n",i,rand()%n+1);
    }
    
    
    return 0;
}
