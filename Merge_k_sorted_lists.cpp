#include<iostream>
using namespace std;
// Definition for singly-linked list.
 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* a;
        if(lists.size()==0)return a;
        else{
            priority_queue<int> pq;
            for(int i=0; i<lists.size(); i++){
                while(lists[i]!=nullptr){
                    pq.push(-1*lists[i]->val);
                    lists[i]=lists[i]->next;
                }  
            }      

            ListNode* res = new ListNode(-1*pq.top());
            pq.pop();
            ListNode* ptr = res;
            while(!pq.empty()){
                ptr->next =  new ListNode(-1*pq.top());
                pq.pop();
                ptr=ptr->next;
            }
            return res;
        }
         
    }
};