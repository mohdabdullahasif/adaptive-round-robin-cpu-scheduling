# Adaptive Round Robin CPU Scheduling Algorithm

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Course](https://img.shields.io/badge/Course-CS--381%20Operating%20Systems-orange.svg)]()
[![License](https://img.shields.io/badge/License-MIT-green.svg)]()

An enhanced implementation and comparative study of **CPU Scheduling Algorithms** in C: evaluating the standard **Round Robin (RR)** scheduling algorithm against a **Modified Adaptive Round Robin (ARR)** algorithm designed for mixed workloads.

---

## 📌 Project Overview

CPU scheduling is a fundamental operating system mechanism that controls the allocation of CPU resources among competing processes. The primary objectives are to optimize CPU utilization, throughput, turnaround time, waiting time, and response time while ensuring fairness.

While traditional **Round Robin (RR)** is widely adopted in time-sharing operating systems due to its starvation-free preemptive design, its reliance on a **fixed time quantum** poses severe performance limitations:
- **Small Time Quantum:** Leads to excessive context switching and high system overhead.
- **Large Time Quantum:** Degenerates towards First-Come, First-Served (FCFS), leading to increased waiting and response times for shorter tasks.

### 💡 The Proposed Solution: Adaptive Round Robin

The **Modified Adaptive Round Robin** algorithm dynamically adapts the time quantum based on process characteristics. By evaluating the average CPU burst time ($\text{avgBurst}$) of incoming tasks:
- **Short Processes ($\text{Burst} \le \text{avgBurst}$):** Assigned a tighter time quantum ($TQ = 4$) to finish rapidly, boosting system responsiveness.
- **Long Processes ($\text{Burst} > \text{avgBurst}$):** Assigned a larger time quantum ($TQ = 6$), preventing unnecessary preemption and reducing context switches.

---

## 🚀 Key Features & Algorithm Comparison

| Feature | Standard Round Robin | Modified Adaptive Round Robin |
| :--- | :--- | :--- |
| **Quantum Type** | Static / Fixed | Dynamic / Adaptive |
| **Workload Adaptability** | Uniform treatment across all jobs | Tailored execution based on job duration |
| **Context Switching** | High frequency in mixed workloads | Significantly reduced for compute-heavy jobs |
| **Short Job Starvation** | Delayed behind longer tasks | Accelerated completion |
| **Average Waiting Time** | Higher | **Reduced (~13.5% improvement)** |
| **Average Turnaround Time** | Higher | **Improved (~8.5% improvement)** |

---

## 📊 Benchmark & Performance Evaluation

Using a standardized benchmark workload of 4 processes with varying burst requirements:

### Test Workload

| Process | Arrival Time (AT) | Burst Time (BT) |
| :---: | :---: | :---: |
| **P1** | 0 | 5 |
| **P2** | 1 | 3 |
| **P3** | 2 | 8 |
| **P4** | 3 | 6 |

### Comparative Results

| Metric | Original Round Robin ($TQ = 4$) | Modified Adaptive Round Robin | Improvement |
| :--- | :---: | :---: | :---: |
| **Average Waiting Time (Avg WT)** | **9.25 ms** | **8.00 ms** | 🟢 **13.51% Faster** |
| **Average Turnaround Time (Avg TAT)** | **14.75 ms** | **13.50 ms** | 🟢 **8.47% Faster** |
| **Context Switching** | High | Reduced | 🟢 **Lower Overhead** |
| **Short Job Latency** | Slower | Faster | 🟢 **Optimized** |

---

## 📂 Repository Structure

```text
├── Modified_Adaptive_Round_Robin.c   # Implementation of Adaptive Round Robin (Dynamic TQ)
├── Original_Round_Robin.c            # Baseline implementation of Standard Round Robin (Static TQ)
├── Project Report.docx               # Comprehensive academic project report & analysis
└── README.md                         # Project documentation and guide
```

---

## 🛠️ Getting Started

### Prerequisites

Ensure you have a C compiler installed:
- **GCC** (`gcc`) / **MinGW** for Windows
- **Clang** (`clang`) for macOS / Linux

Verify compiler installation:
```bash
gcc --version
```

### Compilation & Execution

#### 1. Run Baseline (Original Round Robin)
```bash
# Compile
gcc Original_Round_Robin.c -o original_rr

# Run
./original_rr
```

#### 2. Run Modified Adaptive Round Robin
```bash
# Compile
gcc Modified_Adaptive_Round_Robin.c -o adaptive_rr

# Run
./adaptive_rr
```

### Sample Input & Output

```text
Enter number of processes: 4
Enter burst time for each process:
P1: 5
P2: 3
P3: 8
P4: 6

Process Burst   Waiting Turnaround
P1      5       8       13
P2      3       3       6
P3      8       9       17
P4      6       12      18

Average Waiting Time = 8.00
Average Turnaround Time = 13.50
```

---

## ⚖️ Trade-offs & Discussion

- **Benefits:**
  - Lower average waiting and turnaround times.
  - Mitigates the "convoy effect" often seen when short processes get trapped behind compute-heavy tasks.
  - Lowers context switching overhead.
- **Trade-offs:**
  - Introduces minimal initial computational overhead ($O(n)$) to calculate average burst time.
  - Assumes known or estimated burst times prior to execution (can be integrated with exponential smoothing burst estimation in real production kernels).

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).
