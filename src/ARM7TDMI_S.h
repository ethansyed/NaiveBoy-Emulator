#ifndef ARM7TDMI_S_H
#define ARM7TDMI_S_H

#include <cstdint>
#define ARM_Regs 16
class ARM7TDMI_S
{
private:
    int32_t REGS[ARM_Regs]; // 16 register for ARMv4
    int32_t CPSR;           // Prog Status Reg

    // User mode or Supervisor mode
public:
    // Begins continuously cycling through instructions
    void run();
    // Runs n specified amount of cycles
    void runNCycles(int n);
};

#endif