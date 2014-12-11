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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	int carry = 0;
    	int num;
    	ListNode *node, *head, *tmp;
    	head = new ListNode(-1);
    	node = head;

    	while(l1 != NULL && l2 != NULL)
    	{
    		num = carry + l1->val + l2->val;
    		carry = num / 10;

    		tmp = new ListNode(num%10);
		node->next = tmp;
		if(node->val == -1)
			head = tmp;
		node = node->next;


    		l1 = l1->next;
    		l2 = l2->next;
    	}
	while(l1 != NULL){
		num = carry + l1->val;
		carry = num / 10;

    		tmp = new ListNode(num%10);
		node->next = tmp;
		node = node->next;
		l1 = l1->next;
	}
	while(l2 != NULL){
		num = carry + l2->val;
    		carry = num /10;

    		tmp = new ListNode(num%10);
		node->next = tmp;
		node = node->next;
		l2 = l2->next;
	}
	if(carry != 0){
		tmp = new ListNode(carry);
		node->next = tmp;
	}

	return head;
    }
};