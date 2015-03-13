#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
      int tmp;
      vector<vector<int> >::iterator i, new_i;
      vector<int>::iterator ij, new_j;
      //make sure that i <= j
      for(i = matrix.begin(); i < matrix.end(); i++){
        for(ij = (*i).begin() + (i - matrix.begin()); ij < (*i).end(); ij++){   //matrix[i,j]
		  //ÏÈ×ªÖÃ matrix[i,j] --> matrix[j,i]
          new_i = matrix.begin() + (ij - (*i).begin());
          new_j = (*new_i).begin() + (i - matrix.begin());
          tmp = *ij;
          *ij = *new_j;
          *new_j = tmp;
        }
        reverse((*i).begin(), (*i).end());  //ºóÄæÐò
      }
    }
};
