EIGRP Lab: Understanding Dynamic Routing with EIGRP
This repository encompasses a walkthrough and practical exercises aimed at comprehending the Enhanced Interior Gateway Routing Protocol (EIGRP) and implementing dynamic routing within a network topology using CISCO Packet Tracer.

Overview
Understanding EIGRP
EIGRP is an advanced version of IGRP, utilizing distance vector technology to enhance convergence properties and operational efficiency. The protocol employs the Diffusing Update Algorithm (DUAL) to maintain loop-freedom during route computation, synchronizing routers affected by topology changes while excluding unaffected ones.

Components of EIGRP
The EIGRP protocol comprises four fundamental components:

Neighbour Discovery/Recovery: Dynamically learns and tracks routers on directly attached networks using periodic hello packets.
Reliable Transport Protocol: Ensures ordered delivery of EIGRP packets, supporting multicast and unicast transmissions for efficient communication.
DUAL Finite State Machine: Manages route computations based on metric information and selects loop-free paths using feasible successors.
Protocol Dependent Modules: Handles network layer-specific requirements, such as encapsulating EIGRP packets in IP, parsing received packets, and making routing decisions.
Tools Required
CISCO Packet Tracer: Required for creating and configuring the network topology.
Experiment Objectives
Upon completion of this lab, participants will:

Cable a network according to the provided topology.
Configure routers and interfaces.
Implement EIGRP routing on all routers.
Verify EIGRP routing using show commands.
Perform tasks such as disabling automatic summarization, configuring manual summarization, and propagating default routes to EIGRP neighbors.
Document the EIGRP configuration.
Walkthrough Task
Creating Topology
Follow the provided Topology Diagram to place the required components (routers, WIC-1T ports, switches, and PCs) within the Packet Tracer environment.
Connect the devices appropriately using serial-DCE cables and copper straight-through cables based on the diagram.
Configuration Steps
Configure router interfaces with IP addresses and enable necessary settings (such as no shutdown).
Implement EIGRP protocol settings using the provided commands on the routers.
Assign IP addresses, subnet masks, and default gateways to PCs connected to the network.
Evaluation
Perform a final evaluation by pinging devices within the network to ensure successful communication.
Practice Tasks
Task:
Configure EIGRP dynamic routing within a given topology and present the results to the instructor.

Usage
Clone or download this repository to access the detailed walkthrough and configuration steps. Use CISCO Packet Tracer to simulate the provided network topology and perform the lab tasks.

Contributing
Contributions to improve documentation, add supplementary tasks, or enhance the lab instructions are welcome! Fork this repository, make your changes, and submit a pull request.
