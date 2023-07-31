
// 647. Palindromic Substrings


class Solution {
public:

    int expandAroundIndex(string s, int left, int right){
        int count = 0;
        while(left>=0 && right<s.length() && s[left]==s[right]){
            count ++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
         int totalCount = 0;
         int n= s.length();
        for(int centre = 0; centre<n; centre++){
            int oddAns = expandAroundIndex(s,centre,centre);
            totalCount = totalCount + oddAns;

            int evenAns = expandAroundIndex(s,centre,centre+1);
            totalCount = totalCount + evenAns;
        }
        return totalCount;
    }
};