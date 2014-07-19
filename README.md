OS Thesis Project
=================
**Tyler James Higley**

This is a repository for Tyler Higley's Potential 2014/2015 Computer Science Senior Thesis Project. 
###Intention
Write a simple functional Operating System that:
- Bootstraps into memory
- Switches to 32 bit protected mode
- Runs a C Kernel
- Has an interrupt handler
- Has a file System
- Read and Writes files
- Navigate a filesystem
- Run applications

Languages: x86 Assembly (nasm), C (gcc)

Currently run on: QEMU [Quick EMUlator] booting from floppy

###Versions
05/15/14  
1) HelloOS - Simple 16 bit Operating System that loads and prints a hello message



06/01/14  
2) Interactive - 16 bit Operating System that echos keyboard input to the screen



07/08/14  
3) Bootstrapping - OS that bootstraps from a floppy to memory and jumps to the C Kernel



07/17/14  
4) Kernel - Add functionality to the Kernel


###Sources:
- OS Development Series - brokenthorn.com
- Writing a Simple Operating System — from Scratch by Nick Blundell
- Write Your Own Operating System Tutorial - joelgompert.com
- Writing a 16-bit Real mode OS [NASM] - appusajeev.wordpress.com
- Onyxkernel -- First Steps -
