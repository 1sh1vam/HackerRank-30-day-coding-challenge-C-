#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void hourglass(vector<vector<int>> arr){
    int prev_hglass=0;
    int hglass = 0;
    int i=0, j=0;
    for(i=0; i<=3; i++){
        for(j=0; j<=3; j++){
            for(int k=0; k<3; k++){ 
                for(int l=0; l<3; l++){
                    
                    
                    if(k==1 & l==0 || k==1 & l==2){
                        continue;
                    }
                    else{
                        cout << arr[i+k][j+l] <<" ";
                        hglass = hglass + arr[i+k][j+l];
                    }
                }
                cout << endl;
            }
            if(hglass > prev_hglass){
            prev_hglass = hglass;
        }
        hglass = 0;
        }
        
    }

    cout << prev_hglass;
    
}

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    hourglass(arr);
    return 0;
}