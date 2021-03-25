int yes(Node* root, int l, int e, int r){
        
        if (root == NULL)
            return r;
        if (root->data == e)
            l += 1;
        else 
            l = 1;
        r = max(r, l);
        
        return max(yes(root->left, l, root->data+1, r), yes(root->right, l, root->data+1, r));
        
    }
    int longestConsecutive(Node* root)
    {
         //Code here
         if (root == NULL)
            return -1;
        
        return yes(root, 0, root->data, 0) >= 2 ? yes(root, 0, root->data, 0) : -1;
    }