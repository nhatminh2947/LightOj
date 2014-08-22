//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1022 - Circle in Square
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <cmath>
#include <cstdio>

#define PI 2*acos(0.0)

using namespace std;

int main()
{
    freopen("1022 - Circle in Square.INP","r",stdin);
    freopen("1022 - Circle in Square.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        double r;
        scanf(" %lf ",&r);

        double square = 4*r*r;
        double round = PI*r*r;
        printf("Case %d: %.2lf\n",t,square - round);
    }


}
