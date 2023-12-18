#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/msr.h>

#define MAX_MSG 80

#define IA32_VMX_PINBASED_CTLS    0x481
#define IA32_VMX_PROCBASED_CTLS    0x482
#define IA32_VMX_PROCBASED_CTLS2    0x48B
#define IA32_VMX_EXIT_CTLS    0x483
#define IA32_VMX_ENTRY_CTLS    0x484

struct capability_info {
    uint8_t bit;
    const char *name;
};

struct capability_info pinbased[5] = {
    {0, "External Interrupt Exiting"},
    {3, "NMI Exiting"},
    {5, "Virtual NMIs"},
    {6, "Activate VMX Preemption Timer"},
    {7, "Process Posted Interrupts"}
};


struct capability_info procbased1[21] =
{
    {2 , "Interrupt-window" },
    {3 , "Use TSC offsetting" },
    {7 , "HLT exiting" },
    {9 , "INVLPG exiting" },
    {10 , "MWAIT exiting" },
    {11 , "RDPMC exiting" },
    {12 , "RDTSC exiting" },
    {15 , "CR3-load exiting" },
    {16 , "CR3-store exiting" },
    {19 , "CR8-load exiting" },
    {20 , "CR8-store exiting" },
    {21 , "Use TPR shadow" },
    {22 , "NMI-window exiting" },
    {23 , "MOV-DR exiting" },
    {24 , "Unconditional I/O" },
    {25 , "Use I/O bitmaps" },
    {27 , "Monitor trap flag" },
    {28 , "Use MSR Bitmaps" },
    {29 , "MONITOR exiting" },
    {30 , "PAUSE exiting" },
    {31 , "Activate secondary controls" }
};

    
struct capability_info procbased2[26] =
{
    
    { 0, "Virtualize APIC accesses" },
    { 1, "Enable EPT" },
    { 2, "Descriptor-table exiting" },
    { 3, "Enable RDTSCP" },
    { 4, "Virtualize x2APIC mode" },
    { 5, "Enable VPID" },
    { 6, "WBINVD exiting" },
    { 7, "Unrestricted guest" },
    { 8, "APIC-register virtualization" },
    { 9, "Virtual-interrupt delivery" },
    { 10, "PAUSE-loop exiting" },
    { 11, "RDRAND exiting" },
    { 12, "Enable INVPCID" },
    { 13, "Enable VM functions" },
    { 14, "VMCS shadowing" },
    { 15, "Enable ENCLS exiting" },
    { 16, "RDSEED exiting" },
    { 17, "Enable PML" },
    { 18, "EPT-violation #VE" },
    { 19, "Conceal VMX from PT" },
    { 20, "Enable XSAVES/XRSTORS" },
    { 22, "Mode-based execute control for EPT" },
    { 23, "Sub-page write permissions for EPT"},
    { 24, "Intel PT uses guest physical address"},
    { 25, "Use TSC scaling" },
    { 26, "Enable user wait and pause"},
    { 28, "Enable ENCLV exiting"}
};


struct capability_info entry[12] =
{

        { 2, "Load debug controls" },
        { 9, "IA-32e mode guest" },
        { 10, "Entry to SMM" },
        { 11, "Deactivate dual-monitor treatment" },
        { 13, "Load IA32_PERF_GLOBAL_CTRL" },
        { 14, "Load IA32_PAT" },
        { 15, "Load IA32_EFER" },
        { 16, "Load IA32_BNDCFGS" },
        { 17, "Conceal VMX from PT" },
        { 18, "Load IA32_RTIT_CTL" },
        { 20, "Load CET state" },
        { 22, "Load PKRS" }

};

struct capability_info exit[14] =
{

     { 2, "Save debug controls" },
     { 9, "Host address-space size" },
     { 12, "Load IA32_PERF_GLOBAL_CTRL" },
     { 15, "Acknowledge interr" },
     { 18, "Save IA32_PAT" },
     { 19, "Load IA32_PAT" },
     { 20, "Save IA32_EFER" },
     { 21, "Load IA32_EFER"},
     { 22, "Save VMXpreemption timer value" },
     { 23, "Clear IA32_BNDCFGS" },
     { 24, "Conceal VMX from PT" },
     { 25, "Clear IA32_RTIT_CTL" },
     { 28, "Load CET state" },
     { 29, "Load PKRS" }
    
};

void report_capability(struct capability_info *cap, uint8_t len, uint32_t lo, uint32_t hi) {
    uint8_t i;
    struct capability_info *c;
    char msg[MAX_MSG];

    memset(msg, 0, sizeof(msg));

    for (i = 0; i < len; i++) {
        c = &cap[i];
        snprintf(msg, 79, "  %s: Can set=%s, Can clear=%s\n",
                 c->name,
                 (hi & (1u << c->bit)) ? "Yes" : "No",
                 !(lo & (1u << c->bit)) ? "Yes" : "No");
        printk("%s", msg);
    }
}

void detect_vmx_features(void) {
    uint32_t lo, hi;

    rdmsr(IA32_VMX_PINBASED_CTLS, lo, hi);
    pr_info("Pinbased Controls MSR: 0x%llx\n", (uint64_t)(lo | (uint64_t)hi << 32));
    report_capability(pinbased, 5, lo, hi);

    printk(KERN_INFO "\n");
    rdmsr(IA32_VMX_PROCBASED_CTLS, lo, hi);
    pr_info("Proc based Controls MSR: 0x%llx\n",
      	(uint64_t)(lo | (uint64_t)hi << 32));
    report_capability(procbased1, 21, lo, hi);

    printk(KERN_INFO "\n");
    rdmsr(IA32_VMX_PROCBASED_CTLS2, lo, hi);
    pr_info("Proc Based Secondary Controls MSR: 0x%llx\n",
        (uint64_t)(lo | (uint64_t)hi << 32));
    report_capability(procbased2, 27, lo, hi);


    printk(KERN_INFO "\n");
        rdmsr(IA32_VMX_ENTRY_CTLS, lo, hi);
        pr_info("Entry Controls MSR: 0x%llx\n",
                (uint64_t)(lo | (uint64_t)hi << 32));
        report_capability(entry, 12, lo, hi);



    printk(KERN_INFO "\n");
        rdmsr(IA32_VMX_EXIT_CTLS, lo, hi);
        pr_info("Exit Controls MSR: 0x%llx\n",
                (uint64_t)(lo | (uint64_t)hi << 32));
        report_capability(exit, 14, lo, hi);

}

int init_module(void) {
    printk(KERN_INFO "CMPE 283 Assignment 1 Module Start\n");
    detect_vmx_features();
    return 0;
}

void cleanup_module(void) {
    printk(KERN_INFO "CMPE 283 Assignment 1 Module Exits\n");
}

MODULE_LICENSE("GPL");

