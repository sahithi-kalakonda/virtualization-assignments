# CMPE283: Virtual Technologies - Assignment 1

## Discovering VMX Features

**Team Members:** Sahithi Kalakonda (017478786), Lekhana Gadde (017461236)

### Contribution of Team Members
#### Lekhana Gadde : 
- Implemented the creation of a virtual machine on Google Cloud Compute Engine using Cloud Shell.
- Installed necessary dependencies (gcc, make, linux-headers) on the launched VM.
- Conducted research on VMX capabilities for VMEXIT control.
- Developed code to read MSR to determine capabilities for Secondary Procbased control.
- Compiled a new module using make, loaded the module into the kernel, and inserted it into the kernel.
- Updated the README file with instructions for launching a VM instance.
- Committed the dmesg output to Git as evidence of completion.
  
#### Sahithi Kalakonda :
- Enabled SSH authentication on the VM launched on Google Cloud.
- Upgraded the Ubuntu OS to the latest version using apt-get update and apt-get upgrade.
- Conducted research on VMX capabilities for VMENTRY, Primary, and Secondary Procbased controls.
- Defined code to read MSR to understand capabilities for VMENTRY, VMEXIT, and Primary Procbased controls.
- Updated the README file with instructions for SSHing into the VM instance.
- Inserted and removed the new module in the kernel.
- Committed the compiled modules to Git to provide evidence of completing the required module.

We distributed the assignment uniformly ensuring that each person contributed by writing two MSR's Linux kernel code. To maintain consistency, we followed a standardized process for setting up, building, and configuring the environment. Throughout the assignment, we collaborated closely to document the procedures we followed.


## Environment Setup

1. Created a VM instance on Google Cloud Platform using the following command:

![VM Instance](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/736756fd7cd45a312139321a4dd88577e6887e64/screenshots/create_vm.png)


## Build and Development

1. Downloaded `CMPE283-1.c` and `Makefile` from the Canvas platform.

2. Created a new directory named `linux`, which contains the cloned repository.
   ![git clone](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/7bb81b7acf9f8a291f394cab25d4688ad3c7a2dc/screenshots/Installing_git_status.jpeg)
3. created cmpe283-1.c file using vi cmpe283-1.c command
   ![cfile]() 
5. Checked whether the `Makefile` is uploaded using the command
   ![makefile](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/9d2de2803a0722d441a71e76bb182be77b76ff78/screenshots/make_file.jpeg)
6. Installed all the required libraries. Ensure you have the necessary dependencies installed.
   ![libraries](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/37a3c4cc7cc444d9972969d90d52e6878406c439/screenshots/req_libraries.jpeg)
7. Built the file using the Make command:
![make1](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/e3fbddbf8a151056aa44cb8d1b15bb94856cf734/screenshots/running_make_command.jpeg)
![make2](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/bc559ad3e79a1695e492b7377d870a851783cacf/screenshots/make.png)
8. After building the file, checked whether `cmpe283-1.ko` (Kernel Object) file is created.
![kernelobject](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/9e267116e8a8e013193fbc31b518d111e703092a/screenshots/Listing_files.jpeg)
9. Viewed Kernel-related messages using:
![dmesg](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/8779b2d19ef68bd3bfa70124169dc74c3e54679c/screenshots/dmesg_command.jpeg)
10. Inserted the above-built Kernel module `cmpe283-1.ko` into the running kernel using:
![insert1](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/e4fcb201fe636ad96c3d5d78478bb647d9d07600/screenshots/ins1.png)
![insert2](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/a76ee9696e5778661bd65d1dfe9edd6beb2b20d7/screenshots/ins2.png)
![insert3](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/5d90a4817c611299791b28a4d2e6b2f04bf2f9ff/screenshots/ins3.png)
11. Executed the below command to remove the `cmpe283-1` module
   sudo rmmod cmpe283-1
12. Checked Kernel messages again using `dmesg` after removing the module `cmpe283-1`.
   ![rmmod1](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/4986d0615910aff9e7d69a3287f5ee43557bb02e/screenshots/rmmod_command.jpeg)
   ![rmmod](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/cfae4adf247357e53a6eb66076348f7b906f187a/screenshots/dmesg_afterrm_cmpe283-1.jpeg)

