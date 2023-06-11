#!/bin/bash

#First we need to  gather all infos...
#=====================================================================================================
# No 01:   The architecture of your operating system and its kernel version.
arch=$(uname -a)

# No 02:   The number of physical processors.
phy_proc=$(grep "physical id" /proc/cpuinfo | wc -l)

# No 03:   The number of virtual processors.
vir_proc=$(grep processor /proc/cpuinfo | wc -l)

# No 04:   The current available RAM on your server and its utilization rate as a percentage.
ram_ava=$(free -m | grep  "Mem:" | awk '{print $7}')
ram_total=$(free -m | grep  "Mem:" | awk '{print $2}')
ram_uti=$(echo "scale=1; ($ram_ava *100  / $ram_total)" | bc)

# No 05:   The current available memory on your server and its utilization rate as a percentage.
mem_ava=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{ava += $4} END {print ava "M"}')
mem_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{total += $2} END {print total "M"}')
mem_uti=$(echo "scale=1; ($mem_ava *100  / $mem_total)" | bc)

# No 06:   The current utilization rate of your processors as a percentage.
proc_wait=$(vmstat 1 2 | tail -1 | awk '{printf $15}') #15 = wa = time spent waiting for I/O
proc_uti=$(expr 100 - $proc_wait)

# No 07:   The date and time of the last reboot.
last_reboot=$(who -b | awk '$1=="system" && $2=="boot" {print $3 " " $4}')

# No 08:   Whether LVM is active or not.
lvm_status=$(if [ $(lsblk | grep "lvm" | wc -l) -ge 1 ]; then echo "yes"; else echo "no"; fi)

# No 09:   The number of active connections.
ac_conn=$(ss -ta | grep ESTAB | wc -l)
#ss network sockets
#       -ta all TCP Connections

# No 10:   The number of users using the server.
count_users=$(users | wc -w)

# No 11:   The IPv4 address of your server and its MAC (Media Access Control) address.
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# No 12:   The number of commands executed with the sudo program
count_sudo_cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)



#...then we will put the message together...
#====================================================================================================
MSG="
===============================================================================
Architecture:
$arch

Physical processors:\t\t$phy_proc
Virtual processors:\t\t$vir_proc
Untilization of processors:\t${proc_uti}%

Available RAM:\t\t\t${ram_ava}M / ${ram_total}M ($ram_uti%)
Available Memory:\t\t$mem_ava / $mem_total ($mem_uti%)

Server Address:\t\t\t$ip (${mac})
Active Connections:\t\t$ac_conn

Last reboot:\t\t\t$last_reboot
LVM active:\t\t\t$lvm_status
Number of users:\t\t$count_users
Count of sudo cmds:\t\t$count_sudo_cmds
===============================================================================
"



#...then we will print the MSG to all terminals using 'wall'
#====================================================================================================
echo -e "$MSG" | fold -w80 | wall
#-e = enable escape sequences


