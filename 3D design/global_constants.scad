$fn=50;

// Body
body_size=140;
body_size_diff=30;
cylinder_radius=15;
body_height=15;

wall_size=4;
wall_size_offset_x= (body_size*(wall_size/100))/2;
wall_size_offset_y= ((body_size+cylinder_radius)*(wall_size/100))/2;

// Anchors
anchor_outer_size=4.5;
anchor_inner_size=2.5;

anchor_inner_size_margin=0.4;

anchor_height=7;
anchor_height_margin=2;

anchor_top_y=-38;
anchor_bottom_y=-125;

body_left_anchor_x = -cylinder_radius + anchor_outer_size + anchor_outer_size - anchor_inner_size;

body_right_anchor_x = body_size + cylinder_radius - (anchor_outer_size + anchor_outer_size - anchor_inner_size);

// Lit
screw_size = 1.65;
screw_top_height = 1.5;

lit_height = 3;

lit_battery_x = 40;
lit_battery_y = -140;

lit_battery_x_size = 52;
lit_battery_y_size = 37;

battery_wall = lit_height;

battery_height = 15;

// Speaker
speaker_size=28.2;
speaker_size_y=31.2;
speaker_x=5;
speaker_y=-43;

// Screen
screen_size=32.2;
screen_x=58;
screen_y=-75;

// Power switch
power_switch_size_x=13.4;
power_switch_size_y=9.2;
power_switch_z=-power_switch_size_y;

// Buttons
button_size=12.5;
button_x_margin=5;
button_starting_x=3;

button_x_placement=button_size + button_x_margin;
button_y_placement=-100;
button_y_second_row=30;

confirm_button_x=body_size - button_size-2;
confirm_button_y=-60;

// Leds
led_size=2.6;
led_height=10;