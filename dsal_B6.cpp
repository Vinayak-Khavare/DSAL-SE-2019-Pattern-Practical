#include <iostream>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
private:
    node *root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(int data)
    {
        if (root == nullptr)
        {
            root = new node(data);
            return;
        }

        node *temp = root;
        while (true)
        {
            if (data < temp->data)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new node(data);
                    return;
                }
                temp = temp->left;
            }
            else if (data > temp->data)
            {
                if (temp->right == nullptr)
                {
                    temp->right = new node(data);
                    return;
                }
                temp = temp->right;
            }
            else
            {
                // Handle duplicate values (optional)
                return;
            }
        }
    }

    int longestpath()
    {
        if (root == nullptr)
        {
            return 0;
        }

        int depth = 0;
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            depth++;
            int levelsize = q.size();
            for (int i = 0; i < levelsize; i++)
            {
                node *temp = q.front();
                q.pop();

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }

                if (temp->left == nullptr && temp->right == nullptr)
                {
                    return depth;
                }
            }
        }
    }

    int findmin()
    {
        const int MAX_INT_VALUE = 2147483647;
        if (root == nullptr)
        {
            return MAX_INT_VALUE; // Handle empty tree case
        }

        node *temp = root;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp->data;
    }

    void mirror()
    {
        if (root == nullptr)
            return;

        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *current = q.front();
            q.pop();

            // Swap left and right children
            node *temp = current->left;
            current->left = current->right;
            current->right = temp;

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }

    bool search(int value)
    {
        if (root == nullptr)
        {
            return false;
        }

        node *temp = root;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return true;
            }
            else if (temp->data < value)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        return false;
    }

    void preorder()
    {
        stack<node *> s;
        s.push(root);

        while (!s.empty())
        {
            node *temp = s.top();
            s.pop();

            cout << "-" << temp->data << "-";

            if (temp->right)
            {
                s.push(temp->right);
            }
            if (temp->left)
            {
                s.push(temp->left);
            }
        }
    }

    void inorder()
    {
        stack<node *> s;
        node *curr = root;

        while (curr != nullptr || !s.empty())
        {
            while (curr != nullptr)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();

            cout << "-" << curr->data << "-";

            curr = curr->right;
        }
    }

    void postorder()
    {
        if (root == nullptr)
            return;

        node* temp = root;
        stack<node *> s;
        node *lastVisited = nullptr;

        while (temp != nullptr || !s.empty())
        {
            if (temp != nullptr)
            {
                s.push(temp);
                temp = temp->left;
            }
            else
            {
                node *peekNode = s.top();

                if (peekNode->right != nullptr && lastVisited != peekNode->right)
                {
                    temp = peekNode->right;
                }
                else
                {
                    cout << "-" << peekNode->data << "-";
                    lastVisited = peekNode;
                    s.pop();
                }
            }
        }
    }
};


int main()
{
    BinarySearchTree bst;

    bst.insert(4);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(10);

    int min_ele = bst.findmin();
    cout << "Minimum Element: " << min_ele << endl;

    cout << "depth: " << bst.longestpath() << endl;

    cout << "Searching 5...";
    if (bst.search(5))
    {
        cout << "Found!!" << endl;
    }
    else
    {
        cout << "Not found!!" << endl;
    }

    // cout << endl;
    cout << "preorder: ";
    bst.preorder();
    cout << endl << "postorder: ";
    bst.postorder();    

    cout << "\nBefore mirror:" << endl;
    bst.inorder(); // Display the tree before mirroring

    bst.mirror();

    cout << "\nAfter mirror:" << endl;
    bst.inorder(); // Display the tree after mirroring

    return 0;
}
