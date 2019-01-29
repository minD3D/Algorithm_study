#include<vector>
#include<queue>
#include<dequeue>
#include<stack>
using namespace std;
//Use stack to get reverse order values
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {//head is pointer
        
        deque<int> dq; //dq also save pointer references
        ListNode* cur=head; //this cur also pointer so if it changed its change value of address 
        while(cur!=nullptr){
            dq.push_back(cur->val);
            cur=cur->next;
        }
        cur=head;
        while(cur!=nullptr){
            cur->val=dq.front();
            dq.pop_front();
            cur=cur->next;
            if(cur!=nullptr){
                cur->val=dq.back();
                dq.pop_back();
                cur=cur->next;        
            }
        }
    }
};