class BST{
  private:
      struct node {
        int key;
        node* left;
        node* right;
      };

      node* root; //root ref
      node* createLeaf (int key);
      void addLeafPrivate (int key, node* Ptr);
      void PrintInOrderPrivate (node* Ptr);
      node* ReturnNodePrivate (int key, node* Ptr);
      int FindSmallestPrivate (node* Ptr);
      void removePrivate (int key, node* parent);
      void removeMatchRoot ();
      void removeMatch (node* parent, node* match, bool left);
      node* ReturnNode(int key);
      void removeSubtree (node* Ptr);

  public:
    BST ();
    ~BST ();
    void addLeaf (int key);
    void PrintInOrder ();
    int ReturnRoot ();
    void PrintChildren (int key);
    int FindSmallest ();
    void remove (int key);
};
