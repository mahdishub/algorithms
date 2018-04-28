#include <bits/stdc++.h>

using namespace std;

struct values{

    int r;
    int x;
    int y;

};

values ext_gcd( int a,int b ) {

    int r2 = a,r1 = b,x2 = 1,x1 = 0,y1 = 1,y2 = 0,q,r,X,Y;
    while ( r1 ) {
        q  = r2/r1;
        r  = r2 % r1;
        X  = x2 - ( q*x1 );
        Y  = y2 - ( q*y1 );
        r2 = r1;
        r1 = r;
        x2 = x1;
        y2 = y1;
        x1 = X;
        y1 = Y;
    }
    values ans;
    ans.r = r2;
    ans.x = x2;
    ans.y = y2;
    return ans;
}


int main ( ) {


    values m;
    m = ext_gcd(240,46);
    cout << m.r <<' ' <<  m.x <<' ' << m.y << endl;


}
