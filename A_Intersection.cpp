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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> check;
        while(headA!=nullptr){
            check[headA]=true;
            headA=headA->next;
        }
        while(headB!=nullptr){
            if(check[headB])
                return headB;
            headB=headB->next;
        }
        return headA;
        
    }
};