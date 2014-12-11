class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	string t;
    	int len = 0;
    	for(string::size_type ix = 0; ix != s.size(); ++ix)
    	{
    		int pos = t.find(s[ix]);
    		if(pos != -1){     //有重复字符
    			t.erase(0, pos + 1); 
    		}
    		t.append(1, s[ix]);
		if(len < t.size())
			len = t.size();
    	}
    	return len;      
    }
};