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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int> > ret;
		vector<int>::iterator i, cbeg = candidates.begin(), cend = candidates.end();
	    sort(cbeg, cend);
	    for(i = cbeg; i < cend; i++){
		   	if(*i == target){    //既是递归出口也是一种case
		    	vector<int> tmp(1, *i);
		    	ret.push_back(tmp);
	    	}
	    	else if(*i < target){
				vector<int> c(i, cend);
			    vector<vector<int> > pre = combinationSum(c, target - *i);  //先确定一个元素*i,再进行递归，将target逐步变小
			    if(!pre.empty()){   //如果非空，则将*i元素添加至各个组合中
			    	for(vector<vector<int> >::iterator vec = pre.begin(); vec < pre.end(); vec++){
			    		(*vec).push_back(*i);
			    		sort((*vec).begin(), (*vec).end());
			    	}
			    	ret.insert(ret.end(), pre.begin(), pre.end());  //将某一固定*i元素下，所有符合要求的组合添加至最终结果
			    }
		    }
	    	else  break;
		}
		return ret;
    }
};

void main()
{
    int a[] = {2,3,5,6};
    int sizea = sizeof(a)/sizeof(int);
    vector<int> cand(a, a + sizea);
    Solution test;
    vector<vector<int> > ret = test.combinationSum(cand, 9);
	for(vector<vector<int> >::iterator i = ret.begin(); i < ret.end(); i++){
		for(vector<int>::iterator j = (*i).begin(); j < (*i).end(); j++)
			cout << *j << ' ';
		cout << endl;
	}
}
