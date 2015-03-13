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
 * m = [n/2];
 * x^n = x^m * x^m * x^(n-2m)
 */
class Solution {
public:
    double pow(double x, int n) {
    	if(n < 0)   return 1/(x * pow(x, -n - 1)); //-2^31=0x80000000 is a special num, cuz 2^31 is not included in type int
    	if(n == 0)  return 1;  //递归出口
    	if(n == 1)	return x;  //递归出口  
    	int m = n/2;

    	double r1 = pow(x, m);
    	double r2 = pow(x, n - 2 * m);
    	return r1 * r1 * r2;  	        
    }
};

void main()
{
    Solution test;
    cout << test.pow(1.00, -2147483648) << endl;
}
