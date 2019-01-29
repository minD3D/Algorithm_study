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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vector;
        for(int i=0; i<lists.size(); i++){//O(n)
            ListNode* cur=lists[i];
            while(cur!=nullptr){
                vector.push_back(cur->val);
                cur=cur->next;
            }
        }
        if(vector.size()==0)return nullptr;
        sort(vector.begin(),vector.end());//O(nlogn)
        ListNode* pnt=new ListNode(0);
        ListNode* res=pnt;
        for(int i=0; i<vector.size();i++){//O(n)
            pnt->val=vector[i];
            if(i!=vector.size()-1)
                pnt->next=new ListNode(0);
            pnt=pnt->next;
        }
        // pnt=nullptr;
        return res;
    }
};

//O(n+nlogn)