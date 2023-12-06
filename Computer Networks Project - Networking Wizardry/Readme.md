![Topology](https://github.com/FaizanPervaz/ComputerNetworks/assets/121532370/5be62759-a8d4-49f4-a19f-fc6a381f348b)

Overview:
This project focuses on configuring a complex network topology using Packet Tracer Instructor Version. Students are tasked with implementing various networking protocols, subnetting using VLSM, routing configurations, redistribution, DHCP, NAT, and access control through Access Lists.

Instructions:
Simulate the Network:

Utilize Packet Tracer Instructor Version to recreate the provided network design.
Refer to the attached "IP address" file for IP addressing details.
VLSM Subnetting:

Determine the required hosts per subnet, provided in the file.
Implement VLSM to allocate IP addresses to the subnets accordingly.
Routing Protocol Configuration:

Use OSPF (Area 1), EIGRP 11, and RIP for different blocks as instructed.
Implement Redistribution among routers per the guidelines.
DHCP Assignment:

Designate DHCP 1 for specific sets of hosts in various areas/subnets.
NAT Implementation:

Configure NAT on Router 10 for Network G using provided Private IP Addresses.
Access Control via ACLs:

Restrict specific PCs/networks from accessing servers using Access Control Lists (ACLs).
Project Guidelines:
Follow the instructions provided meticulously to build and configure the network.
Avoid cheating or copying as the evaluation is strict.
Create multiple pkt files for backup.
Key Objectives:
Technical Challenge: Configuring and optimizing a multi-protocol network.
Learning Focus: VLSM, Routing Protocols, Redistribution, NAT, and Access Control.
Time Frame: 4 hours to set up and run the network.
"Our greatest weakness lies in giving up. The most certain way to succeed is always to try just one more time." - Thomas Edison
"A creative man is motivated by the desire to achieve, not by the desire to beat others." - Ayn Rand

Complete Solution Topology : 
![Screenshot 2023-12-06 204122](https://github.com/FaizanPervaz/ComputerNetworks/assets/121532370/08c057f9-5849-4a9c-a4f8-ae28202ac2d2)

OSPF AREA 1 : 
![Screenshot 2023-12-06 204237](https://github.com/FaizanPervaz/ComputerNetworks/assets/121532370/2b598b3b-b829-4a43-940e-a8309ecbe773)

EIGRP 11 : 
![Screenshot 2023-12-06 204254](https://github.com/FaizanPervaz/ComputerNetworks/assets/121532370/7d928908-03bd-40ee-bf1b-d4c6a92811d9)

RIP VER 2:
![Screenshot 2023-12-06 204301](https://github.com/FaizanPervaz/ComputerNetworks/assets/121532370/2e916614-89e5-4f00-8093-4f155f6a9b09)
![Screenshot 2023-12-06 204320](https://github.com/FaizanPervaz/ComputerNetworks/assets/121532370/2cde9856-84ee-4728-8672-ba5a9e6d61ea)

OSPF AREA 2:
![Screenshot 2023-12-06 204313](https://github.com/FaizanPervaz/ComputerNetworks/assets/121532370/458e5fd0-d84e-425f-9787-b01cf0e7a0cf)

Redistribution Commands : 
ospf to ospf: 
router ospf 1 
redistribute ospf 2 subnets
router ospf 2
redistribute ospf 1 subnets


ospf to rip: 
router rip
ver 2 
redistribute ospf 1 metric 1(you can give this value(1) from 1-15 so i chose 1 here)
router ospf 1 
redistribute rip subnets


eigrp to rip: 
router rip
ver 2 
redistribute eigrp 11 metric 1
router eigrp 11
redistribute rip metric 1000 1000 255 1 1000


eigrp to ospf:
router eigrp 11
 redistribute ospf 1 metric 10000 100 255 1 1500
router ospf 1
 redistribute eigrp 11 subnets

Nat Commands : 
![WhatsApp Image 2023-12-06 at 13 42 33_e69f5165](https://github.com/FaizanPervaz/ComputerNetworks/assets/121532370/91b6b1b7-2c73-4b15-bda4-18644454187e)






