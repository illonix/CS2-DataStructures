#include "btree.hpp"
#include <iostream>

int main() {
    // Create an empty binary tree
    btree<int> tree;

    // Structure of the tree:
    //         8
    //       /    \
    //      4      55
    //     / \    /  \
    //    1   7  16   87
    //    \      /    / \
    //    2      9   64 99

    tree.insert(8);
    tree.insert(4);
    tree.insert(55);
    tree.insert(1);
    tree.insert(2);
    tree.insert(7);
    tree.insert(16);
    tree.insert(9);
    tree.insert(87);
    tree.insert(64);
    tree.insert(99);


    // Demonstrate find function
    std::cout << "Demonstrating find function:" << std::endl;
    std::cout << "Find 8: " << (tree.find(8) ? "Found" : "Not Found") << std::endl;
    std::cout << "Find 99: " << (tree.find(99) ? "Found" : "Not Found") << std::endl;
    std::cout << "Find 16: " << (tree.find(16) ? "Found" : "Not Found") << std::endl;

    // Demonstrate findDepth function
    std::cout << "Demonstrating findDepth function:" << std::endl;
     // Test 1: Depth of root
    std::cout << "Depth of 8 (root): " << tree.findDepth(8) << std::endl;
    // Test 2: Depth of a left child
    std::cout << "Depth of 4: " << tree.findDepth(4) << std::endl;
    // Test 3: Depth of a deeper node
    std::cout << "Depth of 87: " << tree.findDepth(87) << std::endl;
    // Test 3: Depth of a deepest node
    std::cout << "Depth of 99: " << tree.findDepth(99) << std::endl;



    // Demonstrate inorder traversal
    std::cout << "\nInorder Traversal:" << std::endl;
    tree.inorder(std::cout);
    std::cout << std::endl;

    // Demonstrate preorder traversal
    std::cout << "\nPreorder Traversal:" << std::endl;
    tree.preorder(std::cout);
    std::cout << std::endl;

    // Demonstrate postorder traversal
    std::cout << "\nPostorder Traversal:" << std::endl;
    tree.postorder(std::cout);
    std::cout << std::endl;

    return 0;
}