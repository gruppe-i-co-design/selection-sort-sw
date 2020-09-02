connect -url tcp:127.0.0.1:3121
targets -set -nocase -filter {name =~"APU*"}
rst -system
after 3000
targets -set -filter {jtag_cable_name =~ "Digilent Zybo 210279651829A" && level==0 && jtag_device_ctx=="jsn-Zybo-210279651829A-13722093-0"}
fpga -file /home/oruud/VWorkspace3/selection_sort_sw_app/_ide/bitstream/selection_sort_sw_design_wrapper.bit
targets -set -nocase -filter {name =~"APU*"}
loadhw -hw /home/oruud/VWorkspace3/selection_sort_sw/export/selection_sort_sw/hw/selection_sort_sw_design_wrapper.xsa -mem-ranges [list {0x40000000 0xbfffffff}] -regs
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*"}
source /home/oruud/VWorkspace3/selection_sort_sw_app/_ide/psinit/ps7_init.tcl
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "*A9*#0"}
dow /home/oruud/VWorkspace3/selection_sort_sw_app/Debug/selection_sort_sw_app.elf
configparams force-mem-access 0
targets -set -nocase -filter {name =~ "*A9*#0"}
con
