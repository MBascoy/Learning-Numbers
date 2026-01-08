include<global_constants.scad>;

use<body/body_bottom.scad>;
use<lit/lit_holes.scad>;

difference(){
    hull() linear_extrude(height = lit_height) projection() body_bottom();
  
    lit_holes();
    
    lit_battery_hole();
}