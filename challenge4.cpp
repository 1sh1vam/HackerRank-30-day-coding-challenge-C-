#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i, j, n;
    cin >> n;
    cin.ignore(1,'\n');
    for(i=0; i<n; i++){
        string str1, even, odd;
        getline(cin, str1);
        if(str1.length() >= 2){
            even = str1[0];
            odd = str1[1];
            for(j=2; j<str1.length(); j++){
                if(j%2==0){
                    even = even + str1[j];
                }
                else{
                    odd = odd + str1[j];
                }
            }
        }
        else if(str1.length() > 0){
            even = str1[0];
        }
        cout << even << "\t" << odd<< endl;
    }
    
    return 0;
}
