#include <iostream>
#include <vector>
#include <cstring>
#include <string> 
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Node{
public:
    int key;
    int color;
    Node *left;
    Node *right;
    Node *parent;

    Node(){
        color = 'R';
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    Node(int k){
        key = k;
        color = 'R';
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    ~Node(){}

    friend Node *leftRotate(Node *node){
        Node *x = node->right;
        Node *y = x->left;

        x->left = node;
        node->right = y;
        node->parent = x;

        if (y != NULL){
            y->parent = node;
        }
        return x;
    }

    friend Node *rightRotate(Node *node){
        Node *x = node->left;
        Node *y = x->right;

        x->right = node;
        node->left = y;
        node->parent = x;

        if (y != NULL){
            y->parent = node;
        }
        return x;
    }

    friend int getHeightNode(Node *node){
        if (node == NULL){
            return 0;
        }
        else {
            return max(getHeightNode(node->left), getHeightNode(node->right)) + 1;
        }
    }

};

class RBT{
public:
    Node *root;
    RBT(){
        root = NULL;
    }
    ~RBT(){}

    bool isLL = false, isRR = false, isLR = false, isRL = false;
    Node *insertChild(Node *node, int k){
        bool isColorConflict = false;

        if (node == NULL){
            Node *newNode = new Node(k);
            return newNode;
        }

        if (k < node->key){
            node->left = insertChild(node->left, k);
            node->left->parent = node;
            if (node != this->root){
                if (node->color == 'R' && node->left->color == 'R'){
                    isColorConflict = true;
                }
            }
            
        } else {
            node->right = insertChild(node->right, k);
            node->right->parent = node;
            if (node != this->root){
                if (node->color == 'R' && node->right->color == 'R'){
                    isColorConflict = true;
                }
            }
        }

        
        if (this->isLL){
            node = leftRotate(node);
            node->color = 'B';
            node->left->color = 'R';
            this->isLL = false;
        }
        else if (this->isRR){
            node = rightRotate(node);
            node->color = 'B';
            node->right->color = 'R';
            this->isRR = false;
        }
        else if (this->isRL){
            node->right = rightRotate(node->right);
            node->right->parent = node;
            node = leftRotate(node);
            node->color = 'B';
            node->left->color = 'R';
            this->isRL = false;
        }
        else if (this->isLR){
            node->left = leftRotate(node->left);
            node->left->parent = node;
            node = rightRotate(node);
            node->color = 'B';
            node->right->color = 'R';
            this->isLR = false;
        }

        if (isColorConflict){
            if (node->parent->right == node){
                if (node->parent->left == NULL || node->parent->left->color == 'B'){
                    if (node->left != NULL && node->left->color == 'R'){
                        this->isRL = true;
                    }
                    else if (node->right != NULL && node->right->color == 'R'){
                        this->isLL = true;
                    }
                }
                else {
                    node->parent->left->color = 'B';
                    node->color = 'B';
                    if (node->parent != this->root){
                        node->parent->color = 'R';
                    }
                }
            }
            else {
                if (node->parent->right == NULL || node->parent->right->color == 'B'){
                    if (node->left != NULL && node->left->color == 'R'){
                        this->isRR = true;
                    }
                    else if (node->right != NULL && node->right->color == 'R'){
                        this->isLR = true;
                    }
                }
                else {
                    node->parent->right->color = 'B';
                    node->color = 'B';
                    if (node->parent != this->root){
                        node->parent->color = 'R';
                    }
                }
            }
            isColorConflict = false;
        }
        return node;
    }

    void insert(int k){
        if (this->root == NULL){
            this->root = new Node(k);
            this->root->color = 'B';
        }
        else {
            this->root = insertChild(this->root, k);
        }
    }

    int getHeight(){
        if (this->root == NULL){
            return 0;
        }
        else {
            return getHeightNode(root);
        }
    }
};

int main(){

    string output = "output_RB_tree.txt" ;
    ofstream fo(output);

    for (int i = 1; i <= 10; i++)
    {
        string input = "test" + to_string(i) + ".txt";        
        ifstream fi(input);

        Node *root = NULL;

        int N;
        fi >> N;
        RBT tree;
        for (int i = 0; i < 1e6; i++)
            {
                int key;
                fi >> key;
                tree.insert(key);
            }
            
        fo << input << "\n";
        fo << "N = " << N << "\n";
        fo << "logN = " << log2(N) << "\n";
        fo << "1.45logN = " << 1.45 * log2(N) << "\n";
        fo << "Heigh of tree: " << tree.getHeight() << "\n";
        fo << endl;
    }
}