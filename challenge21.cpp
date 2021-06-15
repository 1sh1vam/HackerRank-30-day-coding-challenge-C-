#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


vector<int> binConvert(int a){
   vector<int> binArr;
   while(a){
       int num = a%2;
       binArr.push_back(num);
       a = floor(a/2);
       
       if(a<1){
           break;
       }
   }
   return binArr;
}

int power(int a, int n){
    if(n==0){
        return 1;
    }
    else if(n%2==0){
        return power(a, n/2) * power(a, n/2);
    }
    else{
        return a*power(a, n/2) * power(a, n/2);
    }
}

int bitAnd(int a, int b){
    vector<int> first = binConvert(a), second = binConvert(b);
    int diff;
    if(first.size() < second.size()){
        diff = first.size() - second.size();
        for(int i=0; i<diff; i++){
            first.insert(first.begin(), 0);
        }
    }
    else if(first.size() > second.size()){
        diff = second.size() - first.size();
        for(int i=0; i<diff; i++){
            second.insert(second.begin(), 0);
        }
    }
    
    vector<int> andArr;
    for(int i=0; i<first.size(); i++){
        if(first[i]==1 && second[i]==1){
            andArr.push_back(1);
        }
        else{
            andArr.push_back(0);
        }
    }
    int sum=0;
    for(int i=0; i<andArr.size(); i++){
        if(andArr[i]==1){
            sum += power(2, i);
        }
    }
    return sum;
}


int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        // assert(bitAnd(6, 7) == 6);
        int max = 0;
        for(int i=1; i<n; i++){
            for(int j=i+1; j<=n; j++){
                int sum = bitAnd(i, j);
                if(sum < k && sum > max){
                    max = sum;
                }
            }
        }
        cout << max <<endl;
    }
    
    

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
