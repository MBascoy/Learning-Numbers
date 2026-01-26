include<../../global_constants.scad>

border_depth = 1.25;
border_size = 2.5;

module power_switch(){
        translate([ -power_switch_size_x, -power_switch_size_y, power_switch_z])cube([power_switch_size_x, power_switch_size_y, power_switch_size_y]);
    
        translate([ -power_switch_size_x, -power_switch_size_y - border_depth, power_switch_z - (border_size / 2)])cube([power_switch_size_x, power_switch_size_y, power_switch_size_y + border_size]);
}
