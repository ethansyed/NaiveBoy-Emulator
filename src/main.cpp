#include "ARM7TDMI_S.h"
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sstream>

/***************************************************************/
/*   GBA Emulator                                              */
/*   Ethan Syed                                                */
/***************************************************************/

#define TESTMODE 1
int CYCLE_COUNT = 0; // Cycle Counter

/***************************************************************/
/* Print the list of commands for testing                      */
/***************************************************************/
void printHelp()
{
    std::cout << "----------------------- ARM7TDMI-S Sim Commands -----------------------" << std::endl;
    std::cout << "Continue\t- run simulation file to completion" << std::endl;
    std::cout << "Run n\t\t- run n cycles" << std::endl;
    std::cout << "Help\t\t- run n cycles" << std::endl;
    std::cout << "Quit\t\t- exit program" << std::endl;
}

/***************************************************************/
/*   Test Mode                                                 */
/*   Allow user to run CPU by cycle and log simulation         */
/***************************************************************/
void process_user_command(ARM7TDMI_S *CPU, FILE *dumpsim)
{
    std::string command;
    std::string runAmount;
    int cycles;

    std::cout << "ARM7TDMI-S Sim> " << std::endl;
    printHelp(); // command menu

    while (1)
    {
        std::cout << "> ";
        std::getline(std::cin, runAmount);
        std::istringstream iss(runAmount);
        iss >> command;

        switch (command[0])
        {
        case 'C':
        case 'c':
            std::cout << "Continuous Simulation begin..." << std::endl;
            CPU->run();
            break;
        case 'R':
        case 'r':
            if (iss >> cycles)
            {
                std::cout << "Running for " << cycles << " cycles..." << std::endl;
                CPU->runNCycles(cycles);
            }
            else
            {
                std::cerr << "Enter a valid number after the run command!" << std::endl;
            }

            break;
        case 'h':
        case 'H':
            printHelp();
            break;
        case 'q':
        case 'Q':
            return;
        default:
            std::cerr << "Invalid Command" << std::endl;
            break;
        }
    }
}

void loadROM() {};

/***************************************************************/
/*   Entry Point                                               */
/***************************************************************/
int main(int argc, char *argv[])
{
    FILE *dumpsim_file; // Simulator dumpfile

    ARM7TDMI_S *CPU = new ARM7TDMI_S();
    std::cout << "Ethan's GBA emulator" << std::endl;

    // TODO: Process some input file here (ROM eventually)
    bool validInput = true;
    if (!validInput)
    {
        std::cout << "Bad input" << std::endl;
        exit(1);
    }

    if ((dumpsim_file = fopen("dumpsim", "w")) == NULL)
    {
        printf("Error: Can't open dumpsim file\n");
        exit(-1);
    }

    if (TESTMODE)
    {
        process_user_command(CPU, dumpsim_file);
        delete (CPU);
    }
    else
    {
        loadROM();
        CPU->run();
        delete (CPU);
    }

    return 0;
}