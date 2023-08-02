// 14. Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i=0;
        while(true){
            char current_ch = 0;
            for(auto str:strs){
                if(i>=str.size()){
                    current_ch = 0;
                    break;
                }
                if(current_ch==0){
                    current_ch = str[i];
                }
                else if(str[i] != current_ch){
                    current_ch = 0;
                    break;
                }
            }
            if(current_ch == 0){
                break;
            }
            ans.push_back(current_ch);
            i++;
        }
        return ans;
    }
};