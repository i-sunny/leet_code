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

bool isNonnegative(int i) {  return (i >= 0); }
class Solution {
public:
    void twoSum(vector<vector<int> > &ret, vector<int>::iterator beg, vector<int>::iterator end, int num)
    {
        vector<int> triplet(1, -num);
        vector<int>::iterator e = end - 1;
        for(vector<int>::iterator b = beg; b < end; b++)
        {
            if(b > beg && *b == *(b - 1))  continue;
            while(b < e){
                if(*b + *e== num){
                    triplet.push_back(*b);  triplet.push_back(*e);  sort(triplet.begin(), triplet.end());
                    ret.push_back(triplet);  triplet.assign(1, -num);
                    break;
                }
                else if( e != end - 1 && *b + *e < num){ e++; break; }
                e--;
            }
        }
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<int>::iterator beg = num.begin(), end = num.end(); 
        vector<vector<int> > ret; vector<int>::size_type ix;
        sort(beg, end);
        vector<int>::iterator nonnegPos = find_if(beg, end, isNonnegative);     
        for(ix = 0; ix < nonnegPos - beg; ix++){
            if(ix > 0 && num[ix] == num[ix - 1]) continue;
            twoSum(ret, nonnegPos, end, -num[ix]);
        }
         for(ix = nonnegPos - beg; ix < num.size(); ix++){
            if(ix > nonnegPos - beg && num[ix] == num[ix - 1]) continue;
            twoSum(ret, beg, nonnegPos, -num[ix]);
        }
        if(count(beg, end, 0) >= 3){
            vector<int> zero(3, 0);
            ret.push_back(zero);
        }
       return ret;
    }
};

void main()
{
    int a[] = {-3, -2, -2, -1, 0, 2, 1, 1};
    int sizea = sizeof(a)/sizeof(int);
    vector<int> height(a, a + sizea);
    Solution test;
    test.threeSum(height);
    //cout << p << endl;
}
