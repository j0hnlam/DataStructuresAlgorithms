#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

BST::BST (){
  root = NULL;
}

BST::node* BST::createLeaf (int key){
      node* n = new node ();
      n->key = key;
      n->left = NULL;
      n->right = NULL;

      return n;
}

void BST::addLeaf (int key){

  addLeafPrivate (key, root);

}

void BST::addLeafPrivate (int key, node* Ptr){

  if (root == NULL){
    root = createLeaf (key);
  }
  else if (key < Ptr->key){ // if key value is less than current key value
    if (Ptr->left != NULL){
      addLeafPrivate (key, Ptr->left);
    }
    else{ // if left key value is null, set a value to it.
      Ptr->left = createLeaf (key);
    }
  }
  else if (key > Ptr->key){ // if key value is greater than current key value
    if (Ptr->right != NULL){
      addLeafPrivate (key, Ptr->right);
    }
    else{ // if right key value is null, set a value to it.
      Ptr->right = createLeaf (key);
    }
  }
  else{
    cout << "The key " << key << " has already been added." << endl;
  }
}

void BST::PrintInOrder (){

  PrintInOrderPrivate (root);

}

void BST::PrintInOrderPrivate (node* Ptr){
  if (root != NULL){
    if (Ptr->left != NULL){
      PrintInOrderPrivate (Ptr->left);
    }
    cout << Ptr->key << " ";
    if (Ptr->right != NULL){
      PrintInOrderPrivate (Ptr->right);
    }
  }
  else{
    cout << "Tree is empty" << endl;
  }
}

BST::node* BST::ReturnNode (int key){

  return ReturnNodePrivate (key, root);
}

BST::node* BST::ReturnNodePrivate (int key, node* Ptr){
  if (Ptr != NULL){
    if (Ptr->key == key){
      return Ptr;
    }
    else{
      if (key < Ptr->key){
        return ReturnNodePrivate (key, Ptr->left);
      }
      else{
        return ReturnNodePrivate (key, Ptr->right);
      }
    }
  }
  else{
    return NULL;
  }
}

int BST::ReturnRoot (){
  if (root != NULL){
    return root->key;
  }
  else{
    return 0;
  }
}

void BST::PrintChildren (int key){
  node* Ptr = ReturnNode (key); // get the key value

  if (Ptr != NULL){
    cout << "Parent Node = " << Ptr->key << endl;

    if (Ptr->left == NULL){
      cout << "Left child is null" << endl;
    }
    else{
      cout << "Left child is " << Ptr->left->key << endl;
    }

    if (Ptr->right != NULL){
      cout << "Right child is " << Ptr->left->key << endl;
    }
    else{
      cout << "Right child is null" << endl;
    }
  }
  else {
    cout << "Key " << key << " is not in the tree" << endl;
  }
}

int BST::FindSmallest (){

  return FindSmallestPrivate (root);

}

int BST::FindSmallestPrivate (node* Ptr){
  if (root == NULL){
    cout << "Tree is empty" << endl;
    return -1000;
  }
  else{
    if (Ptr->left != NULL){ // check the left side, no need to check the right side since it has all the biggest numbers
      return FindSmallestPrivate (Ptr->left);
    }
    else{
      return Ptr->key;
    }
  }
}

void BST::remove (int key){

  return removePrivate (key, root);
}

void BST::removePrivate (int key, node* parent){
  if (root != NULL){
    if (root->key == key){
      removeMatchRoot ();
    }
    else {
      if (key < parent->key && parent->left != NULL){ // if the key is less than the current key and parent's left node is not null
        parent->left->key == key ?
        removeMatch (parent, parent->left, true) :
        removePrivate (key, parent->left);
      }
      else if (key > parent->key && parent->right != NULL){ // if the key is greater than the current key and parent's right node is not null
        parent->right->key == key ?
        removeMatch (parent, parent->right, false) :
        removePrivate (key, parent->right);
      }
      else{
        cout << "The key = " << key << " is not in the tree." << endl;
      }
    }
  }
  else{
    cout << "Tree is empty" << endl;
  }
}

void BST::removeMatchRoot (){
  if (root!=NULL){
    node* delPtr = root;
    int rootKey = root->key;
    int smallestRightSubTree;

    // Case 1: There is 0 child
    if (root->left == NULL && root->right == NULL){
      root = NULL;
      delete delPtr;
    }
    // Case 2: There is 1 child
    else if (root->left == NULL && root->right != NULL){
      root = root->right;
      delPtr->right = NULL;
      cout << "The root node with key " << rootKey << " was deleted. "
      << "The new root contains key " << root->key << endl;
    }
    else if (root->right == NULL && root->left != NULL){
      root = root->left;
      delPtr->left = NULL;
      cout << "The root node with key " << rootKey << " was deleted. "
      << "The new root contains key " << root->key << endl;
    }
    // Case 3: There is 2 children
    else{
      smallestRightSubTree = FindSmallestPrivate (root->right);
      removePrivate (smallestRightSubTree, root);
      root->key = smallestRightSubTree;
      cout << "The root key containing " << rootKey << " was overwritten with key " << root->key << endl;
    }
  }
  else{
    cout << "Cannot remove root...Tree is empty." << endl;
  }
}

void BST::removeMatch (node* parent, node* match, bool left){
  if (root != NULL){
    node* delPtr;
    int matchKey = match->key;
    int smallestInRightSubtree;

    //Case 1: There is 0 child.
    if (match->left == NULL && match->right == NULL){
      delPtr = match;
      left == true ? parent->left = NULL : parent->right = NULL;
      delete delPtr;
      cout << "The node containing key " << matchKey << " was removed." << endl;
    }
    //Case 2: There is 1 child
    else if (match->left == NULL && match->right != NULL){
      left == true ? parent->left = match->right : parent->right = match->left;
      match->right = NULL;
      delete match;
      cout << "The node containing key " << matchKey << " was removed." << endl;
    }
    else if (match->right == NULL && match->left != NULL){
      left == true ? parent->left = match->left : parent->right = match->right;
      match->left = NULL;
      delete match;
      cout << "The node containing key " << matchKey << " was removed." << endl;
    }
    //Case 3: There is 2 children
    else{
      smallestInRightSubtree = FindSmallestPrivate(match->right);
      removePrivate (smallestInRightSubtree, match);
      match->key = smallestInRightSubtree;
    }
  }
  else{
    cout << "Cannot remove. Tree is empty." << endl;
  }
}

BST::~BST (){
  removeSubtree (root);
}

void BST::removeSubtree (node* Ptr){
  if (Ptr != NULL){
    if (Ptr->left !=NULL){
      removeSubtree (Ptr->left);
    }
    if (Ptr->right != NULL){
      removeSubtree (Ptr->right);
    }
    cout << "Delete node is " << Ptr->key << endl;
    delete Ptr;
  }
}
