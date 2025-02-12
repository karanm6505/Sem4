# UE23CS251B - Microprocessor and Computer Architecture

## Course Overview
This course explores the design, functionality, and optimization of modern microprocessors and computer systems. It focuses on ARM architecture, pipelining, memory hierarchy, and advanced parallel computing techniques. Students will gain hands-on experience with simulators and microcontroller kits to implement and analyze architectural concepts.

---

## Course Details
- **Credits**: 5  
- **Total Hours**: 126 (Theory + Lab)  
- **Tools/Languages**:  
  - ARM Simulator (ARMSIM)  
  - Arduino Microcontroller Kit  
  - Para Cache Simulator  
  - C Programming (for system-level implementations)  
- **Prerequisites**: Desirable knowledge of UE23CS251A and UE23CS252A (as noted in the syllabus).  

---

## Course Outline

### **Unit 1: Introduction to Microprocessor Architecture & ISA**  
- **Topics**:  
  - RISC vs. CISC architectures  
  - ARM processor architecture (register set, ISA)  
  - Data processing instructions (arithmetic operations, variants)  
  - Branch instructions, addressing modes, and conditional execution  
  - Load/Store instructions with programming examples  
  - Instruction encoding (data processing, data transfer, branch)  
  - Interrupt handling and context switching  
  - Functions and parameter-passing techniques  

### **Unit 2: Pipelining**  
- **Topics**:  
  - 3-stage and 5-stage pipelining  
  - Pipeline hazards: Structural, Data, Control  
  - Performance analysis (throughput, latency)  
  - Branch prediction (1-bit and 2-bit predictors)  
  - Lab work: ARM7TDMI ISA programming sequences  

### **Unit 3: Memory Hierarchy**  
- **Topics**:  
  - Cache organization (Fully Associative, Direct Mapped, Set Associative)  
  - Cache optimization techniques (reducing miss rate, write policies)  
  - Case study: Direct-mapped cache using Para Cache Simulator  
  - Introduction to parallel computing (Flynn’s taxonomy, memory architectures)  

### **Unit 4: Advances in Architecture**  
- **Topics**:  
  - Shared memory programming (OpenMP, CUDA)  
  - GPU computing and multi-core architectures  
  - Amdahl’s Law, Gustafson’s Law  
  - Hardware multithreading and design challenges  
  - Mini-project: Sensor-based project implementation  

---

## Lab Sessions (Key Activities)  
1. **Lab 1-4**: ARM7TDMI ISA programming sequences (data processing, branching, interrupts).  
2. **Lab 6**: Para Cache Simulator case study (cache performance analysis).  
3. **Lab 7-9**: Parallel computing and GPU programming experiments.  
4. **Mini-Project**: Design and demonstrate a sensor-based system using Arduino/Raspberry Pi.  

---

## Learning Outcomes  
By the end of the course, students will:  
- Design and simulate ARM-based programs using ARMSIM.  
- Analyze pipeline hazards and optimize performance.  
- Implement cache memory systems and evaluate their efficiency.  
- Develop parallel programs using OpenMP/CUDA.  
- Build hardware-software integrated projects with microcontrollers.  

---

## Textbooks & References  
### **Core Textbooks**:  
1. **Computer Organization and Design** (4th Ed.) by Hennessy & Patterson  
   - Focus: Pipelining, memory hierarchy, performance analysis.  
2. **ARM System Developer’s Guide** by Andrew Sloss et al.  
   - Focus: ARM architecture and optimization.  
3. **Programming Massively Parallel Processors** (3rd Ed.) by Kirk & Hwu  
   - Focus: GPU programming and CUDA.  

### **Reference Books**:  
- **Computer Architecture: A Quantitative Approach** (5th Ed.) by Hennessy & Patterson  
- **Multicore and GPU Programming** by Gerassimos Barlas  

---

## Software/Tools Setup Guide  
- **ARMSIM**: Download from [ARMSIM Official Page](http://armsim.cs.uvic.ca/)  
- **Para Cache Simulator**: Use provided lab manuals.  
- **Arduino IDE**: Install from [Arduino Software](https://www.arduino.cc/en/software).  

---

