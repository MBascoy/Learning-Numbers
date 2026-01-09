include<../global_constants.scad>;

module lit_battery_box(){
    // Left wall
    translate([lit_battery_x - battery_wall, lit_battery_y, lit_height]) cube([battery_wall, lit_battery_y_size + battery_wall, battery_height]);
    
    // Top wall
    translate([lit_battery_x, lit_battery_y + lit_battery_y_size, lit_height]) cube([lit_battery_x_size, battery_wall, battery_height]);
    
    // Right wall
    translate([lit_battery_x + lit_battery_x_size, lit_battery_y, lit_height]) cube([battery_wall, lit_battery_y_size + battery_wall, battery_height]);
    
    // Bottom wall
    translate([lit_battery_x - battery_wall, lit_battery_y - battery_wall, lit_height]) cube([lit_battery_x_size + (battery_wall*2), battery_wall, battery_height]);
    
    // Roof
    translate([lit_battery_x - battery_wall, lit_battery_y - battery_wall, lit_height + battery_height]) cube([lit_battery_x_size+ (battery_wall*2), lit_battery_y_size + (battery_wall*2), battery_wall]);
}
