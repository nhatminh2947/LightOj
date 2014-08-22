//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 1020 - A Childhood Game
// Verdict: Accepted
//******************************************************************

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <map>

using namespace std;

int main()
{
    freopen("1020 - A Childhood Game.INP","r",stdin);
    freopen("1020 - A Childhood Game.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    
    for(int t = 1 ; t <= tcs ; t++)
    {
        int n;
        char s[10];
        scanf(" %d %s ",&n,&s);
        
        printf("Case %d: ",t);
        
        if(s[0] == 'A')
            n--;
        
        if(n % 3)
            puts(s);
        else 
        {
            if(s[0] == 'A')
                puts("Bob");
            else puts("Alice");
        }
    }
    
    return 0;
}
