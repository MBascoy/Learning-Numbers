include<../../global_constants.scad>

module speaker(){
    translate([speaker_x, speaker_y, cylinder_radius-speaker_size])cube(speaker_size);
}
