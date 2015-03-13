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
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        string v;
        map<string, int> m;
        pair<map<string, int>::iterator, bool> tmp;
        for(int i = 0; i < strs.size(); i++){
            v = strs[i];
            sort(v.begin(), v.end());     //sort is important!!
            tmp = m.insert(make_pair(v, i)); 
            if(!tmp.second){    //string is already in map
              if(m[v] >= 0){    //push the first string that meet anagrams 
                ret.push_back(strs[m[v]]);
                m[v] = -1;
              }
              ret.push_back(strs[i]);
            }
        }
        return ret;
    }
};

int main()
{
  string s[] = {"ate", "and", "dna", "tea", "eat", "endl", "hello", "ehllo"};
  vector<string> str(s, s + 8);
  Solution test;
  vector<string> ret = test.anagrams(str);
  for(int i = 0; i < ret.size(); i++)
    cout << ret[i] << endl;
  return 0;
}
