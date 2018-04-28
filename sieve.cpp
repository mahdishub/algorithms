#include<bits\stdc++.h>

using namespace std;


vector <unsigned int> prime;
bool checker[10000000];

void sieve(int n){

    checker[0] = checker[1] = true;
    int i,j,sqrtN;
    sqrtN = sqrt((double)n);
    for(i=3;i<=sqrtN;i+=2){
        if(checker[i]==false){
            for(j=i*i;j<=n;j+=2*i)
                checker[j]=true;
        }
    }
    prime.push_back(2);
    for(i=3;i<=n;i+=2)
        if(checker[i]==false)
            prime.push_back(i);
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
