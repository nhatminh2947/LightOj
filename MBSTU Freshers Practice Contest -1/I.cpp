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
#define INF 3.1415926535897932384626433832795
#define PI 3.14159
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

float m,dg;

int main()
{
    freopen("I.INP","r",stdin);
    freopen("I.OUT","w",stdout);
    while(scanf(" %f %f ",&m,&dg)==2)
    {
        float CAB=dg*PI/180;
        float x=m/sin(CAB);
        float h=m/tan(CAB);
        
        float I=x+h;
        printf("%.6f\n",I);
    }
    return 0;
}
