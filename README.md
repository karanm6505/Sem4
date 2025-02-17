# UE23CS242B - Operating Systems

## Course Overview  
This course explores the design, implementation, and management of operating systems. Topics include process/thread management, CPU scheduling, synchronization, memory management, file systems, and system protection. Students will implement system calls, shell scripts, and kernel modules using C and Linux/Unix environments.

---

## Course Outline  

### **Unit 1: Introduction and Process Management**  
- **Topics**:  
  - OS structure (kernel, user mode)  
  - Process lifecycle: creation, termination, states  
  - CPU scheduling algorithms (FCFS, SJF, Priority, Round-Robin)  
  - Multi-level queues and feedback scheduling  
  - **Lab**: Linux VM setup, process management system calls (`fork()`, `exec()`, `wait()`).  

### **Unit 2: IPC and Synchronization**  
- **Topics**:  
  - Inter-Process Communication (IPC): shared memory, pipes, FIFOs  
  - Threads (Pthreads, Windows threads)  
  - Synchronization: mutex locks, semaphores  
  - Classic problems: Bounded Buffer, Readers-Writers, Dining Philosophers  
  - Deadlock handling (Banker’s Algorithm)  
  - **Lab**: Thread synchronization, deadlock simulation.  

### **Unit 3: Memory Management**  
- **Topics**:  
  - Memory allocation (partitioning, paging, segmentation)  
  - Virtual memory (demand paging, page replacement algorithms)  
  - Swapping, thrashing, and copy-on-write  
  - Case studies: Linux/Windows memory management  
  - **Lab**: Page replacement simulation (FIFO, LRU, Optimal).  

### **Unit 4: File Management and System Protection**  
- **Topics**:  
  - File systems (ext4, NTFS), directory structures  
  - Disk scheduling (SCAN, C-SCAN, LOOK)  
  - RAID configurations  
  - Access control (ACLs, Unix permissions)  
  - **Lab**: File operations (hard/soft links), `awk`/`sed` scripting.  

---

## Key Labs & Projects  
1. **Lab 1**: Linux VM setup, basic shell commands, C program compilation.  
2. **Lab 2**: Process scheduling simulation (FCFS, SJF, Round-Robin).  
3. **Lab 3**: Shared memory and pipe-based IPC.  
4. **Lab 4**: Thread synchronization with mutex/semaphores.  
5. **Lab 5**: Memory management (page replacement algorithms).  
6. **Lab 6**: File system operations and disk scheduling.  
7. **Shell Scripting**: Automate tasks using cron jobs.  
8. **Project**: Implement a custom shell with job control.  

---

## Learning Outcomes  
By the end of the course, students will:  
- Design and simulate CPU scheduling algorithms.  
- Implement IPC mechanisms (shared memory, pipes).  
- Solve synchronization problems (deadlocks, race conditions).  
- Analyze virtual memory performance and page replacement strategies.  
- Configure file systems and access control policies.  

---

## Textbooks & References  
### **Core Textbooks**:  
1. **Operating System Concepts** (10th Ed.) by Silberschatz, Galvin, Gagne  
   - Focus: Process management, memory, file systems.  
2. **Advanced Programming in the Unix Environment** by Stevens & Rago  
   - Focus: System calls, shell programming.  

### **Reference Books**:  
1. **Operating Systems: Internals and Design Principles** by William Stallings  
2. **Modern Operating Systems** by Andrew Tanenbaum  

---

## Tools Setup Guide  
1. **Linux VM**: Use VirtualBox/VMWare with Ubuntu/Fedora.  
2. **GCC/GDB**: Install via `sudo apt-get install build-essential gdb`.  
3. **Cron**: Schedule tasks using `crontab -e`.  
4. **Shell Scripting**: Practice with Bash in the terminal.  

