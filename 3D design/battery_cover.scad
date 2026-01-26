include<global_constants.scad>;

cover_margin = 0.3;

difference(){
    translate([cover_margin/2,0,0]) cube([lit_battery_x_size - cover_margin,  lit_battery_y_size - cover_margin, lit_height]);
    
    // Left hole
    base_hole(anchor_outer_size - (anchor_inner_size/2));
    
    // Right hole
    base_hole(lit_battery_x_size - anchor_outer_size + (anchor_inner_size/2));

}

module base_hole(x){
    translate([x, lit_battery_y_size / 2, 0]) cylinder(lit_height, screw_size, screw_size);
    
    translate([x, lit_battery_y_size / 2, lit_height-screw_top_height]) cylinder(screw_top_height, screw_size, screw_size*1.8);
}