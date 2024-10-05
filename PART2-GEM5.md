**Note: This assignment is under preparation. Meanwhile, you may just start reading and learning about GEM5**

### **Assignment: Running a Basic Benchmark and Analyzing CPI using Gem5**

---

### Objective:
- Use the **Gem5** simulator to run a simple benchmark on a simulated CPU.
- Understand how to simulate different CPU models and configurations.
- Analyze basic performance metrics such as **CPI** (Cycles Per Instruction).

---

### **Step-by-Step Instructions:**

#### 1. **Setup Gem5**
- Download and install **Gem5** from the official repository: [Gem5 Installation Guide](https://www.gem5.org/documentation/general_docs/building).
- Verify that your installation is correct by running a simple example:

```bash
./build/X86/gem5.opt configs/example/se.py -h
```

This command should print the help message for Gem5’s **simple execution (SE)** mode.

#### 2. **Run a Simple Benchmark**
- You will simulate the execution of a simple benchmark program (such as a simple matrix multiplication or a sorting algorithm) using **SE mode**. You can use a program from the provided test binaries or compile your own small program.

Run the following command to simulate the execution of a benchmark program:

```bash
./build/X86/gem5.opt configs/example/se.py --cmd="tests/test-progs/hello/bin/x86/linux/hello"
```

This command runs a simple “Hello World” program, simulating the execution on a basic x86 CPU.

#### 3. **Modify CPU Parameters**
- Modify the CPU model to switch between different CPU types: `AtomicSimpleCPU`, `TimingSimpleCPU`, and `O3CPU` (out-of-order CPU). This will allow you to understand the difference between different levels of CPU complexity.

Run the following commands to simulate the benchmark on different CPU models:

```bash
# Run with AtomicSimpleCPU
./build/X86/gem5.opt configs/example/se.py --cpu-type=AtomicSimpleCPU --cmd="tests/test-progs/hello/bin/x86/linux/hello"

# Run with TimingSimpleCPU
./build/X86/gem5.opt configs/example/se.py --cpu-type=TimingSimpleCPU --cmd="tests/test-progs/hello/bin/x86/linux/hello"

# Run with O3 (Out-of-order CPU)
./build/X86/gem5.opt configs/example/se.py --cpu-type=O3CPU --cmd="tests/test-progs/hello/bin/x86/linux/hello"
```

#### 4. **Collect and Analyze CPI**
- After running the simulations, locate the **Gem5 statistics file** in the output directory (`m5out/stats.txt`). This file contains important statistics like the number of instructions executed, total cycles, cache accesses, etc.

To calculate **CPI** (Cycles Per Instruction), use the following formula:

\[
CPI = \frac{\text{Total Cycles}}{\text{Total Instructions}}
\]

Open the `stats.txt` file and find the relevant metrics:
- `sim_ticks`: The total number of cycles (in ticks).
- `sim_insts`: The total number of instructions executed.

Using these values, calculate the CPI for each CPU model.

#### 5. **Compare CPU Models**
- Compare the **CPI** values for the three CPU models (`AtomicSimpleCPU`, `TimingSimpleCPU`, `O3CPU`). Write a brief analysis of how the CPU models differ and why some models have a higher or lower CPI.

---

### **Deliverables:**

1. **Simulation Logs:** Submit the `stats.txt` file for each CPU model (AtomicSimpleCPU, TimingSimpleCPU, O3CPU).
2. **CPI Calculation:** Provide the calculated **CPI** for each model.
3. **Analysis Report:** Write a short report (1–2 pages) comparing the performance of the three CPU models based on the **CPI** values and explain why some models perform better than others.

---

### **Example Questions for the Report:**

1. **What is the difference between AtomicSimpleCPU, TimingSimpleCPU, and O3CPU in terms of CPI?**
2. **Why does the O3CPU typically have a lower CPI than the other models?**
3. **What architectural features allow out-of-order CPUs to achieve better performance?**
4. **What trade-offs exist between simpler CPU models (like AtomicSimpleCPU) and more complex ones (like O3CPU)?**

---

### **Bonus Task (Optional):**
- Modify the cache parameters (L1 size, associativity) and observe how it affects the **CPI** of the O3CPU. Add this analysis to your report.

Example command to modify cache parameters:

```bash
./build/X86/gem5.opt configs/example/se.py --cpu-type=O3CPU --caches --l1d_size=64kB --l1i_size=32kB --cmd="tests/test-progs/hello/bin/x86/linux/hello"
```

---

### **Notes:**
- **Gem5 Documentation:** Students should refer to the [Gem5 Documentation](https://www.gem5.org/documentation/) for further details on how to run simulations and modify configurations.
- **Tools:** Ensure that students know how to navigate and interpret the `stats.txt` file, as it contains all relevant performance statistics.

---

### **Summary:**
This assignment introduces students to the Gem5 simulator and demonstrates how to:
- Simulate different types of CPUs.
- Collect performance statistics, specifically focusing on **CPI**.
- Analyze and compare CPU models based on their architectural features.

This simple assignment is ideal for getting started with Gem5 and understanding basic architectural simulation concepts.
