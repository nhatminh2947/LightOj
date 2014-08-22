//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: B - Triangle Partitioning
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

int main()
{
    //freopen("B.INP","r",stdin);
    //freopen("B.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        double ab,ac,bc,ratio;
        double ABC,ADE,BDEC;
        scanf(" %lf %lf %lf %lf ",&ab,&ac,&bc,&ratio);
        
        double p=(ab+ac+bc)/2;
        
        ABC=sqrt(p*(p-ab)*(p-ac)*(p-bc));
        //cout<<ABC<<endl;
        
        BDEC=ABC/(ratio+1);
        ADE=ABC-BDEC;
        
        //cout<<ADE<<fixed<<endl;
        
        double res=ab*sqrt(ADE/ABC);
        
        printf("Case %d: %.7lf\n",t,res);
    }
    return 0;
}
