# Overview
The Classroom Management System is an application designed to facilitate the management of classrooms, teachers, students, assignments, and submissions. It provides functionalities for user authentication, class creation, assignment management, and submission tracking.

#Features
* User Management: Registration and authentication for students and teachers.
* Class Management: Create, view, update, and delete classes.
* Assignment Management: Create, manage, and evaluate assignments.
* Submission Management: Track and manage student submissions, including grading and feedback.

# Structure
The project is organized into several classes, each encapsulating different aspects of the system:
* User: Base class for user attributes and methods.
* Student and Teacher: Derived classes from User with additional properties and authentication methods.
* Class: Manages class details, roster, and file handling.
* Assignment: Manages assignment details and deadlines.
* Submission: Manages submission details and feedback.
* ClassManagement: Manages a collection of classes.

# File Overview
# Headers
* User.h
* Student.h
* Teacher.h
* Class.h
* Assignment.h
* Submission.h
* ClassManagement.h

# Source Files
* User.cpp
* Student.cpp
* Teacher.cpp
* Class.cpp
* Assignment.cpp
* Submission.cpp
* ClassManagement.cpp
* main.cpp

# Getting Started
# Prerequisites
Ensure you have a C++ compiler installed on your system.

# Usage
* Login/Register: On starting the application, you can choose to log in or register a new user.
* Class Management: After login, you can create, view, update, or delete classes.
* Assignment Management: Teachers can create and manage assignments.
* Submission Management: Students can submit assignments, and teachers can grade and provide feedback.
# File Handling
The system uses file handling for storing user credentials, class details, and submission data
