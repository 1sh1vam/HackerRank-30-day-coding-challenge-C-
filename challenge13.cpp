#include <iostream>
#include<vector>

using namespace std;

class Solution {
    //Write your code here
    private:
        vector<char> stack;
        vector<char> queue;
    public:
        
        void pushCharacter(char d){
            stack.push_back(d);
        }
        void enqueueCharacter(char d){
            queue.push_back(d);
        }
        
        char popCharacter(){
            char c;
            auto it = stack.end()-1;
            c = *it;
            stack.erase(it);
            return c;
        }
        
        char dequeueCharacter(){
            char c;
            auto it = queue.begin();
            c = *it;
            queue.erase(it);
            return c;
        }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}