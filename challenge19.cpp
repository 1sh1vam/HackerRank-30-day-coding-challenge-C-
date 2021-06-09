#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<n; i++){
        if(arr[i] == 2 || arr[i]==3){
            cout << "Prime" << endl;
        }
        else if(arr[i] < 2 || arr[i]%2==0){
            cout << "Not prime" << endl;
        }
        else{
            int p=0;
            for(int j=3; j<(arr[i]-1)/2; j+=2){
                if(arr[i]%j==0){
                    cout << "Not prime" <<endl;
                    p=1;
                    break;
                }
            }
            if(p==0){
                cout << "Prime" << endl;
            }
            
        }
    }
    return 0;
}
