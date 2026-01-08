include<../global_constants.scad>

module anchor_body(){
    
    //top left anchor
    base_anchor(body_left_anchor_x, anchor_top_y);
    
    //bottom left anchor
    base_anchor(body_left_anchor_x, anchor_bottom_y);
    
    //top right anchor
    base_anchor(body_right_anchor_x, anchor_top_y);
    
    //bottom right anchor
    base_anchor(body_right_anchor_x, anchor_bottom_y);
}

module base_anchor(x, y){
        translate([x, y, -body_height])
    difference(){
        cylinder(anchor_height + anchor_height_margin, anchor_outer_size, anchor_outer_size);
        cylinder(anchor_height, anchor_inner_size, anchor_inner_size - anchor_inner_size_margin);
    }
}