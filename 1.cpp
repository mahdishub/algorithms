#include<bits/stdc++.h>

using namespace std;

int len;
int arr[100];

int cc ( int index, int toMake ) {
    int ans1,ans2;
    if ( index == len ) {
        if ( toMake == 0 ) return 0;
        else return INT_MAX;
    }
    ans1 =  cc(index+1,toMake);
    if ( toMake-arr[index] >= 0 )
        ans2 = cc( index,toMake-arr[index] ) + 1;
    return min(ans1,ans2);
}

int main () {
   int toMake;
   cin >> len >> toMake;
   for ( int i= 0 ; i < len; i++ ) cin >> arr[i];
   cout << cc(0,toMake);


}
