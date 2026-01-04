include<../../global_constants.scad>

module speaker(){
    translate([speaker_x, speaker_y, cylinder_radius-speaker_size])cube([speaker_size,speaker_size_y,speaker_size]);
}
