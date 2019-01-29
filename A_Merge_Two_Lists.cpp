class Solution {
public:
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur1=l1;
        ListNode* cur2=l2;

        ListNode* pnt=new ListNode(0);
        ListNode* res=pnt;
        while(1){
            if(cur1==nullptr){
                pnt=cur2;
                break;
            }
            if(cur2==nullptr){
                pnt=cur1;
                break;
            }
            if(cur1->val>cur2->val){
                pnt->val=cur1->val;
                cur1=cur1->next;
            }
            else{
                pnt->val=cur2->val;
                cur1=cur2->next;
            
            }
            pnt->next=new ListNode(0);
            pnt=pnt->next;
        }
        // pnt=nullptr;
        return res;
    }
};