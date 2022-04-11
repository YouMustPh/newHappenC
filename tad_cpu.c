
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_cpu.h"

struct button
{
    char *format;
    char *texture;
    char *type;
};

Button *button_create(char *format, char *texture, char *type)
{
    Button *button = (Button *)malloc(sizeof(Button));
    button->format = format;
    button->texture = texture;
    button->type = type;
    return button;
}

void button_destroy(Button *btn)
{
    free(btn);
    btn = NULL;
}

void buttonPress(Button *btn, int pressed)
{
    if (strcmp(btn->type, "power") == 0)
    {
        if (pressed == 0)
        {
            printf("Button %s pressed. CPU inicialized.\n", btn->type);
        }
        else
        {
            printf("Button %s released. CPU shutdown.\n", btn->type);
        }
    }
    else if (strcmp(btn->type, "open CDInput") == 0)
    {
        if (pressed == 0)
        {
            printf("Button %s pressed. Oppended.\n", btn->type);
        }
        else
        {
            printf("Button %s released. Closed.\n", btn->type);
        }
    }
    else if (strcmp(btn->type, "reset") == 0)
    {
        printf("Button %s pressed. Reset.\n", btn->type);
    }
}

struct port
{
    char *type;
    char *format;
    char *symbol;
    char *name;
};

Port *Port_create(char *format, char *type, char *symbol, char *name)
{
    Port *port = (Port *)malloc(sizeof(Port));
    port->format = format;
    port->type = type;
    port->symbol = symbol;
    port->name = name;

    return port;
}

void port_destroy(Port *port)
{
    free(port);
}

void port_use(Port *port)
{
    printf("Port %s in use.\n", port->name);
}

void port_stop(Port *port)
{
    printf("Port %s disconected.\n", port->name);
}

struct cdInput
{
    Button *button;
    int opened;
};

CDInput *CDInput_create()
{
    CDInput *cdInput = (CDInput *)malloc(sizeof(CDInput));
    Button *btn = button_create("circle", "smooth", "open CDInput");

    cdInput->button = btn;
    cdInput->opened = 0;

    return cdInput;
}

void CDInput_destroy(CDInput *CDInput)
{
    free(CDInput);
    CDInput = NULL;
}

void CDInputOpen(CDInput *CDInput)
{
    buttonPress(CDInput->button, 0);
    CDInput->opened = 1;
}

void CDInputClose(CDInput *CDInput)
{
    buttonPress(CDInput->button, CDInput->opened);
    CDInput->opened = 0;
}

struct cpu
{
    Button *power;
    Button *reset;
    Port *energy;
    Port *usb1;
    Port *usb2;
    Port *usb3;
    Port *ethernet;
    Port *audio;
    Port *video1;
    Port *video2;
    CDInput *CDInput;
    int started;
};

CPU *CPU_create(Button *power, Button *reset, Port *energy, Port *USB1, Port *USB2, Port *USB3, Port *Ethernet, Port *Audio, Port *video1, Port *video2, CDInput *CDInput)
{
    CPU *cpu = (CPU *)malloc(sizeof(CPU));
    cpu->power = power;
    cpu->reset = reset;
    cpu->energy = energy;
    cpu->usb1 = USB1;
    cpu->usb2 = USB2;
    cpu->usb3 = USB3;
    cpu->ethernet = Ethernet;
    cpu->audio = Audio;
    cpu->video1 = video1;
    cpu->video2 = video2;
    cpu->CDInput = CDInput;
    cpu->started = 0;
    return cpu;
}

void cpu_destroy(CPU *cpu)
{
    free(cpu->power);
    free(cpu->reset);
    free(cpu->energy);
    free(cpu->usb1);
    free(cpu->usb2);
    free(cpu->usb3);
    free(cpu->ethernet);
    free(cpu->audio);
    free(cpu->video1);
    free(cpu->video2);
    free(cpu->CDInput);
    free(cpu);

    cpu->power = NULL;
    cpu->reset = NULL;
    cpu->energy = NULL;
    cpu->usb1 = NULL;
    cpu->usb2 = NULL;
    cpu->usb3 = NULL;
    cpu->ethernet = NULL;
    cpu->audio = NULL;
    cpu->video1 = NULL;
    cpu->video2 = NULL;
    cpu->CDInput = NULL;
}

void CPU_start(CPU *cpu)
{
    buttonPress(cpu->power, 0);
    cpu->started = 1;
}

void CPU_shutdown(CPU *cpu)
{
    buttonPress(cpu->power, cpu->started);
    cpu->started = 0;
}

void CPU_usePort(CPU *cpu, char *name)
{
    if (strcmp(name, "Energy") == 0)
    {
        port_use(cpu->energy);
    }
    else if (strcmp(name, "USB1") == 0)
    {
        port_use(cpu->usb1);
    }
    else if (strcmp(name, "USB2") == 0)
    {
        port_use(cpu->usb2);
    }
    else if (strcmp(name, "USB3") == 0)
    {
        port_use(cpu->usb3);
    }
    else if (strcmp(name, "RJ-45") == 0)
    {
        port_use(cpu->ethernet);
    }
    else if (strcmp(name, "P2P") == 0)
    {
        port_use(cpu->audio);
    }
    else if (strcmp(name, "HDMI") == 0)
    {
        port_use(cpu->video1);
    }
    else if (strcmp(name, "DisplayPort") == 0)
    {
        port_use(cpu->video2);
    }
}

void CPU_stopPort(CPU *cpu, char *name)
{
    if (strcmp(name, "Energy") == 0)
    {
        port_stop(cpu->energy);
    }
    else if (strcmp(name, "USB1") == 0)
    {
        port_stop(cpu->usb1);
    }
    else if (strcmp(name, "USB2") == 0)
    {
        port_stop(cpu->usb2);
    }
    else if (strcmp(name, "USB3") == 0)
    {
        port_stop(cpu->usb3);
    }
    else if (strcmp(name, "RJ-45") == 0)
    {
        port_stop(cpu->ethernet);
    }
    else if (strcmp(name, "P2P") == 0)
    {
        port_stop(cpu->audio);
    }
    else if (strcmp(name, "HDMI") == 0)
    {
        port_stop(cpu->video1);
    }
    else if (strcmp(name, "DisplayPort") == 0)
    {
        port_stop(cpu->video2);
    }
}

void CPU_openCDInput(CPU *cpu)
{
    CDInputOpen(cpu->CDInput);
}
void CPU_closeCDInput(CPU *cpu)
{
    CDInputClose(cpu->CDInput);
}