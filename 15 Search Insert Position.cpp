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
    int searchInsert(int A[], int n, int target) {
        int ret;
        if(target > A[n - 1])
            return  n;
        else if(target <= A[0])
            return 0;

        if(target == A[n/2])      //递归出口1,找到目标值
            ret = n/2;
        else if(n == 2)           //递归出口2,找不到目标值,则目标在两数之间
            ret = 1;
        else if(target < A[n/2])
            ret = searchInsert(A, n/2 + 1, target);
        else{
            ret = searchInsert(A + n/2, n - n/2, target);
            ret += n/2;
        }
        return ret;
    }
};

int main()
{
    int a[] = {1,2,4,5,6};
    int sz = sizeof(a)/sizeof(int);
    Solution test;
    cout << test.searchInsert(a, sz, 4) << endl;
}