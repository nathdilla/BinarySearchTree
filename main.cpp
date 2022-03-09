// cst-210 - BinarySearchTree(BST) by Nathan Dilla
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node // bst node
{
    int data = NULL;
    struct node *left;
    struct node *right;
};

class BST
{
public:
    BST(){};                            // constructor
    node *insert(node *&temp, int data) // insert node O(n)
    {
        if (temp == NULL) // base case
        {
            cout << "place" << endl;
            node *newNode = new node(); // create new node, with data and left, right pointers are NULL
            newNode->left = newNode->right = NULL;
            newNode->data = data;
            temp = newNode; // set target pointer to new node
            return temp;    // return
        }
        else
        {
            if (data < temp->data) // if data is less, traverse down left
            {
                cout << "left" << endl;
                temp->left = insert(temp->left, data); // pointer defined by callback
            }
            else // traverse down right
            {
                cout << "right" << endl;
                temp->right = insert(temp->right, data);
            }
            return temp;
        }
    };
    node *search(node *&temp, int data)
    {
        if (temp == NULL || temp->data == data) // if node is null or found data then go back up with this node
        {
            return temp;
        }
        else
        {
            if (data < temp->data) // traverse left or right
            {
                return search(temp->left, data);
            }
            else
            {
                return search(temp->right, data);
            }
        }
    };
    void display(node *temp) // RPL o(n)
    {
        if (temp == NULL)
        {
            return;
        }
        else
        {
            display(temp->right);
            cout << temp->data;
            display(temp->left);
        }
    };
    int minVal(node *temp)
    {
        int min = temp->data;
        if (temp->left != NULL)
        {
            min = minVal(temp->left);
        }
        return min;
    };
    node *deleteNode(node *root, int data)
    {
        if (root == NULL)
        {
            return root;
        }
        // traverse tree
        if (data < root->data)
        {
            root->left = deleteNode(root->left, data); // left node defined by callback
        }
        else if (data > root->data)
        {
            root->right = deleteNode(root->right, data); // right node defined by callback
        }
        else
        {                            // equal
            if (root->right == NULL) // no right child
            {
                node *temp = root->left;
                delete root;
                return temp;
            }
            else if (root->left == NULL)
            { // no left child
                node *temp = root->right;
                delete root;
                return temp;
            }
            root->data = minVal(root->right);
            root->right = deleteNode(root->right, data);
        }
        return root;
    };
};

int main()
{
    BST myBst;
    node *root = NULL;
    myBst.insert(root, 5);
    myBst.insert(root, 6);
    myBst.insert(root, 2);
    myBst.insert(root, 4);
    myBst.insert(root, 1);
    myBst.insert(root, 7);
    myBst.insert(root, 3);
    myBst.insert(root, 8);
    node *fourPointer = myBst.search(root, 4);
    cout << fourPointer->data << endl;
    node *fivePointer = myBst.search(root, 5);
    cout << fivePointer->data << endl;
    cout << "*********display----" << endl;
    myBst.display(root);
    cout << endl;
    cout << myBst.minVal(root) << endl;
    myBst.deleteNode(root, 1);
    cout << "*********display----" << endl;
    myBst.display(root);
    myBst.deleteNode(root, 5);
    cout << "*********display----" << endl;
    myBst.display(root);
    cout << endl;

    // node *sixPointer = myBst.search(root, 6);
    // cout << sixPointer->data << endl;
}