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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *h1=l1,*h2=l2;
        ListNode *res=new ListNode(0);
        ListNode *cur=res;

        int carry=0;
        while(h1!=NULL && h2!=NULL) {
            int sum=h1->val+h2->val + carry;
            if(sum>=10){
                sum=sum-10;
                carry=1;
            }
            else{
                carry=0;
            }
            
            cur->next=new ListNode(sum);
            cur=cur->next;
            h1=h1->next;
            h2=h2->next;
        }
        while(h1!=NULL)
        {
            
            int sum=carry+h1->val;
            carry=sum>=10?1:0;
            sum=sum>=10?sum-10:sum;
            cur->next=new ListNode(sum);
            cur=cur->next;
            h1=h1->next;
        }
        while(h2!=NULL)
        {
            
            int sum=carry+h2->val;
            carry=sum>=10?1:0;
            sum=sum>=10?sum-10:sum;
            cur->next=new ListNode(sum);
            cur=cur->next;
            h2=h2->next;
        }
        
        if(carry)
        {
            cur->next=new ListNode(carry);
        }
        
        return res->next;
    }
};