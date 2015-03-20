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
 |1 2 3 4|
 |5 6 7 8|--> |6 7| 
 |9 a b c|    |a b| a new matrix (m-2)x(n-2)
 |d e f g|
 */
 //we should be careful about mx1 and 1xn case!!
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
	  int i, m = matrix.size(), n;
      vector<int> ret;
	  if(m == 0)  return ret;
	  n = matrix[0].size();
      ret.insert(ret.end(), matrix[0].begin(), matrix[0].end());   //add: 1 2 3 4
      if(m > 1){
        for(i = 1; i < m - 1; i++)
          ret.push_back(matrix[i][n - 1]);  //add: 8 c
        vector<int> tmp0(matrix[m - 1].begin(), matrix[m - 1].end()); //add: g f e d
		reverse(tmp0.begin(), tmp0.end());
		ret.insert(ret.end(), tmp0.begin(), tmp0.end());
        if(n > 1){
          for(i = m - 2; i > 0; i--)
            ret.push_back(matrix[i][0]);    //add: 9 5
        }
      }
      vector<vector<int> > newMatrix; 
	  if(m > 2 && n > 2){
		for(i = 1; i < m - 1; i++){  //new matrix
			vector<int> tmp(matrix[i].begin() + 1, matrix[i].end() - 1);
			newMatrix.push_back(tmp);
		}
		vector<int> tmpRet = spiralOrder(newMatrix);
        ret.insert(ret.end(), tmpRet.begin(), tmpRet.end());
	  }
      return ret;
    }
};

int main()
{
  int a[][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  vector<vector<int> > v;
  for(int i = 0; i < 4; i++){
    vector<int> row(a[i], a[i] + 4);
    v.push_back(row);
  }
  Solution test;
  vector<int> ret = test.spiralOrder(v);

  for(i = 0; i < ret.size(); i++)
	  cout << ret[i] <<" ";
  cout << endl;
  return 0;
}
