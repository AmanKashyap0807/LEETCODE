#include <iostream>
using namespace std;

// Class
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int main()
{
    // Creation
    Node *root = new Node(1);

    // Adding another node
    root->left = new Node(2);
    root->right = new Node(3);
    return 0;
}