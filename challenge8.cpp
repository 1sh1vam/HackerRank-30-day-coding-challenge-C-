#include <bits/stdc++.h>
#include<cmath>

using namespace std;

void binary(int num){
    int cnt_prev=0;
    int count = 0;
    vector<int> arr ={};
    while(num > 0){
        arr.push_back(num%2);
        num = floor(num/2);
    }
    for(auto i=arr.begin(); i!=arr.end(); i++){
        if(*i == 1){
            count++;
        }
        else{
            if(count > cnt_prev){
                cnt_prev = count;
            }
            
            count = 0;
        }
        cout << count << "\t" << cnt_prev << endl;
    }
    if(count > cnt_prev){
        cnt_prev = count;
    }
    cout << cnt_prev;
}


int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    binary(n);
    return 0;
}
