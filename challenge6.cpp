#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<string, string> Nmp;

void insert_mp(string str, int num){
    string word1="", word2="";
    for(int i=0; i<num; i++){
        word1 = word1 + str[i];
    }

    for(int j=num+1; j<str.length(); j++){
        word2 = word2 + str[j];
    }

    Nmp[word1] = word2;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i=0, n, num;
    cin >> n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string str;
    for(i=0; i<n; i++){
       getline(cin, str);
       for(int j=0; j<str.length(); j++){
            if(str[j] == ' '){
                num = j;
                break;
            }
       }

        insert_mp(str, num);
        }
    while(cin >> str){
        if(Nmp.find(str) != Nmp.end()){
                 cout << str << "=" << Nmp[str] << endl;
                 
             }
             else{
                 cout << "Not found" << endl;
             }
    }
    
    return 0;
}
