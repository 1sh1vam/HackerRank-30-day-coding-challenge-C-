#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
     string ne;
     int len = s.length();
     if(s[len-2] == 'P' && s[len-1] == 'M'){
         if(s.substr(0, 2)=="12"){
             ne = ne+s.substr(0, len-2);
         }
         else{
            ne = ne + to_string(stoi(s.substr(0, 2))+12);
            ne += s.substr(2, len-4);
         }
            
     }
     else{
         if(s.substr(0, 2) == "12"){
             ne = ne+"00";
             ne = ne+s.substr(2, len-4);
         }
         else{
             ne = ne+s.substr(0, len-2);
         }
     }
     
     return ne;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
