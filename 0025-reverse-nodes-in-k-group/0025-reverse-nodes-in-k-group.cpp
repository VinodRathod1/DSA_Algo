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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        int cnt=0;
        while(curr && cnt<k){
            cnt++;
            curr=curr->next;
        }
        if(cnt<k)return head;
        cnt=0;
        ListNode* prev=nullptr;ListNode* next=nullptr;
        curr=head;
        while(cnt<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        head->next=reverseKGroup(curr,k);
        return prev;

    }
};