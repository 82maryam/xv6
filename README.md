# xv6 Kernel Development: MSKF Integration

## Overview

This repository is based on the **xv6 operating system**, a modern reimplementation of the Sixth Edition Unix kernel for pedagogical purposes, developed at MIT. This project specifically focuses on extending and modifying the core kernel functionality by integrating a new feature or module contained within the **`mskf`** directory.

The goal is to successfully incorporate the files and logic from the `mskf` folder—which typically contains new system calls, user programs, or kernel modifications—into the xv6 build and execution environment. This process requires modifying key xv6 configuration files (like `Makefile` and potentially kernel source files) to ensure the new components are compiled, linked, and runnable.

## Project Structure

The standard xv6 file structure is maintained, with the addition of the new module directory:

```
.
├── mskf/                 # NEW: Directory containing the added feature/module files (e.g., new system calls, utilities).
├── Makefile              # Configuration file, must be updated to include 'mskf' files.
├── README                # Standard xv6 documentation.
├── usys.S                # System call entry points (may need modification).
├── syscall.h             # System call numbers (may need modification).
├── ...                   # Other xv6 kernel and user source files (proc.c, fs.c, etc.).
└── user/                 # Standard xv6 user-level programs.
```

## How to Build and Run xv6 (with MSKF Integration)

### Prerequisites

To build and run xv6, you will typically need:

1.  **`git`**: For cloning the repository.
2.  **GCC (GNU Compiler Collection)**: For C compilation.
3.  **GDB (GNU Debugger)** (Optional but recommended).
4.  **QEMU**: The system emulator used to run the xv6 kernel.

You must ensure that your host system has the necessary cross-compiler tools for the xv6's target architecture (usually $\text{x}86$).

### 1\. Cloning the Repository

If you are starting from a clean slate:

```bash
git clone https://github.com/82maryam/xv6.git
cd xv6
```

### 2\. Integrating the `mskf` Module

The most crucial step is modifying the **`Makefile`** to recognize and compile the files within the `mskf` directory. You will typically need to:

  * **Add `.o` files** from `mskf` to the `EXTRADEFS` or similar variables in the `Makefile` to link them into the kernel.
  * If `mskf` contains new user-level utilities, ensure they are compiled and added to the file system image (`fs.img`).

**Example `Makefile` modification (conceptual):**

```makefile
# Find the KERNEL or EXTRA_OBJS section and add the mskf object files
# Example: mskf_file.c -> mskf_file.o
OBJS += mskf/mskf_main.o mskf/mskf_util.o
```

### 3\. Compiling the Kernel

Once the `Makefile` is updated, build the kernel and the file system image:

```bash
make
```

### 4\. Running the Kernel in QEMU

Execute the compiled kernel image using QEMU:

```bash
make qemu
```

This command will start the QEMU emulator, boot the xv6 kernel, and present the shell prompt. You can then test the functionality provided by the **`mskf`** module (e.g., by executing a new user program or invoking a new system call).

### 5\. Cleaning the Build

To remove the generated object files and the kernel image:

```bash
make clean
```

## System Calls and Kernel Modifications

If the `mskf` folder introduces **new system calls**, you will also have had to modify:

1.  **`syscall.h`**: Assign a unique number to the new system call.
2.  **`syscall.c`**: Add the system call function pointer to the `syscalls` array.
3.  **`usys.S`**: Add an assembly stub for the new system call.

This project serves as an excellent hands-on experience in extending the functionality of a real, albeit simplified, operating system kernel.
