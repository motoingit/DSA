class Solution {
public:
    bool isAnagram(string s, string t) {
         int nS = s.size(), nT = t.size();
        if(nS != nT || !nS || !nT) return false;

        int freqArr[26] = {0};
        for(int i = 0; i < nS; i++){
            freqArr[s[i] - 'a']++;
        }

        for(int i = 0; i < nT; i++){
            freqArr[t[i] - 'a']--;
            if(freqArr[t[i] - 'a'] < 0){
                return false;
            }
        }

        return true;
    
    }
};