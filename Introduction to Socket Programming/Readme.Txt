Introduction to Socket Programming in Computer Networks
Overview
This repository presents an introduction to Socket Programming in the realm of Computer Networks. Understanding the basics of network structures, OSI model, and the functionalities of sockets in programming is essential for building network applications, facilitating communication, and handling data transmission between systems.

Computer Networks
Definition
Computer networks comprise interconnected computers or hardware devices, serving the purposes of resource sharing, information sharing, and communication.

Network Types
PAN (Personal Area Network): Range of approximately 1 meter.
LAN (Local Area Network): Spanning from 10 meters to 1 kilometer.
MAN (Metropolitan Area Network): Encompassing a range of around 10 kilometers.
WAN (Wide Area Network): Ranging from 100 kilometers to 1000 kilometers.
OSI Model
The OSI (Open Systems Interconnection) model categorizes network communication into seven layers, detailing the functions and interactions between these layers.

Internet Protocol Suite
Protocols
Application Layer: Various protocols like HTTP, FTP, SMTP.
Transport Layer: TCP (Transmission Control Protocol) and UDP (User Datagram Protocol).
Network Layer: IP (Internet Protocol) - IPv4, IPv6.
Data Link and Physical Layer: Handling physical connections and data framing.
Socket Programming
What is a Socket?
A socket serves as an endpoint for inter-process communication, functioning similarly to file handling. It comprises an address (IP and Port) and facilitates communication between applications, either locally or remotely.

Socket Types
Stream Sockets (SOCK_STREAM): Utilize TCP for reliable, two-way communication.
Datagram Sockets (SOCK_DGRAM): Employ UDP for unreliable connections.
Socket Functions
Socket programming involves essential functions like socket(), bind(), listen(), connect(), accept(), send(), recv(), close(), and shutdown() to manage communication endpoints and data transfer.

Client-Server Model
The communication pattern in socket programming primarily revolves around the client-server model, where servers provide services, and clients request information or services from servers.

TCP and UDP
TCP (Transmission Control Protocol): Reliable, connection-oriented protocol.
UDP (User Datagram Protocol): Unreliable, connectionless protocol suitable for applications with lower latency requirements.
Commands and Network Utilities
Network utilities like ipconfig (Windows), ifconfig (Linux), and their variations aid in querying and retrieving system IP and MAC addresses.
