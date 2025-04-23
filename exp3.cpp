#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Tree node definition
class Node {
public:
    string data;
    vector<Node*> children;

    Node(string value) {
        data = value;
    }

    ~Node() {
        for (Node* child : children)
            delete child;
    }
};

// Function to print the tree level-wise
void printLevelWise(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            for (Node* child : current->children)
                q.push(child);
        }

        cout << endl; // new line after each level
    }
}

int main() {
    // Book (root)
    Node* book = new Node("Book");

    // Chapters
    Node* chapter1 = new Node("Chapter 1");
    Node* chapter2 = new Node("Chapter 2");
    book->children.push_back(chapter1);
    book->children.push_back(chapter2);

    // Sections in Chapter 1
    Node* section1_1 = new Node("Section 1.1");
    Node* section1_2 = new Node("Section 1.2");
    chapter1->children.push_back(section1_1);
    chapter1->children.push_back(section1_2);

    // Sections in Chapter 2
    Node* section2_1 = new Node("Section 2.1");
    chapter2->children.push_back(section2_1);

    // Subsections under Section 1.1
    Node* subsection1_1_1 = new Node("Subsection 1.1.1");
    section1_1->children.push_back(subsection1_1_1);

    // Print the tree
    cout << "Tree (Book > Chapter > Section > Subsection):\n";
    printLevelWise(book);

    // Clean up memory
    delete book;

    return 0;
}
