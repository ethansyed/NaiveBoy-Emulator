#include <cstdint>
#include "ARM7TDMI_S.h"

/* This implementation is of the synthensizable ARM7TDMI (ARM7TDMI-S)   */
/* Their respective emulation implementation should be identical        */

void ARM7TDMI_S::run()
{
}

void ARM7TDMI_S::runNCycles(int n)
{
    for (int i = 0; i < n; i++)
    {
        cycle();
    }
}

void ARM7TDMI_S::Fetch()
{
}

void ARM7TDMI_S::Decode()
{
}
void ARM7TDMI_S::Execute()
{
}

void ARM7TDMI_S::cycle()
{
    Fetch();
    Decode();
    Execute();
    CYCLE_COUNT++;
}