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

string cmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        int i;
        if(digits.size() == 0) 
            ret.push_back("");
        else if(digits.size() == 1){
            string tmp = cmap[digits[0] - '0'];
            for(i = 0; i < tmp.size(); i++){
                string s(1, tmp[i]); 
                ret.push_back(s);
            }
         }else{
            vector<string> oldRet = letterCombinations(digits.substr(0, digits.size() - 1));
            string last = cmap[digits[digits.size() - 1] - '0'];       //最后一个数对应字符
            vector<string> tmpRet(oldRet);
            for(i = 0; i < last.size(); i++){
                tmpRet = insertLetter(oldRet, last[i]);
                ret.insert(ret.end(), tmpRet.begin(), tmpRet.end());
             }
         }
         return ret;  
    }
    vector<string> insertLetter(vector<string> svec, char c){
        for(vector<string>::size_type ix = 0; ix < svec.size(); ix++)
            svec[ix].append(1, c);
        return svec; 
    }
};

void main()
{
    string a("34");
    Solution test;
    vector<string> p = test.letterCombinations(a);
    for(vector<string>::size_type ix = 0; ix < p.size(); ix++)
        cout << p[ix] << endl;
}
