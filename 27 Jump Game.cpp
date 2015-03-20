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

/*
 * 从后往前倒推
 */
class Solution {
public:
    bool canJump(int A[], int n) {
    	bool tag = 0;
		int i;
		if(n <= 1)
            return true;
    	for(i = n - 2; i >= 0; i--){
    		if(A[i] >= (n - 1 - i)){
    			tag = 1;
				break;
    		}
    	}
    	if(tag == 0)         //递归出口
    		return false;
		else if(i == 0 && tag == 1)  //递归出口
			return true;
    	else
    		return canJump(A, i + 1);
    }
};

int main(){
	//int A[] ={2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
	int A[] = {2, 3, 1, 0, 4};
	Solution test;
	cout << test.canJump(A, 5) << endl;
}