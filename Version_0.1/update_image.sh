#!/bin/bash

sudo losetup /dev/loop0 floppy.img
sudo mount /dev/loop0 /mnt
sudo cp bin/kernel /mnt/kernel
sudo cp menu.lst /mnt/boot/grub/menu.lst
sudo umount /dev/loop0
sudo losetup -d /dev/loop0
