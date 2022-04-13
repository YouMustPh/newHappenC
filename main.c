
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_cpu.h"

int main()
{

    
    Button *btnPower = button_create("circle", "smooth", "power");
    Button *btnReset = button_create("circle", "smooth", "reset");

    Port *portEnergy = Port_create("circle", "Energy", "EnergySymbol", "Energy");

    Port *portUSB1 = Port_create("rectangle", "USB", "USBSymbol", "USB1");
    Port *portUSB2 = Port_create("rectangle", "USB", "USBSymbol", "USB2");
    Port *portUSB3 = Port_create("rectangle", "USB", "USBSymbol", "USB3");

    Port *portRJ = Port_create("rectangle", "ethernet", "ethernetSymbol", "RJ-45");
    Port *portP2P = Port_create("circle", "audio", "audioSymbol", "P2P");
    Port *portHDMI = Port_create("HDMIformat", "video", "HDMISymbol", "HDMI");
    Port *portDP = Port_create("DPformat", "video", "DPSymbol", "DisplayPort");

    CDInput *cdInput = CDInput_create();

    CPU *cpu = CPU_create(btnPower, btnReset, portEnergy, portUSB1, portUSB2, portUSB3, portRJ, portP2P, portHDMI, portDP, cdInput);

    CPU_start(cpu);

    CPU_openCDInput(cpu);

    CPU_closeCDInput(cpu);

    CPU_usePort(cpu, "energy");

    CPU_usePort(cpu, "USB1");
    CPU_usePort(cpu, "USB2");
    CPU_usePort(cpu, "USB3");

    CPU_usePort(cpu, "RJ-45");
    CPU_usePort(cpu, "P2P");
    CPU_usePort(cpu, "HDMI");
    CPU_usePort(cpu, "DisplayPort");

    CPU_stopPort(cpu, "USB1");
    CPU_stopPort(cpu, "USB2");
    CPU_stopPort(cpu, "USB3");

    CPU_stopPort(cpu, "RJ-45");
    CPU_stopPort(cpu, "P2P");
    CPU_stopPort(cpu, "HDMI");
    CPU_stopPort(cpu, "DisplayPort");

    CPU_stopPort(cpu, "energy");

    CPU_shutdown(cpu);

    cpu_destroy(cpu);

    return 0;
}