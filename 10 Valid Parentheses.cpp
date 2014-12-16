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

<<<<<<< HEAD
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *pa = head, pb = pa, pa_pre;
        int dis = 0;
        while(pb != NULL){
            if(dis++ < n)
                pb = pb->next;
            else{
                pa_pre = pa;
                pa = pa->next;
                pb = pb->next;
            }
        }
        if(pa == head)
            head = head->next;
        else
            pa_pre->next = pa->next;
        delete pa;
        return head;
    }
};
=======
char cmatch(char c)
{
    switch(c){
        case '(': return ')';
        case ')': return '(';
        case '[': return ']';
        case ']': return '[';
        case '{': return '}';
        case '}': return '{';
    }
}

class Solution {
public:
    bool isValid(string s) {
        bool count = 0;
        stack<char> stk;                
        for(int ix = 0; ix < s.size(); ix++){
            if(ix > 0 && stk.size() != 0 && s[ix] == cmatch(stk.top()))
                stk.pop();
            else
                stk.push(s[ix]);
        }
        if(stk.size() != 0)
            return false;
        return true;
    }
};

int main(void)
{
    string s("()[]{}");
    Solution test;
    int p = test.isValid(s);
    cout <<  p << endl;
    return 0;
}

>>>>>>> origin/master
