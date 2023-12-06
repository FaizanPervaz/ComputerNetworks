Introduction:
Access Control Lists (ACLs) facilitate filtering rules based on source IP addresses, dividing into Standard ACLs and Extended ACLs. Standard ACLs operate primarily on source IPs, restricting entire protocol suites of higher layers without distinction between specific protocols.

Features:
Standard ACLs are generally placed near the destination.
They operate on whole networks or sub-networks.
Identified by numbers 1-99 or extended range 1300-1999.
Exclusively use source IP addresses.
Differences between numbered and named standard ACLs regarding rule deletion.
Types of Access Lists:
Standard Access List
Extended Access List
Tools Required:
CISCO Packet Tracer
Objective:
Upon completion of this lab, one should be able to perform various networking tasks including setting up ACLs, cable network configuration, basic switch configurations, packet control, access list configuration, port management, and more.

Walkthrough Tasks:
Task 1:
Construct a topology with two switches connected via copper cross-through wires and four PCs paired with each switch. Configure inter-Virtual LAN and display the results.

Task 2:
Configure generic routers and PCs, connect devices, set IP addresses, configure interfaces, apply routing, ensure connectivity, enable dynamic routing via RIP protocol, and implement Standard ACLs.

Practice Task 1:
Block communication from 192.168.1.0 to Sarah's PC.

Practice Task 2:
Configure ACLs to restrict communication between specific hosts (192.168.40.3 and 192.168.50.3).

Conclusion:
The lab README provides detailed instructions for implementing Access Control Lists in a network environment using CISCO Packet Tracer. It covers topology setup, interface configurations, routing, ACL implementation, and practice tasks for hands-on learning and experimentation
