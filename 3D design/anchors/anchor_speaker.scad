include<../global_constants.scad>

outer_size=3.5;
inner_size=1.5;

anchor_height=3.5;

anchor_margin=4;

inner_size_margin=0.4;

top_y = speaker_y + (speaker_size_y/2);

left_anchor_x = speaker_x - anchor_margin;
right_anchor_x = speaker_x + speaker_size + anchor_margin;



module anchor_speaker(){
    //left anchor
    base_anchor(left_anchor_x, top_y);
    
    //right anchor
    base_anchor(right_anchor_x, top_y);
}

module base_anchor(x, y){
        translate([x, y, -wall_size_offset_x +cylinder_radius - anchor_height])
    difference(){
        cylinder(anchor_height, outer_size, outer_size);
        cylinder(anchor_height, inner_size, inner_size - inner_size_margin);
    }
}
