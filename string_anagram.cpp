/***
 * 
 * Leetcode : https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * 
*/



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int>hMap;
        vector<int> result;

        for(auto ch : p){
            if(hMap.find(ch) == hMap.end()){
                hMap[ch] = 1;
            } else {
                hMap[ch]++;
            }
        }

        int match = 0;
        int len = p.size();
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(hMap.find(ch) != hMap.end()){
                hMap[ch]--;
                if(hMap[ch] == 0) match++;
            }

            if(i >= len && (hMap.find(s[i - len]) != hMap.end())){
                hMap[s[i - len]]++;               
                if(hMap[s[i - len]] == 1) match--;
            }

            if(match == hMap.size()){
                result.push_back(i - len + 1);
            }
        }

        return result;
    }
};