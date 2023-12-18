# CMPE282: Virtual Technologies - Assignment 1

## Discovering VMX Features

**Team Members:** Sahithi Kalakonda (017478786), Lekhana Gadde (017461236)

### Contribution of Team Members

We distributed the assignment uniformly ensuring that each person contributed by writing two MSR's Linux kernel code. To maintain consistency, we followed a standardized process for setting up, building, and configuring the environment. Throughout the assignment, we collaborated closely to document the procedures we followed.


## Environment Setup

1. Created a VM instance on Google Cloud Platform using the following command:

![VM Instance](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/736756fd7cd45a312139321a4dd88577e6887e64/screenshots/create_vm.png)


## Build and Development

1. Downloaded `CMPE283-1.c` and `Makefile` from the Canvas platform.

2. Created a new directory named `linux`, which contains the cloned repository.
   ![git clone](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/dac44512a5795bdedcaa4324ad41183d785557de/screenshots/Installing_git_status.jpeg)
3. Checked whether the `Makefile` is uploaded using the command
   ![makefile](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/9d2de2803a0722d441a71e76bb182be77b76ff78/screenshots/make_file.jpeg)
4. Installed all the required libraries. Ensure you have the necessary dependencies installed.
   ![libraries](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/37a3c4cc7cc444d9972969d90d52e6878406c439/screenshots/req_libraries.jpeg)
5. Built the file using the Make command:
![make1](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/e3fbddbf8a151056aa44cb8d1b15bb94856cf734/screenshots/running_make_command.jpeg)
![make2]()
7. After building the file, checked whether `cmpe283-1.ko` (Kernel Object) file is created.
![kernelobject](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/9e267116e8a8e013193fbc31b518d111e703092a/screenshots/Listing_files.jpeg)
8. Viewed Kernel-related messages using:

9. Inserted the above-built Kernel module `cmpe283-1.ko` into the running kernel using:

10. Executed the below command to remove the `cmpe283-1` module:

11. Checked Kernel messages again using `dmesg` after removing the module `cmpe283-1`.

---


