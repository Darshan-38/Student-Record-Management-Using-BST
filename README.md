# Student Record Management Using BST

A console-based Student Record Management System developed in C using the Binary Search Tree (BST) data structure.

The project demonstrates efficient storage and management of student records through BST operations such as insertion, deletion, searching, updating, and traversal.

---

## Features

- Insert student records
- Search student by roll number
- Update student information
- Delete student records
- Inorder traversal
- Preorder traversal
- Postorder traversal
- Dynamic memory allocation
- Binary Search Tree implementation

---

## Data Structure Used

This project uses a Binary Search Tree (BST) where:

- Each node stores:
  - Student Name
  - Roll Number
- Left subtree contains smaller roll numbers
- Right subtree contains larger roll numbers

This allows efficient searching, insertion, and deletion operations.

---

## Operations Supported

| Operation | Description |
|-----------|-------------|
| Insert | Add a new student record |
| Search | Find a student by roll number |
| Update | Modify student name |
| Delete | Remove a student record |
| Inorder | Display records in sorted order |
| Preorder | Display BST in preorder traversal |
| Postorder | Display BST in postorder traversal |

---

## Project Structure

```text
Student-Record-Management-Using-BST/
│
├── student_bst.c
└── README.md
```

---

## How to Run

### Compile

```bash
gcc student_bst.c -o student_bst
```

### Execute

```bash
./student_bst
```

For Windows:

```bash
gcc student_bst.c -o student_bst.exe
student_bst.exe
```

---

## Sample Menu

```text
Main Menu

1. Enter Data
2. Inorder Display
3. Preorder Display
4. Postorder Display
5. Search Data
6. Update Data
7. Delete Record
0. Exit
```

---

## Concepts Demonstrated

- Structures in C
- Dynamic Memory Allocation
- Binary Search Trees
- Recursion
- Tree Traversals
- Data Management Systems

---

## Author

Darshan
