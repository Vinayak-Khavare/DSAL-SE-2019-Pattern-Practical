#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    string keyword;
    string meaning;
    int height;
    Node* left;
    Node* right;
};

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

// Function to update the height of a node
void updateHeight(Node* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Function to perform right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to create a new node
Node* createNode(string keyword, string meaning) {
    Node* newNode = new Node;
    newNode->keyword = keyword;
    newNode->meaning = meaning;
    newNode->height = 1;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into the AVL tree
Node* insertNode(Node* node, string keyword, string meaning) {
    if (node == nullptr) return createNode(keyword, meaning);

    if (keyword < node->keyword)
        node->left = insertNode(node->left, keyword, meaning);
    else if (keyword > node->keyword)
        node->right = insertNode(node->right, keyword, meaning);
    else // Duplicate keywords not allowed
        return node;

    updateHeight(node);

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && keyword < node->left->keyword)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && keyword > node->right->keyword)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && keyword > node->left->keyword) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && keyword < node->right->keyword) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to find the node with minimum value in a tree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* root, string keyword) {
    if (root == nullptr) return root;

    if (keyword < root->keyword)
        root->left = deleteNode(root->left, keyword);
    else if (keyword > root->keyword)
        root->right = deleteNode(root->right, keyword);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->keyword = temp->keyword;
            root->right = deleteNode(root->right, temp->keyword);
        }
    }

    if (root == nullptr) return root;

    updateHeight(root);

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to update the meaning of a keyword
Node* updateMeaning(Node* root, string keyword, string newMeaning) {
    root = deleteNode(root, keyword);
    root = insertNode(root, keyword, newMeaning);
    return root;
}

// Function to display the AVL tree in ascending order
void displayAscending(Node* root) {
    if (root == nullptr) return;
    displayAscending(root->left);
    cout << root->keyword << ": " << root->meaning << endl;
    displayAscending(root->right);
}

// Function to display the AVL tree in descending order
void displayDescending(Node* root) {
    if (root == nullptr) return;
    displayDescending(root->right);
    cout << root->keyword << ": " << root->meaning << endl;
    displayDescending(root->left);
}

// Function to find a keyword in the AVL tree and count comparisons
int findKeyword(Node* root, string keyword, int& comparisons) {
    if (root == nullptr) return -1;

    comparisons++;

    if (keyword == root->keyword)
        return comparisons;
    else if (keyword < root->keyword)
        return findKeyword(root->left, keyword, comparisons);
    else
        return findKeyword(root->right, keyword, comparisons);
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, "apple", "a fruit");
    root = insertNode(root, "banana", "a yellow fruit");
    root = insertNode(root, "cherry", "a red fruit");
    root = insertNode(root, "date", "a sweet fruit");
    root = insertNode(root, "fig", "a small fruit");

    cout << "Ascending Order:" << endl;
    displayAscending(root);

    cout << "\nDescending Order:" << endl;
    displayDescending(root);

    int comparisons = 0;
    string keywordToFind = "banana";
    int result = findKeyword(root, keywordToFind, comparisons);

    if (result != -1)
        cout << "\nFound " << keywordToFind << " in " << result << " comparisons." << endl;
    else
        cout << "\nKeyword " << keywordToFind << " not found." << endl;

    return 0;
}
