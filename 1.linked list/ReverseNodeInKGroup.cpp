// Question: Reverse Nodes In K Groups
// Platform: Leetcode
// Difficulty: Hard


// * Time Complexity: O(n)
// * Space Complexity: O(1)

class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1){
            return head;
        }        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode* curr=dummy;
        ListNode* nex=dummy;
        ListNode* prev=dummy;
        
        int count=0;
        while(curr->next!=NULL){
            curr=curr->next;
            count+=1;
        }
        
        while(count>=k){
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev=curr;
            count-=k;
        }
        return dummy->next;
    }

};

// **EXPLANATION:**
// 1. First we count the size of LinkedList.
// 2. After that we make the iteration group of k till our count is equal or less than count
// 3. In every iteration we simply reverse the group, and subtracting the k from count, as every time we reverse a group we subtract that k from count.
