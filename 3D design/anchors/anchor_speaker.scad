include<../global_constants.scad>

//anchors for speaker

module anchor_speaker(){
    speaker_anchor_size_x=speaker_size;
    speaker_anchor_size_y=speaker_size;
    speaker_anchor_height=7;
    
    speaker_anchor_hole_height=5;
    speaker_anchor_hole_radius=1.4;

    speaker_circle_size=13;
    anchor_adjust=2.9;
    anchor_margin=1.5;

    difference(){
        translate([speaker_x - anchor_margin, speaker_y - anchor_margin,-wall_size_offset_x + cylinder_radius-speaker_anchor_height])cube([speaker_anchor_size_x + anchor_margin*2, speaker_anchor_size_y + anchor_margin*2, speaker_anchor_height]);
            
        translate([speaker_x + anchor_adjust,speaker_y + anchor_adjust, -wall_size_offset_x + cylinder_radius-speaker_anchor_height + speaker_anchor_height -speaker_anchor_hole_height])cylinder(speaker_anchor_hole_height,speaker_anchor_hole_radius,speaker_anchor_hole_radius);
            
        translate([speaker_x + speaker_size - anchor_adjust, speaker_y + anchor_adjust,-wall_size_offset_x + cylinder_radius - speaker_anchor_hole_height])cylinder(speaker_anchor_hole_height,speaker_anchor_hole_radius,speaker_anchor_hole_radius);
        

        translate([speaker_x + anchor_adjust, speaker_y + speaker_size - anchor_adjust,-wall_size_offset_x + cylinder_radius - speaker_anchor_hole_height])cylinder(speaker_anchor_hole_height,speaker_anchor_hole_radius,speaker_anchor_hole_radius);
        

        translate([speaker_x + speaker_size - anchor_adjust, speaker_y + speaker_size - anchor_adjust,-wall_size_offset_x + cylinder_radius - speaker_anchor_hole_height])cylinder(speaker_anchor_hole_height,speaker_anchor_hole_radius,speaker_anchor_hole_radius);
        
         translate([speaker_x + (speaker_anchor_size_x /2), speaker_y +speaker_anchor_size_y /2,0])cylinder(cylinder_radius,speaker_circle_size,speaker_circle_size);
    }
}
