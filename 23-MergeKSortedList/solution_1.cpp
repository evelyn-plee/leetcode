#include<vector>
#include<queue>
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        for(auto l : lists){
            if(l != nullptr) minHeap.push(l);
        }

        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while(!minHeap.empty()){
            ListNode* top = minHeap.top();
            minHeap.pop();
            cur->next = top;
            cur = top;
            if(top->next != nullptr) minHeap.push(top->next);
        }
        return res->next;
    }

private:
    struct compare{
        bool operator()(const ListNode* l1, const ListNode* l2){
            return l1->val > l2->val;
        }
    };
};
