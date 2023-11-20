Computer Networks Lab: Week 4 - Socket Programming - UDP Client-Server
Overview
This lab session revolves around understanding Socket Programming, particularly focusing on UDP (User Datagram Protocol) Client-Server interaction. The exercises aim to illustrate the fundamentals of socket functionality, types, communication models, and the implementation of UDP-based applications.

Socket Programming Basics
Purpose
Socket programming is integral for constructing various network applications, including web browsers like Internet Explorer and Firefox, along with web apps such as chat, mail, and file transfer applications.

What is a Socket?
A socket serves as an endpoint for inter-process communication, analogous to file operations.
Contains an address (IP and Port) facilitating communication between application processes, local or remote.
TCP & UDP
Difference between UDP and TCP: Exploring where each protocol is suitable and their respective applications.
Applications of UDP & TCP: Illustrating the scenarios suitable for UDP and TCP-based applications.
Socket Types
Stream Sockets (SOCK_STREAM): Dependent on TCP for reliable, two-way connected communication.
Datagram Sockets (SOCK_DGRAM): Leverage UDP with an unreliable, connectionless approach.
Functions Used in Socket Programming
Socket programming relies on functions like socket(), bind(), listen(), connect(), accept(), send(), recv(), and close() to manage communication endpoints and data transfer.

Lab Tasks
Task Details
This lab comprises several questions and tasks that involve designing UDP-based client-server applications for specific functionalities, including two-way communication, checking palindrome strings, and string reversal.

Questions Overview
UDP Client-Server Two-Way Communication: Implement a pair of UDP client/server programs showcasing bidirectional communication, displaying the received message's byte count.
Check Palindrome via UDP: Design an iterative UDP server to check if an input string is a palindrome.
Reverse String via UDP: Create an iterative UDP server to reverse an input string; the server handles five clients without exiting.
Conclusion
Thank you for engaging in this Computer Networks Lab session, delving into the essentials of Socket Programming and UDP Client-Server interaction. Use the provided tasks to deepen your understanding and practical application of these concepts.
