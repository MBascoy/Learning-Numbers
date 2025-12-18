include<../../global_constants.scad>

module screen(){
        translate([screen_x, screen_y, cylinder_radius-screen_size])cube([screen_size*2, screen_size, screen_size]);
}
