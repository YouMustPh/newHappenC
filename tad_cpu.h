typedef struct button Button;
typedef struct port Port;
typedef struct cpu CPU;
typedef struct cdInput CDInput;

Button *button_create(char *format, char *texture, char *type);
void button_destroy(Button *btn);
void buttonPress(Button *btn, int pressed);

Port *Port_create(char *format, char *type, char *symbol, char *name);
void port_destroy(Port *port);
void port_use(Port *port);
void port_stop(Port *port);

CDInput *CDInput_create();
void CDInput_destroy(CDInput *CDInput);
void CDInputOpen(CDInput *CDInput);
void CDInputClose(CDInput *CDInput);

CPU *CPU_create(Button *power, Button *reset, Port *energy, Port *USB1, Port *USB2, Port *USB3, Port *Ethernet, Port *Audio, Port *video1, Port *video2, CDInput *CDInput);
void cpu_destroy(CPU *cpu);
void CPU_start(CPU *cpu);
void CPU_shutdown(CPU *cpu);
void CPU_usePort(CPU *cpu, char *name);
void CPU_openCDInput(CPU *cpu);
void CPU_stopPort(CPU *cpu, char *name);