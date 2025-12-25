include<../global_constants.scad>

outer_size=4.5;
inner_size=2.5;

inner_size_margin=0.4;

anchor_height=4;

top_y=-38;
bottom_y=-105;

left_anchor_x = outer_size + button_starting_x - (outer_size - inner_size) + button_size;

right_anchor_x = body_size - outer_size - button_size;

top_right_anchor_x = confirm_button_x + inner_size;

top_left_anchor_x = screen_x - outer_size*2;

module anchor_pcb(){
    
    //top left anchor
    base_anchor(top_left_anchor_x, top_y -inner_size);
    
    //bottom left anchor
    base_anchor(left_anchor_x, bottom_y);
    
    //top right anchor
    base_anchor(top_right_anchor_x, top_y -inner_size);
    
    //bottom right anchor
    base_anchor(right_anchor_x, bottom_y);
}

module base_anchor(x, y){
        translate([x, y, -wall_size_offset_x +cylinder_radius - anchor_height])
    difference(){
        cylinder(anchor_height, outer_size, outer_size);
        cylinder(anchor_height, inner_size, inner_size - inner_size_margin);
    }
}