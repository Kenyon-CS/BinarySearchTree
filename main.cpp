#include <iostream>

// Node class representing a node in the binary search tree
class Node {
public:
    int key;
    Node* left;
    Node* right;

    // Constructor to initialize the node
    Node(int item) : key(item), left(nullptr), right(nullptr) {}
};

// Utility function to perform an inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

// Utility function to insert a new node with a given key into the BST
Node* insertNode(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);

    return root;
}

// Utility function to find the node with the minimum key value in the BST
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// Function to delete a node with a given key and return the new root
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node to be deleted found
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: find the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);
        root->key = temp->key;  // Copy the inorder successor's key to this node
        root->right = deleteNode(root->right, temp->key);  // Delete the inorder successor
    }
    return root;
}

// Main function to demonstrate BST insertion, deletion, and traversal
int main() {
    Node* root = nullptr;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    std::cout << "Inorder traversal of the given tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Perform deletions
    std::cout << "\nDeleting 20\n";
    root = deleteNode(root, 20);
    std::cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "\nDeleting 30\n";
    root = deleteNode(root, 30);
    std::cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "\nDeleting 50\n";
    root = deleteNode(root, 50);
    std::cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
