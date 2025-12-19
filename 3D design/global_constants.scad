$fn=50;

body_size=140;
body_size_diff=30;
cylinder_radius=15;
body_height=15;

wall_size=4;
wall_size_offset_x= (body_size*(wall_size/100))/2;
wall_size_offset_y= ((body_size+cylinder_radius)*(wall_size/100))/2;

speaker_size=28;
speaker_x=5;
speaker_y=-40;

screen_size=32;
screen_x=58;
screen_y=-70;

power_switch_size_x=13.4;
power_switch_size_y=9.2;
power_switch_z=-power_switch_size_y;

button_size=12.5;
button_x_margin=5;
button_starting_x=3;

button_x_placement=button_size + button_x_margin;
button_y_placement=-100;
button_y_second_row=30;

confirm_button_x=body_size - button_size-2;
confirm_button_y=-60;

led_size=2.6;
led_height=10;