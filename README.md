THOS
=================
**Tyler James Higley**

This is a repository for Tyler Higley's 2015 Computer Science Senior Thesis Project. Version 1.0 has been complete as of May 5th 2015.

###Abstract
An operating system is the software that interfaces between users and the underlying hardware of the machine. It manages all of the computers resources and provides a platform on which other programs may operate. For my senior computer science thesis I wrote a simple minimally functional operating system for the x86 architecture using C and Assembly Language. The design and implementation, when possible, took primary inspiration from the Unix operating system. It has an inode based filesystem with a directory structure, interrupt driven user input, and command line interface. The OS in question, THOS, is integrated with the GRUB bootloader and is equipped with a builtin text editor.

###How to Use
You will need QEMU Installed (qemu-system-i386)
- Change directory to Version 1.0
- ./run

###Features
Here are all the features built into THOS.
- Commands (ls, cat, rm, wc, history, chmod, chown, su, adduser, deluser, listus, echo, passwd, pwd, cd, mkdir, rmdir, mv)
- Text Editor (te)
- Pong Game
- Tab Autocomplete
- Inode Filesystem with Directories

###Future Plans
Here is a list of features that would be nice to include in the near future. 
- Additional Commands (cp, diff, more, ff, grep, date, cal, kill, ps, chgrp, addgrp, rmgrp)
- Text Editor Uograde
- Scripting 
- Improve Filesystems
- Pipe standard output
- Process Manager and System Calls
