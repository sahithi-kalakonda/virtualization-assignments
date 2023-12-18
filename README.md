# CMPE282: Virtual Technologies - Assignment 1

## Discovering VMX Features

**Team Members:** Sahithi Kalakonda (017478786), Lekhana Gadde (017461236)

### Contribution of Team Members

We distributed the assignment uniformly ensuring that each person contributed by writing two MSR's Linux kernel code. To maintain consistency, we followed a standardized process for setting up, building, and configuring the environment. Throughout the assignment, we collaborated closely to document the procedures we followed.


## Environment Setup

1. Created a VM instance on Google Cloud Platform using the following command:

![VM Instance]()


## Build and Development

1. Downloaded `CMPE283-1.c` and `Makefile` from the Canvas platform.

2. Created a new directory named `linux`, which contains the cloned repository.
   ![git clone](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/dac44512a5795bdedcaa4324ad41183d785557de/screenshots/Installing_git_status.jpeg)
3. Checked whether the `Makefile` is uploaded using the command
   ![makefile](https://github.com/sahithi-kalakonda/virtualization-assignments/blob/9d2de2803a0722d441a71e76bb182be77b76ff78/screenshots/make_file.jpeg)
4. Installed all the required libraries. Ensure you have the necessary dependencies installed.

5. Built the file using the Make command:

6. After building the file, checked whether `cmpe283-1.ko` (Kernel Object) file is created.

7. Viewed Kernel-related messages using:

8. Inserted the above-built Kernel module `cmpe283-1.ko` into the running kernel using:

9. Executed the below command to remove the `cmpe283-1` module:

10. Checked Kernel messages again using `dmesg` after removing the module `cmpe283-1`.

---


