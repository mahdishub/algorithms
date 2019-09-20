#include<bits\stdc++.h>

using namespace std;


const int SIZE = 1e6;
vector <int> prime; 
bool sieve[SIZE]; 
void primeSieve ( int n ) {
    sieve[0] = sieve[1] = 1;

    prime.push_back(2);
    for ( int i = 4; i <= n; i += 2 ) sieve[i] = 1;

    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == 0 ) {
            for ( int j = i * i; j <= n; j += 2 * i ) sieve[j] = 1;
        }
    }

    for ( int i = 3; i <= n; i += 2 ) if ( sieve[i] == 0 ) prime.push_back(i);
}


int main(){


    int n = 100;

    sieve(n);
    for(int i=0;i<prime.size();i++){
        cout << prime[i]<<endl;

    }
    if ( !checker[966109] )
        cout << "Prime" << '\n';

    return 0;
}
