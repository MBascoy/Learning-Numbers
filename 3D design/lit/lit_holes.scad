include<../global_constants.scad>;


module lit_battery_hole(){
    translate([40,-80,0]) cube([52,37,lit_height]);
}
module lit_holes(){
    //top left anchor
    base_hole(body_left_anchor_x, anchor_top_y);
    
    //bottom left anchor
    base_hole(body_left_anchor_x, anchor_bottom_y);
    
    //top right anchor
    base_hole(body_right_anchor_x, anchor_top_y);
    
    //bottom right anchor
    base_hole(body_right_anchor_x, anchor_bottom_y);
}

module base_hole(x, y){
    translate([x, y, 0]){
        cylinder(anchor_height, screw_size, screw_size);
        cylinder(screw_top_height, screw_size*2, screw_size);
    }
}