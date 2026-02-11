<img height="50" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

# Holberton School - Binary Trees

This project covers the implementation, traversal, and manipulation of various types of binary trees, including Binary Search Trees (BST), AVL Trees, and Max Binary Heaps.

## Tech Stack

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
![Valgrind](https://img.shields.io/badge/Valgrind-white?style=for-the-badge&logo=linux&logoColor=black)
![Vim](https://img.shields.io/badge/VIM-%2311AB00.svg?style=for-the-badge&logo=vim&logoColor=white)

---

## Tree Structures Implemented



### 1. Basic Binary Tree
Foundational operations for building and measuring trees.
* **Nodes & Insertion:** `0-binary_tree_node.c`, `1-insert_left.c`, `2-insert_right.c`.
* **Properties:** `9-height.c`, `10-depth.c`, `11-size.c`, `12-leaves.c`.
* **Checks:** `15-is_full.c`, `16-is_perfect.c`.

### 2. Traversals
* **Depth-First:** `6-preorder.c`, `7-inorder.c`, `8-postorder.c`.
* **Breadth-First:** `101-levelorder.c`.

### 3. Binary Search Tree (BST)
A binary tree where the left child is lesser and the right child is greater than the parent.
* **Operations:** `111-bst_insert.c`, `113-bst_search.c`, `114-bst_remove.c`.
* **Validation:** `110-is_bst.c`.

### 4. AVL Tree
A self-balancing binary search tree.
* **Operations:** `121-avl_insert.c`, `123-avl_remove.c`.
* **Rotations:** `103-rotate_left.c`, `104-rotate_right.c`.

### 5. Max Binary Heap
A complete tree where the root is always the maximum value.
* **Operations:** `131-heap_insert.c`, `133-heap_extract.c`.

---

## Time Complexity Analysis (Big O)

Understanding the efficiency of tree operations is a key requirement of this project. The following files document the average time complexity ($O(n)$) for various operations:

| File | Structure | Operations Analyzed |
| :--- | :--- | :--- |
| **115-O** | **BST** | Insertion, Searching, Deletion |
| **125-O** | **AVL Tree** | Insertion, Searching, Deletion |
| **135-O** | **Binary Heap** | Insertion, Extraction, Search |



> **Note:** For balanced trees (AVL), operations are typically $O(\log n)$, whereas unbalanced trees can degrade to $O(n)$.

## Requirements
* **Standard:** `C89` (compiled with `gcc 4.8.4`).
* **Style:** All files follow the **Betty** style guide.
* **Data Structures:** See `binary_trees.h` for the specific `struct` definitions used for nodes.

## How to Use
To compile any of the files, include the main test file and the library:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-binary_tree_node.c -o node_test
./node_test
```

## Author
**LEYLA KHASPOLADOVA**
GitHub: [@leyla009](https://github.com/leyla009)
