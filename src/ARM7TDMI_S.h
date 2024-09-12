#ifndef ARM7TDMI_S_H
#define ARM7TDMI_S_H

#include <cstdint>
#define ARM_Regs 16
class ARM7TDMI_S
{
public:
    /**************************************************************/
    /* External Functions                                         */
    /**************************************************************/
    void run();             // Continuously cycle through instructions
    void runNCycles(int n); // Run n specified amount of cycles

private:
    /**************************************************************/
    /* Status                                                     */
    /**************************************************************/
    int CYCLE_COUNT = 0;

    // false - User
    // true - System
    bool systemMode = false;
    bool privileged = false;

    /**************************************************************/
    /* Register Layout                                            */
    /**************************************************************/

    uint32_t REGS[ARM_Regs]; // 16 register for ARMv4
    uint32_t CPSR;           // Prog Status Reg

    struct
    {
        uint32_t fiq; // Fast Interrupt Request
        uint32_t irq; // (General) Interupt Request
        uint32_t svc; // Supervisor mode - handles software interrups (sys calls)
        uint32_t abt; // Abort mode - mem faults / access violations
        uint32_t und; // Undefined Mode - Undef/invalid ins
    } spsr;

    enum class Mode
    {
        User,
        System,
        FIQ,
        IRQ,
        Supervisor,
        Abort,
        Undefined,
    } currentMode;

    bool thumbMode = false;

    /**************************************************************/
    /* Internal Functions                                         */
    /**************************************************************/
    void cycle();
    void Fetch();
    void Decode();
    void Execute();
};

#endif