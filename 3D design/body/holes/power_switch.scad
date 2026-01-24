include<../../global_constants.scad>

module power_switch(){
        translate([ -(power_switch_size_x), -power_switch_size_y, power_switch_z])cube([power_switch_size_x, power_switch_size_y, power_switch_size_y]);
}
