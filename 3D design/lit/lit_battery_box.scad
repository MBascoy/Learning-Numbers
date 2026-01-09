include<../global_constants.scad>;

cables_hole = 7;

battery_screws_spacing = 25;

battery_screws_pos = (lit_battery_y_size - battery_screws_spacing) / 2;

module lit_battery_box(){
    // Left wall
    translate([lit_battery_x - battery_wall, lit_battery_y, lit_height]) cube([battery_wall, lit_battery_y_size + battery_wall, battery_height]);
    
    // Top wall
    translate([lit_battery_x, lit_battery_y + lit_battery_y_size, lit_height]) cube([lit_battery_x_size + battery_wall, battery_wall, battery_height]);
    
    // Right wall
    translate([lit_battery_x + lit_battery_x_size, lit_battery_y, lit_height]) cube([battery_wall, lit_battery_y_size - cables_hole, battery_height]);
    
    // Bottom wall
    translate([lit_battery_x - battery_wall, lit_battery_y - battery_wall, lit_height]) cube([lit_battery_x_size + (battery_wall*2), battery_wall, battery_height]);
    
    // Roof
    difference(){
        translate([lit_battery_x - battery_wall, lit_battery_y - battery_wall, lit_height + battery_height]) cube([lit_battery_x_size+ (battery_wall*2), lit_battery_y_size + (battery_wall*2), battery_wall]);
        
        translate([lit_battery_x + (lit_battery_x_size/2), lit_battery_y + battery_screws_pos, lit_height + battery_height]) cylinder(battery_wall, screw_size, screw_size);
        
        translate([lit_battery_x + (lit_battery_x_size/2), lit_battery_y + battery_screws_pos + battery_screws_spacing, lit_height + battery_height]) cylinder(battery_wall, screw_size, screw_size);
    }
}
