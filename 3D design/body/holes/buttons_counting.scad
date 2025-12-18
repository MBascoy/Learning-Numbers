include<../../global_constants.scad>

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

module buttons_counting(){

        
        //buttons
        for(i=[0:1:7]){
            translate([(button_x_placement*i)+button_starting_x, button_y_placement, cylinder_radius-button_size])cube(button_size);
        }
        
        for(i=[0:1:7]){
            translate([(button_x_placement*i)+button_starting_x, button_y_placement-button_y_second_row, cylinder_radius-button_size])cube(button_size);
        }
        
        //leds
        led_starting_x=button_starting_x + (button_size/2);
        
        led_x_placement=button_size + button_x_margin;
        led_y_placement=-82;
        led_y_second_row=30;
        
        
        for(i=[0:1:7]){
            translate([(led_x_placement*i)+led_starting_x, led_y_placement, cylinder_radius-led_height])cylinder(led_height, led_size, led_size);
        }
        
        for(i=[0:1:7]){
            translate([(led_x_placement*i)+led_starting_x, led_y_placement-led_y_second_row, cylinder_radius-led_height])cylinder(led_height, led_size, led_size);
        }
        
        
        //confirm button
        translate([confirm_button_x, confirm_button_y, cylinder_radius-button_size])cube(button_size);
        
}
