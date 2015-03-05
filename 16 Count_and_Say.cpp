#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    string countAndSay(int n) {
    	string ret;
    	if(n == 1){   //递归出口
    		ret.append(1, '1');
    		return ret;
    	}
		string pre = countAndSay(n - 1);
		ret = countNext(pre);
		return ret;
    }

    string countNext(string s){
    	int count = 1;
    	string ret;
    	for(string::size_type ix = 0; ix < s.size(); ix++){
    		if(ix + 1 < s.size() && s[ix] == s[ix + 1]){
    			count++;
    			continue;
    		}
			ret.append(1, '0' + count);
			ret.append(1, s[ix]);
			count = 1;
	}
    	return ret;
    }
};

int main()
{
	Solution test;
	string str = test.countAndSay(5);
    cout << str << endl;
}