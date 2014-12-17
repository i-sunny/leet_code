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

/*
* p=q*(1+2+4+...+2^(exp-1))+new_p
*/
class Solution {
public:
    int divide(long long dividend, long long divisor) {
        int exp2 = 0;
	long long ret;
        long long p = abs(dividend), q = abs(divisor);
        if(p < q)     //递归出口
            return 0;

        while(p - q >= 0){
            p -=  q;
            q = q + q;
            exp2++;
        }
        ret = divide(p, abs(divisor));    //figure out new_p
        ret += (0x1 << exp2) - 1;
	if(dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
	    ret = -ret;
	if(ret >= (unsigned int)(0x1<<31)) --ret;
	return ret;
    }
};

int main()
{
    Solution test;
    cout << test.divide(1, -2147483648) << endl;
}
