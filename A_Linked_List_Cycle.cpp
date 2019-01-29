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
    bool hasCycle(ListNode *head) {
        // vector<pair<ListNode*,bool>> check;
        int ch=-999999999;
        while(head!=nullptr){
            if(head->val!=ch){
                head->val=ch;
                head=head->next;
            }
            else
                return true;
        }
        return false;
        
    }
};