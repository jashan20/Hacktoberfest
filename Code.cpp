vector <int> bottomView(Node *root)
{
   // Your Code Here
   vector <int> v;
   if(root == NULL)
   return v;

   queue<pair<Node*,int>> q;
   map<int,int> m;
   q.push({root,0});
   while(!q.empty()){
       auto p = q.front();
       Node *curr = p.first;
       int hd = p.second;
       q.pop();
       m[hd] = curr->data;
       if(curr->left != NULL)
       q.push({curr->left,hd-1});
       if(curr->right != NULL)
       q.push({curr->right,hd+1});
   }
   for(auto it = m.begin() ; it != m.end();it++)
   v.push_back(it->second);
   return v;
}
