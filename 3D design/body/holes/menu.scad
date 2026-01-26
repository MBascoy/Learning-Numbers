include<../../global_constants.scad>

button_size=8.2;
size_adjust=0.3;

button_x=3;
button_y=-54;

button_volume_x=36;

button_margin=3;

module buttons_levels(){
    for(i=[0:1:2]){
        translate([button_x - (size_adjust/2), button_y - (size_adjust/2) - (button_size + button_margin) * i, cylinder_radius-button_size])cube(button_size + size_adjust);
    }
}

module buttons_volume(){
    for(i=[0:1:1]){
        translate([button_volume_x - (size_adjust/2), button_y - (size_adjust/2) - (button_size + button_margin) * i, cylinder_radius-button_size])cube(button_size + size_adjust);
    }
}

text_size=4;
text_font="DynaPuff:style=SemiBold";


module text_menu(){
    text_x=button_x + 10;

    text_level1_y=button_y + 1;
    text_level2_y=text_level1_y - button_size - button_margin;
    text_level3_y=text_level2_y - button_size - button_margin;
    
    translate([text_x, text_level1_y, cylinder_radius-text_depth]){
        linear_extrude(text_depth)
        text( "FÁCIL", size=text_size, font=text_font);
    }

    translate([text_x, text_level2_y, cylinder_radius-text_depth]){
        linear_extrude(text_depth)
        text( "DIFÍCIL", size=text_size, font=text_font);
        
    }
    
    translate([text_x, text_level3_y, cylinder_radius-text_depth]){
        linear_extrude(text_depth)
        text( "PRACTICAR", size=text_size, font=text_font);
        
    }
}

module text_volume(){
    text_volume_x=button_volume_x + 9;
    text_volume_y=button_y + 1;
    
    translate([text_volume_x, text_volume_y, cylinder_radius-text_depth]){
        linear_extrude(text_depth)
        text( "Vol+", size=text_size, font=text_font);
    }

    translate([text_volume_x, text_volume_y - button_size - button_margin, cylinder_radius-text_depth]){
        linear_extrude(text_depth)
        text( "Vol-", size=text_size, font=text_font);
        
    }
}