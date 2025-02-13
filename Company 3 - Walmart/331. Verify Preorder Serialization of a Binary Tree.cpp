class Solution {
public:
    bool isValidSerialization(string preorder) {
        int node = 1;
        preorder += ',';

        for(int i=0; i<preorder.size(); i++)
        {
            if(preorder[i] == ',')
            {
                node--;

                if(node<0)
                    return false;

                if(preorder[i-1] != '#')
                    node += 2;
            }
        }

        return node == 0;
    }
};
