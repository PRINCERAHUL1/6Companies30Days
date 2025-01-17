class mycompare{
    public:
    bool operator()(const ListNode* a, const ListNode* b){
        return (a->val > b->val);
    }
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        priority_queue<ListNode*, vector<ListNode*>, mycompare> pq;

        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i] != NULL)
                pq.push(lists[i]);
        }

        while(!pq.empty())
        {
            auto last=pq.top();
            pq.pop();

            temp->next = last;
            temp=temp->next;

            if(last->next)
                pq.push(last->next);
        }

        return head->next;
    }
};
