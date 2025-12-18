include<../global_constants.scad>

outer_size=4;
inner_size=2;

anchor_height=5;

left_anchor_x = -cylinder_radius + outer_size + outer_size - inner_size;

right_anchor_x = body_size + cylinder_radius - (outer_size + outer_size-inner_size);

top_y=-38;
bottom_y=-125;

module anchor_body(){
    
    //top left anchor
    base_anchor(left_anchor_x, top_y);
    
    //bottom left anchor
    base_anchor(left_anchor_x, bottom_y);
    
    //top right anchor
    base_anchor(right_anchor_x, top_y);
    
    //bottom right anchor
    base_anchor(right_anchor_x, bottom_y);
}

module base_anchor(x, y){
        translate([x, y, -body_height])
    difference(){
        cylinder(anchor_height, outer_size, outer_size);
        cylinder(inner_size, inner_size, inner_size);
    }
}