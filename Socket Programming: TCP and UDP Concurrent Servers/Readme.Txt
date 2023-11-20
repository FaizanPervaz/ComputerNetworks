Socket Programming: TCP and UDP Concurrent Servers
Outline
This lab session explores the concepts of iterative servers, utilizing fork(), implementing concurrent servers, and managing child servers in the context of TCP and UDP communication models.

TCP Client-Server Interaction Overview
TCP Interaction

Iterative Servers
Iterative servers continuously wait for clients, providing services to one client at a time.
This method is suited for transactions of shorter duration, where the server is tied to a single client until the transaction completes.
Fork() System Call
fork() creates a child process when the server accepts a client's connection, allowing the child to handle the client independently.
The call returns the process ID of the child process to the parent and '0' to the child process.
Concurrent Servers
Concurrent servers manage multiple clients concurrently by forking a child to handle each incoming client.
The parent process, after establishing the connection, spawns a child process and continues listening for more clients.
Lab Tasks
Task Details
Question 1:
Write a UDP code where clients can communicate via the server acting as a relay node. The server facilitates client A to connect with client B by providing port and IP details. Clients disconnect upon sending "quit".

Question 2:
Develop a TCP client-server chat program enabling the server to connect and manage two clients simultaneously using fork().

Question 3:
Implement a TCP client-server program where two clients communicate through the server acting as a relay node. Utilize fork(). Ensure the program runs across multiple systems.

Question 4:
Design a client-server program using fork() to connect multiple clients concurrently. The server displays a menu offering options to check prime numbers or reverse a sentence based on client selection.

Question 5:
Create a UDP client-server chat program allowing the server to handle two clients concurrently using fork(). Test this across multiple systems.

Conclusion
Thank you for participating in this Computer Networks Lab session focusing on Socket Programming, TCP, and UDP Concurrent Servers. Complete the tasks to deepen your understanding of concurrent server handling and inter-client communication.
