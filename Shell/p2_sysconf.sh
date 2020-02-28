#! /bin/bash

# Write shell script to show various system configurations like
#   1) your OS and version, release number, kernel version
#   2) all available shells
#   3) computer CPU information like processor type, speed etc
#   4) memory information
#   5) hard disk information like size of hard-disk, cache memory, model etc
#   6) File system (Mounted)

echo -e "$(cat /etc/os-release)"
echo -e "$(cat /etc/shells/)"
echo -e "$(xset q)"
echo -e "$(cat /proc/meminfo)"
echo -e "Driver: $(sudo hdparm -I /dev/sda)"
echo -e "$(cat /proc/mounts)"
