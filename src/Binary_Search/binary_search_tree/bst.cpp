#include <iostream>
#include <queue>
#include <algorithm>

class BST{
private:
    struct Node{
        int data;
        Node* left;
        Node* right;

        Node(int val) : data(val), left(nullptr), right(nullptr){}
    };

    Node* root;

    Node* insert(Node* node, int value){
        if(!node) return new Node(value);
        
        if(value < node->data){
            node->left = insert(node->left,value);
        }
        else if(value > node->data){
            node->right = insert(node->right,value);
        }

        return node;
    }

    bool search(Node* node, int value){
        if(!node) return false;

        if(node->data == value) return true;

        if(node->data > value) 
            return search(node->left,value);
        else if(node->data < value) 
            return search(node->right,value);
    }

    // TREE Traversal

    void inorder(Node* node){
        if(!node) return;

        inorder(node->left);
        std::cout<<node->data<<" ";
        inorder(node->right);
    }

    void preorder(Node* node){
        if(!node) return;

        std::cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node){
        if(!node) return;
        
        postorder(node->left);
        postorder(node->right);
        std::cout<<node->data<<" ";
    }

    void levelorder(Node* node){
        if(!node) return;
        
        std::queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            int sz = static_cast<int>(q.size());

            for(int i = 0;i<sz;i++){
                Node* nd = q.front();q.pop();
                std::cout<<nd->data<<" ";
                
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
            }
        }
    }

    // BST Analysis Functions

    Node* findMin(Node* node){
        if(!node->left) return node;
        
        return findMin(node->left);
    }

    int findMax(Node* node){
        if(!node->right) return node->data;

        return findMax(node->right);
    }

    int countNode(Node* node){
        if(!node) return 0;

        int left = countNode(node->left);
        int right = countNode(node->right);

        return 1 + left + right;
    }

    int countLeaf(Node* node){
        if(!node) return 0;

        if(!node->left && !node->right) return 1;

        return countLeaf(node->left) + countLeaf(node->right);
    }

    int height(Node* node){
        if(!node) return 0;

        int left = height(node->left);
        int right = height(node->right);

        return 1 + std::max(left,right);
    }


    // DELETION

    Node* deleteNode(Node* node, int value){
        if(!node) return nullptr;

        if(value < node->data) node->left = deleteNode(node->left,value);
        else if(value > node->data) node->right = deleteNode(node->right,value);
        else{
            //case 1: Delete Leaf node

            if(!node->left && !node->right){
                delete node;
                return nullptr;
            }
            
            //case 2a: only right child
            if(!node->left){
                Node* tmp = node->right;
                delete node;
                return tmp;
            }
            
            //case 2b: only left child
            if(!node->right){
                Node* tmp = node->left;
                delete node;
                return tmp;
            }

            //case 3: two children
            Node* successor = findMin(node->right);
            
            node->data = successor->data;

            node->right = deleteNode(node->right, successor->data);
        }

        return node;
    }
};