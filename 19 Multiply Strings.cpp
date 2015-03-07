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

/* 先考虑一个数乘多位数的情况（即内循环），然后在外循环加入i
 *关键是处理好进位carry
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        string ret(num1.size() + num2.size(), '0');
		int tmp, carry = 0;
		string::size_type i, j;
        //easy to represent
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(i = 0; i < num1.size(); i++){
            for(j = 0; j < num2.size(); j++){
                tmp = (ret[i + j] + (num1[i] - '0') * (num2[j] - '0') + carry) - '0';
                carry =  tmp / 10;
                ret[i + j] = tmp % 10 + '0';
            }
			ret[i + j] = carry + '0';
			carry = 0;
        }
        int k = i + j - 1;
        while(k > 0 && ret[k--] == '0')
            ret.erase(ret.end() - 1);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    Solution test;
    cout << test.multiply("123", "456") << endl;
}
