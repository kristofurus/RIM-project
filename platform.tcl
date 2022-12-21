# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\Users\krist\workspace\rim_projekt\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\Users\krist\workspace\rim_projekt\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {rim_projekt}\
-hw {C:\Users\krist\VivadoProjects\RIM_projekt\rim_projekt.xsa}\
-out {C:/Users/krist/workspace}

platform write
domain create -name {standalone_microblaze_0} -display-name {standalone_microblaze_0} -os {standalone} -proc {microblaze_0} -runtime {cpp} -arch {32-bit} -support-app {empty_application}
platform generate -domains 
platform write
platform generate -quick
platform generate
bsp reload
platform config -updatehw {C:/Users/krist/VivadoProjects/RIM_projekt/rim_projekt.xsa}
platform generate -domains 
