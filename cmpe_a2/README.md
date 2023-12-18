# CPUID Hypercall Instrumentation - Assignment 2

## Team Members
- Lekhana Gadde (017461236)
- Sahithi Kalakonda (017478786)

## Contribution
## Lekhana 
1. **VM Setup:**
   - Created a VM on Google Cloud using Cloud Shell commands, configured virtualization, and added specifications.
  
2. **Kernel Changes:**
   - Built and installed the kernel, implemented CPUID changes in `vmx.c`, and reloaded modules.

3. **Testing:**
   - Launched VM on `qemu-system`, upgraded Ubuntu, and tested CPUID with `test_assignment.c`.

4. **Contributions:**
   - Documented and contributed to GitHub, including screenshots and `Readme.md` updates.

## Sahithi 
1. **SSH Configuration:**
   - Enabled SSH authentication on Google Cloud VM using keys for secure access.

2. **Dependencies and Code:**
   - Installed dependencies, implemented CPUID changes in `cpuid.c`, and reloaded kernel modules.

3. **VM Launch:**
   - Explored methods, opted for `qemu-system` for VM launch.

4. **Testing:**
   - Verified CPUID functionality with `cpuid -l 0x4FFFFFFC/D` and documented outputs.

5. **Contributions:**
   - Committed `dmesg` output to GitHub, collaborated on `Readme.md` updates.


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
> $ sudo bash
> $ make INSTALL_MOD_STRIP=1 modules install && make install
> $ lsmod | grep kvm
> $ rmmod kvm_intel
> $ rmmod kvm
> $ modprobe kvm
> $ lsmod | grep kvm
> $ lsmod | grep kvm

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

## Step 8: Additional Testing with Test Script
1. Create a user-mode program, e.g., `test_assignment.c`, on the launched VM.
2. Compile the program using `gcc`.
3. Execute the compiled program on the VM.
4. Check `sudo dmesg` output to observe kernel logs on the host machine.
