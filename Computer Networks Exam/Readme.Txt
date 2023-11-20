Task Description
Scenario: FAST-NU's Library Administration

The library administration at FAST-NU is implementing a book issuance tracking system. As a computer network student, your task is to create a concurrent TCP server that manages book issuances and returns. The server should efficiently handle client requests and respond accordingly.

User Input:
The server sends a menu to the user.
Users respond with:
Pressing 1 or “one” to issue a book.
Pressing 2 or “two” to return a book.
Sample User Inputs:
Option 1: Book Issuance

Department: “CS”
Name of Student: “Ali Hassan”
Book: “Operating System”
Time: “08:30”
Option 2: Book Return

Department: “CS”
Name of Student: “Ali Hassan”
Book: “Operating System”
Time: “08:30”
Server Responses:
Issuing a Book:

Server response: "Book Operating System is issued by Ali Hassan from the CS department at 08:30"
Returning a Book:

Server response: "Book Operating System is returned by Ali Hassan from the CS department at 08:30"
Server Functionality:
The concurrent server must handle multiple clients.
It should appropriately process incoming requests (book issuance or return) and provide corresponding responses.
This task requires you to create a TCP server that can handle multiple client requests related to book issuance and returns. Design the server to interpret user inputs and respond accordingly, providing appropriate messages based on the actions initiated by the users.
