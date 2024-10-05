#include <iostream>
#include <ctime>
#include <cstdlib>

// Node structure for the binary search tree
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// BST class with insert, delete, and search operations
class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    // Insert a key into the BST
    void insert(int key) {
        root = insertRec(root, key);
    }

    // Search for a key in the BST
    bool search(int key) {
        return searchRec(root, key);
    }

    // Delete a key from the BST
    void deleteKey(int key) {
        root = deleteRec(root, key);
    }

private:
    // Helper function to insert a key recursively
    Node* insertRec(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else if (key > node->key) {
            node->right = insertRec(node->right, key);
        }
        return node;
    }

    // Helper function to search for a key recursively
    bool searchRec(Node* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (node->key == key) {
            return true;
        } else if (key < node->key) {
            return searchRec(node->left, key);
        } else {
            return searchRec(node->right, key);
        }
    }

    // Helper function to find the minimum node
    Node* findMin(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function to delete a key recursively
    Node* deleteRec(Node* root, int key) {
        if (root == nullptr) return root;

        if (key < root->key) {
            root->left = deleteRec(root->left, key);
        } else if (key > root->key) {
            root->right = deleteRec(root->right, key);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteRec(root->right, temp->key);
        }
        return root;
    }
};

// Function to generate a random integer within a range
int getRandomKey(int lower, int upper) {
    return lower + rand() % (upper - lower + 1);
}

int main() {
    BinarySearchTree bst;
    const int numKeys = 50000;   // Number of keys to insert
    const int searchKeys = 5000; // Number of random searches
    const int keyRange = 100000; // Range for generating random keys

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // 1. Insert 50,000 random keys into the BST
    std::cout << "Inserting " << numKeys << " keys into the BST...\n";
    clock_t insertStart = clock();
    for (int i = 0; i < numKeys; ++i) {
        int key = getRandomKey(1, keyRange);
        bst.insert(key);
    }
    clock_t insertEnd = clock();
    double insertTime = static_cast<double>(insertEnd - insertStart) / CLOCKS_PER_SEC;
    std::cout << "Insertion completed in " << insertTime << " seconds.\n";

    // 2. Perform 5000 random searches in the BST
    std::cout << "Performing " << searchKeys << " random searches...\n";
    clock_t searchStart = clock();
    int foundCount = 0;
    for (int i = 0; i < searchKeys; ++i) {
        int key = getRandomKey(1, keyRange);
        if (bst.search(key)) {
            ++foundCount;
        }
    }
    clock_t searchEnd = clock();
    double searchTime = static_cast<double>(searchEnd - searchStart) / CLOCKS_PER_SEC;
    std::cout << "Search completed in " << searchTime << " seconds.\n";
    std::cout << foundCount << " keys were found out of " << searchKeys << " searches.\n";

    return 0;
}