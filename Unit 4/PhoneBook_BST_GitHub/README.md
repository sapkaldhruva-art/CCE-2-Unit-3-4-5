# Phone Book Application Using Binary Search Tree (BST)

## Project Description
This is a menu-driven C++ phone book application that stores contacts in a Binary Search Tree (BST). Each contact contains a name and phone number. Names are used as BST keys.

## Features
1. Insert a contact.
2. Search for a contact by name.
3. Display all contacts in alphabetical order.
4. Find the first name alphabetically.
5. Find the last name alphabetically.
6. Update the phone number when a contact with the same name is entered.

## Data Structure
A **Binary Search Tree (BST)** is used:
- Names alphabetically smaller than a node are stored in its left subtree.
- Names alphabetically greater than a node are stored in its right subtree.
- In-order traversal (Left, Root, Right) displays contacts in alphabetical order.
- The leftmost node contains the first name alphabetically.
- The rightmost node contains the last name alphabetically.

## Requirements
- A C++ compiler such as g++.
- Any code editor or IDE (VS Code, Code::Blocks, Dev-C++, etc.).



## Sample Run
```text
========== PHONE BOOK USING BST ==========
1. Add Contact
2. Search Contact
3. Display Contacts (Alphabetical)
4. Find First Name
5. Find Last Name
0. Exit
Enter your choice: 1
Enter name: Rahul
Enter phone number: 9876543210
Contact added successfully (or updated if name already existed).

Enter your choice: 1
Enter name: Aditi
Enter phone number: 9123456780
Contact added successfully (or updated if name already existed).

Enter your choice: 1
Enter name: Zoya
Enter phone number: 9988776655
Contact added successfully (or updated if name already existed).

Enter your choice: 3

--- Contacts in Alphabetical Order ---
Name: Aditi | Phone: 9123456780
Name: Rahul | Phone: 9876543210
Name: Zoya | Phone: 9988776655

Enter your choice: 4
First name alphabetically: Aditi | Phone: 9123456780

Enter your choice: 5
Last name alphabetically: Zoya | Phone: 9988776655
```

## Time Complexity
Let `n` be the number of contacts:
- Insertion: average `O(log n)`, worst case `O(n)`.
- Searching: average `O(log n)`, worst case `O(n)`.
- Alphabetical display: `O(n)`.
- Finding first or last name: `O(h)`, where `h` is the height of the tree.

## Notes
- Name comparisons are case-sensitive, so `Aditi` and `aditi` are treated as different keys.
- Contacts are stored in memory while the program runs. They are not saved to a file after exiting.
