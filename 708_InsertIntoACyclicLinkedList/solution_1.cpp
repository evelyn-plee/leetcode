#include<vector>
#include<iostream>

using namespace std;

// 1. prev->val <= x <= current->val
// insert between prev and current.
// 2. x is the min/ max in the list
// insert before the head (ie the head has the smallest value and its prev->val > head->val)
// 3. Traverses back to the starting point.
// insert before the starting point


class Node{
public:
    int val;
    Node* next;
    Node(){}
    Node(int _val, Node* _next){ val = _val; next = _next; }
};


class Solution{
public:
    Node* insert(Node* head, int insertVal){
        if(!head){
            Node* ret = new Node(insertVal, ret);
            return ret;
        }
        Node* cur = head->next;
        while(cur != head){
            if((cur->val <= insertVal && insertVal <= cur->next->val) ||
              (cur->val > cur->next->val && (insertVal <= cur->next->val || cur->val <= insertVal))){
                Node* temp = cur->next;
                Node* ptr = new Node(insertVal, temp);
                cur->next = ptr;
                return head;
            }
            cur = cur->next;
        }
        Node* temp = cur->next;
        Node* ptr = new Node(insertVal, temp);
        cur->next = ptr;
        return head;
    }
};
