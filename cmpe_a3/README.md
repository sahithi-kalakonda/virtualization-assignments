# CPUID Hypercall Instrumentation - Assignment 3

## Step 1: Set Up Virtual Machine on Google Cloud Compute Engine
1. Created a VM with mentioned virtualization capabilities for the assignment in Google Cloud Compute Engine.
2. Launch the instance.

## Step 2: Installing Dependencies on the Virtual Machine
1. Update the VM and install the prerequisite libraries.

## Step 3: Download and Build Linux Kernel Source Code
1. Download the Linux kernel source code (e.g., version 6.0.7) and extract it.
2. Copy the configuration from the current kernel to the source code directory.
3. Build the kernel using the following commands mentioned in the video
> $ make -j 16 modules
![make_modules](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/6a8f735ae2e136dce404c90b34961dfea37f78c3/screenshots/make_modules2.png)
> $ sudo bash
> 
> $ make INSTALL_MOD_STRIP=1 modules install && make install
![make install](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/09e7ee42edb1395ac762f7eb7305e8e43771db03/screenshots/make_install2.png)
> $ lsmod | grep kvm
![lsmod](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/f58a7af35bc37bdb4b119148270fb9dcf7441965/screenshots/lsmod.png)
> $ rmmod kvm_intel
> 
> $ rmmod kvm
> 
> $ modprobe kvm
> $ lsmod | grep kvm
![kvm](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/106d96f2b2058e3b2cf44c5c2d3d098daa3daf9c/screenshots/modprobe_kvm.png)
> $ modprobe kvm_intel
> $ lsmod | grep kvm
![kvm_intel](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/f06751d6243d095da8505ec592b5e2f1b00f5fdc/screenshots/modprobe_kvn_intel.png)

## Step 4: Modify Code for CPUID Leaf Nodes 0x4FFFFFFC and 0x4FFFFFFD
1. Locate and modify the relevant code in `vmx.c` and `cpuid.c` to implement the desired functionality for CPUID leaf nodes `0x4FFFFFFC` and `0x4FFFFFFD`.

## Step 5: Rebuild Kernel Modules and Reload
1. Rebuild the kernel modules using appropriate `make` commands.
2. Install the new modules into the kernel.
3. Reload the `kvm` and `kvm_intel` modules.

## Step 6: Launch Virtual Machine on Modified Kernel
1. Obtain an image for launching the VM.
2. Create a user-data file for the VM.
3. Launch the VM.

## Step 7: Test CPUID Functionality
1. Install required items on the VM for observing the behavior of CPUID, such as `cpuid`.
2. Test the modified CPUID leaf nodes using the correct `cpuid` instruction, e.g., `cpuid -l 0x4FFFFFFC` and `cpuid -l 0x4FFFFFFD`.
3. Check `dmesg` output on the host machine to observe kernel logs.

## Q3. Comment on the frequency of exits – does the number of exits increase at a stable rate? Or are there more exits performed during certain VM operations? Approximately how many exits does a full VM boot entail?
The exit frequency demonstrates variability rather than a stable increase. Comparing screenshots before and after boot, it's evident that the VM boot, specifically for exit 28, results in approximately 18,000 exits, indicating fluctuations rather than a consistent rise.
## Q4. Of the exit types defined in the SDM, which are the most frequent? Least?

##### Most Frequent Exits:

- Exit 48 (EPT Violation)
- Exit 32 (WRMSR)
- Exit 1 (External Interrupt)
- Exit 23 (HLT)

##### Least Frequent Exits:

- Exit 54 (WBINVD)
- Exit 55 (XSETBV)
- Exit 29 (MOV DR)
- Exit 31 (RDTSC)
