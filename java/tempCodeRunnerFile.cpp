#include<bits/stdc++.h>
using namespace std;

int ss[25]={ 3, 4, 5, 6, 7, 8, 9, 10, 10, 11, 12, 3, 13, 14, 6, 15, 16, 17, 18, 19, 20, 21, 8, 22};

int main(){
    for(int i=0;i<23;i++){
        cout<<ss[i]^i<<" ";
    }
    
    return 0;
}