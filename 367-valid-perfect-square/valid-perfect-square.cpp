class Solution {
public:
    bool isPerfectSquare(int num1) {
        long long num = num1;
        if( num == 1) return true;
        else if (num == 2) return false;
        else if (num == 3) return false;

        long long  x = 2;
        while(x*x <= num){
            if(x*x == num) return true;
            x++;
        }
        return false;
    }
};