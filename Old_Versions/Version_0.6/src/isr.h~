#include "common.h"

#define irq0 32
#define irq1 33
#define irq2 34
#define irq3 35
#define irq4 36
#define irq5 37
#define irq6 38
#define irq7 39
#define irq8 40
#define irq9 41
#define irq10 42
#define irq11 43
#define irq12 44
#define irq13 45
#define irq14 46
#define irq15 47

typedef struct registers
{
   u32int ds;                  // Data segment selector
   u32int edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   u32int int_no, err_code;    // Interrupt number and error code (if applicable)
   u32int eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t;

typedef void (*isr_t)(registers_t);
void register_interrupt_handler(u8int n, isr_t handler);

