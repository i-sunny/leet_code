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

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *a = head, *na, *pa;
        while(a != NULL)
        {
            na = a->next;
            if(a == head && na != NULL){
                a->next = na->next;
                na->next = a;
                head = na;    // new head
            }
            else if(a != head && na != NULL){
                pa->next = na;
                a->next = na->next;
                na->next = a;
                if(a->next == NULL)
                    return head;
            }
            pa = a;   //new pre pointer for next loop
            a = a->next;
        }
        return head;
    }
};

void main()
{
    int x[4] = {1,2,3,4};
    ListNode *node, *head, *tmp;
    tmp = new ListNode(x[0]);
    head = tmp; node = head;
    for(int i = 1; i < 4; i++){
        tmp = new ListNode(x[i]);
        node->next = tmp;
        node = node->next;
    }
    Solution test;
    ListNode *nHead = test.swapPairs(head);
    for(ListNode *no = nHead; no !=NULL; no=no->next)
        cout << no->val << endl;
}
