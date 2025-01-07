class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* cur = head;
        Node* t;
        
        while(cur)
        {
            for(int i=1; i<m && cur != NULL; i++)
                cur = cur->next;
            
            if(cur == NULL || cur->next == NULL)
                return head;
            
            t = cur->next;
            for(int i=0; i<n && t != NULL; i++)
            {
                Node* temp =  t;
                t = t->next;
                delete temp;
            }
            
            cur->next = t;
            
            cur = t;
        }
        
        return head;
    }
};
