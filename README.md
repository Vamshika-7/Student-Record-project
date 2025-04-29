# Student-Record-project
# 🎓 Student Record Management System

A simple C++ project to manage student records using file handling. It allows adding, viewing, modifying, searching, and deleting student details such as name, roll number, course, email, contact number, address, and marks.

## 📌 Features

- 📥 **Insert** new student records with validation (duplicate roll number check, valid marks).
- 📃 **Display** all student records with pass/fail based on marks.
- 🛠️ **Modify** an existing student record based on roll number.
- 🔍 **Search** for a student by roll number.
- 🗑️ **Delete** a student record using roll number.
- 💾 Data is stored in a file (`StudentRecord.txt`) for persistence.

## 🛠️ Technologies Used

- Language: **C++**
- Concepts: File Handling, Classes and Objects, Loops, Conditionals

## 📁 File Structure

```plaintext
📦 StudentRecordManagement
 ┣ 📜 StudentRecord.txt        # Stores student data
 ┣ 📜 Record.txt               # Temporary file used for modify/delete
 ┗ 📄 main.cpp                 # Contains the complete code

▶️ How to Run
Open the code in any C++ compiler (Turbo C++, Code::Blocks, Dev C++, or g++).

Compile and run the main.cpp file.

Follow the menu in the terminal.

🧑‍💻 Sample Menu Options
text
Copy code
1. Enter New Record
2. Display Record
3. Modify Record
4. Search Record
5. Delete Record
6. Exit
✅ Input Validation
Marks must be between 0 and 100.

Duplicate roll numbers are not allowed.

📝 Sample Student Record Format
text
Copy code
Name RollNo Course Email Contact Address Marks
Example:

nginx
Copy code
Vamshika 102 CS vamshi@example.com 9876543210 Khammam 87
