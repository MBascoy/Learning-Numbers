include<../global_constants.scad>;

module anchor_battery(){
    
    //left anchor
    base_anchor(lit_battery_x + anchor_outer_size - (anchor_inner_size/2), lit_battery_y + (lit_battery_y_size/2));
    
    //top right anchor
    base_anchor(lit_battery_x +  lit_battery_x_size - anchor_outer_size + (anchor_inner_size/2), lit_battery_y + (lit_battery_y_size/2));
}


module base_anchor(x, y){
        translate([x, y, lit_height])
    difference(){
        cylinder(anchor_height + anchor_height_margin, anchor_outer_size, anchor_outer_size);
        cylinder(anchor_height, anchor_inner_size, anchor_inner_size - anchor_inner_size_margin);
    }
}