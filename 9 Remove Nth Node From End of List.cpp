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