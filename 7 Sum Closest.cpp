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
    int threeSumClosest(vector<int> &num, int target) {
        vector<int>::iterator beg = num.begin(), end = num.end(); 
        vector<int>::size_type a, b, c;
        int sum, sumClosest;
        sort(beg, end);
 
        for(a = 0; a < num.size() - 2; a++){
            if(a > 0 && num[a] == num[a - 1])
                continue;
            for(b = a + 1; b < num.size() - 1; b++){
                if(b > a + 1 && num[b] == num[b - 1])
                    continue;
                for(c = b + 1; c < num.size(); c++){
                    sum = num[a] + num[b] + num[c];
                    if(target - sumClosest > sum - target)
                        sumClosest = sum;
                    if(sum > target)
                        break;
                    if(sum == target)
                        return sum;
                }
            }
        }
        return sumClosest;
    }
};

void main()
{
    int a[] = {-3, -2, -2, -1, 0, 2, 1, 1};
    int sizea = sizeof(a)/sizeof(int);
    vector<int> height(a, a + sizea);
    Solution test;
    int p = test.threeSumClosest(height, 5);
    cout << p << endl;
}
