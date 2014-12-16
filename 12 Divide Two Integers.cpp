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
* p=q*(1+2+4+...+2^(exp-1))+new_q
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        int exp2 = 0, ret;
        int p = dividend, q = divisor;
        if(p < q)     //递归出口
            return 0;

        while(p - q >= 0){
            p -=  q;
            q = q + q;
            exp2++;
        }
        ret = divide(p, divisor);    //figure out new_q
        ret += (0x1 << exp2) - 1;
        return ret;       
    }
};

void main()
{
    Solution test;
    cout << test.divide(17,4) << endl;
}
