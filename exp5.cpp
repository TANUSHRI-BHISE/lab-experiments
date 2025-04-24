//Problem Statement: Construct an expression tree from the given prefix expression eg. +--
//a*bc/def and traverse it using post order traversal (non-recursive) and then delete the entire tree.

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};

class ExpressionTree {
public:
    // Function to construct the expression tree from prefix expression
    Node* constructTree(const string& prefix) {
        stack<Node*> st;
        int n = prefix.size();

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            char symbol = prefix[i];

            Node* node = new Node(symbol);

            // If the symbol is an operator
            if (isOperator(symbol)) {
                node->left = st.top(); st.pop();
                node->right = st.top(); st.pop();
            }

            st.push(node);
        }

        return st.top();
    }

    // Non-recursive postorder traversal using two stacks
    void postOrderTraversal(Node* root) {
        if (!root) return;

        stack<Node*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            Node* node = st1.top();
            st1.pop();
            st2.push(node);

            if (node->left) st1.push(node->left);
            if (node->right) st1.push(node->right);
        }

        while (!st2.empty()) {
            cout << st2.top()->data << " ";
            st2.pop();
        }
        cout << endl;
    }

    // Delete the entire tree
    void deleteTree(Node* root) {
        if (!root) return;

        deleteTree(root->left);
        deleteTree(root->right);

        delete root;
    }

private:
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
};

int main() {
    string prefix = "+--a*bc/def";

    ExpressionTree expTree;
    Node* root = expTree.constructTree(prefix);

    cout << "Postorder Traversal (Non-Recursive): ";
    expTree.postOrderTraversal(root);

    expTree.deleteTree(root);

    return 0;
}
