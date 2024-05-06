#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Tree Node structure
struct TreeNode {
    string data;
    vector<TreeNode*> children;

    // Constructor
    TreeNode(const string& d) : data(d) {}
};

// Function to print nodes recursively
void printNodes(TreeNode* root, int depth = 0) {
    if (root == nullptr)
        return;

    // Print the node with appropriate indentation
    cout << string(depth, '-') << root->data << endl;

    // Recursively print children
    for (TreeNode* child : root->children)
        printNodes(child, depth + 1);
}

int main() {
    // Constructing the tree
    TreeNode* book = new TreeNode("Book");
    TreeNode* chapter1 = new TreeNode("Chapter 1");
    TreeNode* section1_1 = new TreeNode("Section 1.1");
    TreeNode* section1_2 = new TreeNode("Section 1.2");
    TreeNode* chapter2 = new TreeNode("Chapter 2");
    TreeNode* section2_1 = new TreeNode("Section 2.1");
    TreeNode* subsection2_1_1 = new TreeNode("Subsection 2.1.1");
    TreeNode* subsection2_1_2 = new TreeNode("Subsection 2.1.2");

    // Constructing the tree structure
    book->children.push_back(chapter1);
    book->children.push_back(chapter2);

    chapter1->children.push_back(section1_1);
    chapter1->children.push_back(section1_2);

    chapter2->children.push_back(section2_1);
    section2_1->children.push_back(subsection2_1_1);
    section2_1->children.push_back(subsection2_1_2);

    // Print the nodes of the tree
    cout << "Nodes of the book structure:" << endl;
    printNodes(book);

    // Deallocate memory (optional)
    delete book;
    delete chapter1;
    delete section1_1;
    delete section1_2;
    delete chapter2;
    delete section2_1;
    delete subsection2_1_1;
    delete subsection2_1_2;

    return 0;
}
