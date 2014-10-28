THOS - (Tyler Higley's Operating System)
=================
**Tyler James Higley**

This is a repository for Tyler Higley's 2014/2015 Computer Science Senior Thesis Project. 

###Abstract
The goal of this project is to write from scratch a simple minimally functional Operating System suitable for use as an educational tool. It will be written for the x86 architecture and will take primary inspiration from Unix based systems. 

###Introduction
There are few programs that can rival the complexity of an Operating System. It is a piece of software that no modern computer can realistically function without. Whether it be the casual user checking their email, the scientific researcher graphing the results of thousands of lines of processed data, or the expert programmer compiling a piece of complicated software, everyone makes use of their Operating System. 

Although there are a number of open-source OS distributions with which one could freely inspect and study the source code, the overwhelming complexity of these modern OS’s make comprehension very challenging for novices to the subject. One of my principal hopes with this project is that when I am done I will have something to show, that is not only functional, but simple and documented well enough that someone else could learn from it.

It is my intention during the remaining year of my college education to personally write from scratch (more or less) a minimally functional command line operating system. In doing so I hope to educate myself about relevant topics and techniques in OS development, establish a closer relationship and  understanding with the inner workings of an Operating System as well as the underlining architecture they run on. My OS will be written for the x86 architecture set and will be in many ways based on Unix.  At a minimum I would like my operating system to be console based, able to read and write files to memory, and run short predefined programs.
as a midrange goal, I would like to include a functional file system with permissions and the like that a user could navigate through. I would also like to include the functionality of simple games that make use of the screen. Lastly, if everything runs smoothly, I would like to include some kind of compiler such that a user could create and run their own programs on my Operating System.

Since this project will involve significant understanding of the topic, I will be taking a significant amount of time to focus on research and education. I have purchased the book Operating Systems Design and Implementation by 3rd Edition Andrew S Tanenbaum. The first edition of that book was Linus Torvalds original inspiration behind the Operating System Linux. Tanenbaum is also the creator of another small educational OS called Minix. Both Minix and Tanenbaum’s book with be principle resources. Additionally I will be taking a look at brokenthorn.com’s OS Development Series, Nick Blundell’s PDF Writing a Simple Operating System, as well as the various resources available at OSDev.org.

The actual implementation will mostly likely be done in x86 Assembly using NASM and C using GCC. I will be primarily testing using QEMU (Quick EMUlator) but may eventually use VirtualBox or Parallels.

As I am still rather naive in regards to Operating Systems, it is hard for me really nail down the individual components that will make up the final project. I think that one of the most challenging parts of this endeavor will be learning everything I need to to make this project a success and figuring out what features and components I can/should leave out.

As of now I have implemented a bootloader that bootstraps the OS, switches from 16 bit real mode to 32 bit protected mode and switches to a C kernel.
	
###Progress
- √ Bootstraps into memory
- √ Switches to 32 bit protected mode
- √ Runs a C Kernel
- √ Accepts keyboard input
- Functional Kernel
- Read and Writes files
- Interrupt handler
- File System
- Run applications

###Specs
Languages: x86 Assembly (nasm), C (gcc)

Currently run on: QEMU [Quick EMUlator] booting from a floppy.
Future goal: Create ISO image to run in a virtual machine.

###Versions
05/15/14  
1) HelloOS - Simple 16 bit Operating System that loads and prints a hello message



06/01/14  
2) Interactive - 16 bit Operating System that echos keyboard input to the screen



07/08/14  
3) Bootstrapping - OS that bootstraps from a floppy to memory and jumps to the C Kernel



07/17/14  
4) Kernel - Changes background and text color. Takes protected mode keyboard input.


###Sources:
- OS Development Series - brokenthorn.com
- Writing a Simple Operating System — from Scratch by Nick Blundell
- Write Your Own Operating System Tutorial - joelgompert.com
- Writing a 16-bit Real mode OS [NASM] - appusajeev.wordpress.com
- Onyxkernel -- First Steps -
- Operating Systems Design and Implementation - Andrew S Tanenbaum
