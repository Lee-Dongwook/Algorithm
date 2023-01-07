#include <iostream>
using namespace std;

struct Node{
    Node *left, *right;
    int value;
};

class BinarySearchTree{
    public:
    BinarySearchTree():root(nullptr){};
    ~BinarySearchTree(){}

    void addNode(int value);
    bool searchValue(int value);
    void removeNode(int value);
    void show();
    void InOrder(Node *current);
    void PreOrder(Node *current);
    void PostOrder(Node * current);
    Node *searchMaxNode(Node *node);
    Node *removeSequence(Node *node, int value);
    private:
    Node *root;
    Node *tail;
};

void BinarySearchTree :: addNode(int value)
{
    Node *node = new Node();
    Node *tmpRoot = nullptr;

    node -> value = value;
    if(root == nullptr)
        root = node;
    else{
        Node *ptr = root;
        while(ptr != nullptr)
        {
            tmpRoot = ptr;
            if(node -> value < ptr -> value)
            {
                ptr = ptr -> left;
            }
            else{
                ptr = ptr ->right;
            }

        }
        if(node -> value < tmpRoot -> value)
        {
            tmpRoot -> left = node;
        }
        else{
            tmpRoot -> right = node;
        }
    }
}

Node * BinarySearchTree :: removeSequence(Node *node, int _value)
{
    if(node == nullptr)return node;
    else if(node -> value > _value)
    {
        node -> left = removeSequence(node -> left, _value);
    }
    else if(node -> value < _value)
    {
        node -> right = removeSequence(node -> right, _value);
    }
    else{
        Node *ptr = node;
        if(node -> right == nullptr && node -> left == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (node -> right == nullptr)
        {
            node = node -> left;
            delete ptr;
        }
        else if (node -> left == nullptr)
        {
            node = node -> right;
            delete ptr;
        }
        else
        {
            ptr = searchMaxNode(node -> left);
            node -> value = ptr -> value;
            node -> left = removeSequence(node -> left, ptr->value);
        }
    }

    return node;
}

void BinarySearchTree::removeNode(int value)
{
    Node *ptr = root;
    removeSequence(ptr, value);
}

bool BinarySearchTree::searchValue(int value)
{
    Node *ptr = root;
    Node *tmpRoot = nullptr;
    while(ptr != nullptr)
    {
        if(ptr -> value == value)
        {
            cout << value << "Found"<< endl;
            return true;
        }
        else if(ptr -> value > value)
        {
            ptr = ptr -> left;
        }
        else{
            ptr = ptr -> right;
        }

    }

    cout << value << "not Found"<< endl;
    return false;
}

void BinarySearchTree::PreOrder(Node *current)
{
    cout << current -> value;
    if(current -> left != NULL)
    {
        PreOrder(current->left);
    }
    if(current->right !=NULL)
    {
        PreOrder(current->right);
    }
}

void BinarySearchTree::InOrder(Node *current)
{
    if(current->left !=NULL)
    {
        InOrder(current->left);
    }
    cout << current -> value;
    if(current->right !=NULL)
    {
        InOrder(current->right);
    }
}
void BinarySearchTree::PostOrder(Node *current)
{
    if(current -> left !=NULL)
    {
        PostOrder(current ->  left);
    }
    if(current -> right != NULL)
    {
        PostOrder(current ->  right);
    }
    cout << current -> value;
}

void BinarySearchTree::show()
{
    cout<<"("<<root->value<<")"<<endl;
}