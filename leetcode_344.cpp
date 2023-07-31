// 344. Reverse String


class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
         int n = s.size();
        int j=n-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};