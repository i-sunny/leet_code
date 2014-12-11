class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 1, max_index = 0;
        int l, r;
        for(string::size_type ix = 1; ix < s.size(); ++ix)
        {
            l = ix - 1; r = ix + 1;
            while(r < s.size() && l >= 0 && s[l] !== s[r]) {
                l--; r++;
            }
           if(max_len < r - l + 1){
                max_len = r - l + 1;
                max_index = l;
            }

            l = ix - 1; r = ix;
            while(r < s.size() && l >= 0 && s[l] == s[r]){
                    l--;  r++;
            }
           if(max_len < r - l + 1){
                max_len = r - l + 1;
                max_index = l;
            }
        }
        return s.substr(max_index, max_len);
    }
};