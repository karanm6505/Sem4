# UE23CS252B - Computer Networks

## Course Overview  
This course delves into the principles, protocols, and architectures of computer networks, focusing on layered models (TCP/IP and OSI), application layer protocols, transport layer mechanisms, network layer routing, and link-layer technologies. Students will gain hands-on experience with network analysis tools, socket programming, and simulations.

---

## Course Details  
- **Credits**: 5  
- **Total Hours**: 126 (Theory + Lab)  
- **Tools/Languages**:  
  - Wireshark (Packet Analysis)  
  - Python (Socket Programming)  
  - NS2/NS3 (Network Simulator)  
  - Linux Networking Commands (`ifconfig`, `ping`, `tcpdump`, `nmap`)  
- **Prerequisites**: Basic understanding of data communication (UE23CS252A recommended).  

---

## Course Outline  

### **Unit 1: Computer Networks, Internet, and Application Layer-1**  
- **Topics**:  
  - Internet structure: edge vs. core, packet/circuit switching  
  - Delay, loss, and throughput analysis  
  - OSI and TCP/IP models  
  - HTTP/HTTPS, web caching, cookies  
  - DNS (services, records, messages)  
  - Socket programming with UDP/TCP  

### **Unit 2: Application Layer-2 and Transport Layer-UDP**  
- **Topics**:  
  - FTP, SMTP, SNMP, SSH, Telnet  
  - P2P applications  
  - UDP: segment structure, checksum, multiplexing/demultiplexing  
  - Lab: Wireshark analysis of DNS and UDP  

### **Unit 3: Network Layer and Internet Protocol**  
- **Topics**:  
  - IPv4 addressing, fragmentation, NAT  
  - IPv6 addressing and transition mechanisms  
  - Routing algorithms: Link-State, Distance-Vector  
  - Router internals: queuing, scheduling, forwarding  
  - Reliable data transfer: Go-Back-N, Selective Repeat  

### **Unit 4: Link Layer and LAN**  
- **Topics**:  
  - Error detection (CRC, checksums)  
  - Multiple access protocols (CSMA/CD)  
  - Ethernet, ARP, VLANs  
  - Wireless LANs (802.11 architecture, MAC protocols)  
  - Physical layer fundamentals: signals, transmission media  

---

## Lab Sessions (Key Activities)  
1. **Lab 1**: Introduction to network devices and basic Linux commands.  
2. **Lab 2**: HTTP/HTTPS analysis with Wireshark.  
3. **Lab 3**: UDP/DNS exploration using Wireshark and Python sockets.  
4. **Lab 4**: Congestion window plotting (NS2) and TCP performance analysis.  
5. **Lab 5**: IPv4 subnetting and NAT configuration.  
6. **Lab 6**: Hardware lab (Ethernet, switches, ARP).  
7. **Mini-Projects**:  
   - **Project 1**: Simulate a network topology with 50+ nodes (NS2/NS3).  
   - **Project 2**: Implement a chat/file transfer application using sockets.  

---

## Learning Outcomes  
By the end of the course, students will:  
- Analyze network traffic using Wireshark.  
- Implement UDP/TCP socket programs in Python.  
- Design and simulate network topologies with NS2/NS3.  
- Configure IPv4/IPv6 addressing and routing protocols.  
- Troubleshoot LAN/WLAN issues using industry-standard tools.  

---

## Textbooks & References  
### **Core Textbook**:  
1. **Computer Networking: A Top-Down Approach** (7th Ed.) by Kurose & Ross  
   - Focus: Application layer, transport layer, and network layer protocols.  

### **Reference Books**:  
1. **TCP/IP Protocol Suite** (4th Ed.) by Behrouz Forouzan  
   - Focus: Detailed protocol analysis and implementation.  

---

## Software/Tools Setup Guide  
- **Wireshark**: Download from [Wireshark Official Site](https://www.wireshark.org/).  
- **NS2/NS3**: Follow installation guides from [NS3 Documentation](https://www.nsnam.org/).  
- **Python Libraries**: Use `socket`, `scapy`, and `matplotlib` for labs.  

---
