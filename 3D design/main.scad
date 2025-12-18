include<global_constants.scad>;

use<body/body_top.scad>;
use<body/body_bottom.scad>;
use<anchors/anchor_speaker.scad>;
use<anchors/anchor_body.scad>;

//body
body_top();
body_bottom();

//anchors
anchor_speaker();
anchor_body();