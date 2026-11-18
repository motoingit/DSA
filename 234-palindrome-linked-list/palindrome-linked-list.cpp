class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return true;

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr &&
               fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* secondHalf = reverse(slow->next);

        // Step 3: Compare both halves
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;

        while (temp != nullptr) {
            if (firstHalf->val != temp->val)
                return false;

            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        return true;
    }
};