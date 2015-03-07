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
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int> > ret;
		vector<int>::iterator i, cbeg = num.begin(), cend = num.end();
	    sort(cbeg, cend);
	    for(i = cbeg; i < cend; i++){
	        if(i > cbeg && *i == *(i - 1)) continue;   //for the case [1,1] 1:correct Ans [1] rather than [[1], [1]] 
		   	if(*i == target){
		    	vector<int> tmp(1, *i);
		    	ret.push_back(tmp);
	    	}
	    	else if(*i < target){
				vector<int> c(i + 1, cend);  //i(in Combination Sum) --> i+1 here
			    vector<vector<int> > pre = combinationSum2(c, target - *i);
			    if(!pre.empty()){
			    	for(vector<vector<int> >::iterator vec = pre.begin(); vec < pre.end(); vec++){
			    		(*vec).push_back(*i);
			    		sort((*vec).begin(), (*vec).end());
			    	}
			    	ret.insert(ret.end(), pre.begin(), pre.end());
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
    vector<vector<int> > ret = test.combinationSum2(cand, 9);
	for(vector<vector<int> >::iterator i = ret.begin(); i < ret.end(); i++){
		for(vector<int>::iterator j = (*i).begin(); j < (*i).end(); j++)
			cout << *j << ' ';
		cout << endl;
	}
}
