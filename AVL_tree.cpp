#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class Node{
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(){
        left = NULL;
        right = NULL;
        height = 0;
    }

    Node(int k){
        key = k;
        left = NULL;
        right = NULL;
        height = 1;
    }

    ~Node(){}

    friend Node* newNode(int k){
        Node* node = new Node(k);
        return node;
    }

    friend int getHeight(Node *N){
        if (N == NULL){
            return 0;
        }
        return N->height;
    }

    friend Node *rightRotate(Node *y){
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    friend Node *leftRotate(Node *x){
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    friend int getBalance(Node *N){
        if (N == NULL){
            return 0;
        }
        return getHeight(N->left) - getHeight(N->right);
    }

};

Node* insert(Node *node, int k){
    if (node == NULL){
        Node* newnode = new Node(k);
        return newnode;
    }
    if (k < node->key){
        node->left = insert(node->left, k);
    } else {
        node->right = insert(node->right, k);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && k < node->left->key){
        return rightRotate(node);
    }

    if (balance < -1 && k >= node->right->key){
        return leftRotate(node);
    }

    if (balance > 1 && k >= node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && k < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


int main(){

    string output = "output_AVL_tree.txt" ;
    ofstream fo(output);

    for (int i = 1; i <= 10; i++)
    {
        string input = "test" + to_string(i) + ".txt";        
        ifstream fi(input);

        Node *root = NULL;

        int N;
        fi >> N;

        for (int i = 0; i < 1e6; i++)
            {
                int key;
                fi >> key;
                root = insert(root, key);
            }
            
        fo << input << "\n";
        fo << "N = " << N << "\n";
        fo << "logN = " << log2(N) << "\n";
        fo << "1.45logN = " << 1.45 * log2(N) << "\n";
        fo << "Heigh of tree: " << getHeight(root) << "\n";
        fo << endl;
    }
}