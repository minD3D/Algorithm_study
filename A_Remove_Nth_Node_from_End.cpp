#include<vector>
#include<queue>
#include<dequeue>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> vector;
        ListNode* cur=head;
        while(cur!=nullptr){
            vector.push_back(cur);
            cur=cur->next;
        }
        
        if(n==vector.size()){
            if(vector.size()==1)
                head=nullptr;
            else
                head=vector[1];
        }
        else if(n==1){
            vector[vector.size()-2]->next=nullptr;
            
        }
        else
            vector[vector.size()-1-n]->next=vector[vector.size()-n+1];
        return head;
    }
};