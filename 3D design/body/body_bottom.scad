include<../global_constants.scad>

//main body bottom part for walls

module body_bottom(){
    difference(){
        body_bottom_solid();
        translate([wall_size_offset_x,-wall_size_offset_y, 0]){
            scale([1-(wall_size/100), 1-(wall_size/100),1]){
                body_bottom_solid();
            }
        }
    }

    module body_bottom_solid(){
        hull(){
            translate([-cylinder_radius, -body_size, -body_height])
            cube([cylinder_radius*2,body_size,body_height]);

            translate([-cylinder_radius + body_size, -body_size, -body_height])
            cube([cylinder_radius*2,body_size - body_size_diff,body_height]);
                
            translate([0, -body_size-cylinder_radius, -body_height])
            cube([body_size ,cylinder_radius,body_height]);
        }
    }
}