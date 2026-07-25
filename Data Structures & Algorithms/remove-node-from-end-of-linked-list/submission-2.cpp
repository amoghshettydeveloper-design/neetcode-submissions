/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = 0;
        ListNode* p = head;
        while (p != nullptr) {
            c++;
            p = p->next;
        }
        ListNode* prev = head;
        ListNode* del = head;
        for (int i = 0; i < (c - n); i++) {
            prev = del;
            del = del->next;
        }
        cout<<c<<endl;
        
        prev->next = del->next;
        if(prev == del){
            head = prev -> next;
        }
        delete del;
        return head;
    }
};
