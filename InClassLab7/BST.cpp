#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};


// Creating a new node
struct node *createNode(int val){
  node *temp = new node();
  temp->key = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}


// Inorder traversal
void traverseInOrder(struct node *root) {

  if (root == NULL){
    return;
  }
  else{
    traverseInOrder(root->left);
    cout<<root->key<<" ";
    traverseInOrder(root->right);
  }  
}


// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == NULL){
      return createNode(key);
    }
    else if (key < node->key){
      node->left = insertNode(node->left, key);
    }
    else{
      node->right = insertNode(node->right, key);
    }
    return node;
}


// Returns the node with minimum key value
struct node *minValueNode(struct node *node){
    struct node *current = node;
    while (current->left != NULL){
        current = current -> left;
    }
    return current;
}  


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root ==NULL){
        return root;
    }
    else if (key < root->key){
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key){
        root->right = deleteNode(root->right, key);
    
    }
    else{
        //no child
        if (root->left == NULL and root->right == NULL){
            return NULL;
        }
        
        //with only right Child
        else if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        
        //with only left child
        else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        
        //with a Node with two children
        else{
            struct node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}



// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:  
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}