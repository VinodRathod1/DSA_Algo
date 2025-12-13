class Solution {
    public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        // Traverse the list in pairs
        while (prev->next != NULL && prev->next->next != NULL) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev to the next pair
            prev = first;
        }

        return dummy->next;
    }
};

