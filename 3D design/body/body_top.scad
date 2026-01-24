include<../global_constants.scad>;

use<holes/buttons_counting.scad>;
use<holes/menu.scad>;
use<body_text.scad>;
use<holes/speaker.scad>;
use<holes/screen.scad>;
use<holes/power_switch.scad>

//top part
module body_top(){
    difference(){
        body_top_walls();

        body_text();

        //holes for components
        buttons_levels();
        buttons_volume();
        text_menu();
        text_volume();
        buttons_counting();
        speaker();
        screen();
        power_switch();
}
    
    
    module body_top_walls(){
        difference(){
            difference(){
                body_solid();
                
                translate([-(cylinder_radius*2),-body_size*2,-(cylinder_radius*2)]){
                    cube([body_size*2,body_size*2,cylinder_radius*2]);
                }
            }

            translate([wall_size_offset_x,-wall_size_offset_y, -wall_size_offset_x]){
                scale([1-(wall_size/100), 1-(wall_size/100),1]){
                    body_solid();
                }
            }
        } 
    }
    
    module body_solid(){
        hull(){
            rotate([90,0,0]){
                cylinder(body_size, cylinder_radius, cylinder_radius);
            }
            translate([body_size,-body_size_diff,0]){
                rotate([90,0,0]){
                    cylinder(body_size - body_size_diff, cylinder_radius, cylinder_radius); 
                }
            }


            translate([0,-body_size,0]){
                rotate([0,90,0]){
                    cylinder(body_size, cylinder_radius, cylinder_radius);
                }
            }
        }
    }
}