include<../global_constants.scad>

text_depth=1.2;
text_big_size=7;
text_small_size=4;
text_font="DynaPuff:style=SemiBold";
text_margin=3;

confirm_margin_x = 2;
confirm_margin_y = 6;

module body_text(){
    text_x=40;
    text_y=-28;
    
    base_big_text(text_x, text_y, "Números");
    base_big_text(text_x, text_y - text_big_size - text_margin, "con Padrino");
    
    base_small_text(confirm_button_x + confirm_margin_x, confirm_button_y - confirm_margin_y, "OK");
}

module base_big_text(x, y, message){
    translate([x, y, cylinder_radius-text_depth]){
        linear_extrude(text_depth)
        text( message, size=text_big_size, font=text_font);
    }
}

module base_small_text(x, y, message){
    translate([x, y, cylinder_radius-text_depth]){
        linear_extrude(text_depth)
        text( message, size=text_small_size, font=text_font);
    }
}