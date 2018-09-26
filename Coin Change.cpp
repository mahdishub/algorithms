#include<bits/stdc++.h>

using namespace std;

#define inf 0x3f3f3f3f

int len;
int arr[100];
int dp[1005][1005];


int cc ( int index, int toMake ) {
    int ans1 = inf,ans2 = inf;
    if ( dp[index][toMake] != -1 ) return dp[index][toMake];
    if ( index == len ) {
        if ( toMake == 0 ) return 0;
        else return inf;
    }
    ans1 =  cc(index+1,toMake);
    if ( toMake-arr[index] >= 0 )
        ans2 = cc( index,toMake-arr[index] ) + 1;
    return dp[index][toMake] =  min(ans1,ans2);
}


int main () {
    memset(dp,-1,sizeof(dp));
    int toMake;
    cin >> len >> toMake;
    for ( int i= 0 ; i < len; i++ ) cin >> arr[i];
    cout << cc(0,toMake);


    return 0;
}
