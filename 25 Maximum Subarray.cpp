#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max = A[0], sum = 0;
        for(int i = 0; i < n; i++){
          sum += A[i];
          if(max < sum)
            max = sum;
          if(sum < 0)
            sum = 0;
        }
        return max;
    }
};

int main()
{
  int a[] = {-2,1,-3,4,-1,2,1,-5,4};
  Solution test;
  cout << test.maxSubArray(a, 9) << endl;
  return 0;
}
