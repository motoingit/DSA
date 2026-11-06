#include <stack>

class Solution {
public:
    bool isOpening(char &ch){
        return ((ch == '(') || (ch == '{') || (ch == '['));
    }

    bool isClosing(char &ch){
        return ((ch == ')') || (ch == '}') || (ch == ']'));
    }

    bool isDuplet(char &ch1, char &ch2){
        if(ch1 == '(' && ch2 == ')') return true;
        else if(ch1 == '[' && ch2 == ']') return true;
        else if(ch1 == '{' && ch2 == '}') return true;
        else return false;
    }

    bool isValid(string s) {
        int n = s.size();
        stack <char> ss;
        for(int i = 0; i < n; i++){
            if(isOpening(s[i])){
                ss.push(s[i]);
            }else if(isClosing(s[i])){
                if(ss.empty() == false && isDuplet(ss.top(), s[i])){
                    ss.pop();
                }else{
                    return false;
                }
            }
        }

        if(ss.empty()) return true;
        else return false;
    }
};