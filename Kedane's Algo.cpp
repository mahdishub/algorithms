#include<bits/stdc++.h>

using namespace std;


int Kadane ( int arr[], int n ) {
    int maxsub,maxglob;
    maxsub = maxglob = arr[0];
    for ( int i = 1; i < n ; i++ ) {

        maxsub  = max(arr[i],maxsub+arr[i]);
        maxglob = max(maxsub,maxglob);
    }
    return maxglob;
}

int main () {

    int arr[] = {2,1,-5,2,1,-3,2,0,1,-10,5,1,-7,5,1,-6,5,0,1};
    cout << Kadane(arr,18);
    return 0;
}
