include<../global_constants.scad>;


module lit_battery_hole(){
    translate([lit_battery_x, lit_battery_y, 0]) cube([lit_battery_x_size, lit_battery_y_size, lit_height]);
}
module lit_holes(){
    //top left hole
    base_hole(body_left_anchor_x, anchor_top_y);
    
    //bottom left hole
    base_hole(body_left_anchor_x, anchor_bottom_y);
    
    //top right hole
    base_hole(body_right_anchor_x, anchor_top_y);
    
    //bottom right hole
    base_hole(body_right_anchor_x, anchor_bottom_y);
}

module base_hole(x, y){
    translate([x, y, 0]){
        cylinder(anchor_height, screw_size, screw_size);
        cylinder(screw_top_height, screw_size*2, screw_size);
    }
}