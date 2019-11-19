$fn=100;
$fs=0.3;

split = true;

rows = 4;
columns = 12;

switch_hole_size = 14.2;
switch_spacing = 3; // 3mm on either size of switch hole

plate_thickness = 5;
bezel_r = switch_spacing + 2; // corner bezel radius
bezel_d = bezel_r/2 - bezel_r/2;

base_height = 15; // height of base, inlcuding cutout

// the amount of space used to calculate grid size
ss = switch_hole_size + switch_spacing * 2; 

// overall case size before bezels
case_length = (split) ? ss * columns / 2 : ss * columns;
case_depth = ss * rows;

// screw params
screw_h = 10;
screw_d = 3.2;
screw_head_diff = 2.5;
screw_head_h = 3;

cs_head_diff = 2.8;
cs_head_h = 2.8;


// m3 heat sert diameter
m3_hs_d = 5.5; 

jack_hole_d = 6.35;
jack_barrel_d = 8.5;

// pro micro
mcu_l = 35;
mcu_w = 19;
mcu_h = 1.5;
usb_w = 8;
usb_h = 3.75;

solder_channel_w = 3;
solder_channel_d = 2;