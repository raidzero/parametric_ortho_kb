$fn=20;
$fs=0.3;

split = false;
needs_center_plate_screw = true;
hotswap = true;

rows = 2;
columns = 2;
switchColumns = (split) ? columns / 2 : columns; // the number of columns to use when making the switch grid

// magnet dimens
magnet_d = 10.2; // diameter
magnet_t = 2.7; // thickness

switch_hole_size = 14;
switch_spacing = 3; // 3mm on either size of switch hole

plate_thickness = 1.4;
plate_spacer_thickness = 3.4;
helper_thickness = 6 - plate_thickness;

bezel_r = switch_spacing; // corner bezel radius
bezel_d = bezel_r/2 - bezel_r/2;

base_height = magnet_d + 1.5; //15; // height of base, inlcuding cutout

echo("total height", base_height + helper_thickness + plate_thickness + plate_spacer_thickness);

// the amount of space used to calculate grid size
ss = switch_hole_size + switch_spacing * 2; 

// overall case size before bezels
case_length = (split) ? ss * columns / 2 : ss * columns;
case_depth = ss * rows;

case_thickness_factor = 1.5;

// screw params
screw_h = 10;
screw_d = 3.2;
screw_head_diff = 2.5;
screw_head_h = 3;

cs_head_diff = 2.8;
cs_head_h = 2.8;

// outside screw hole 
screw_locs = [
    [ bezel_d, bezel_d], // front left
    [ case_length + bezel_d, bezel_d], // front right
    [ case_length + bezel_d, case_depth + bezel_d], // back right
    [ bezel_d, case_depth + bezel_d] // back left
];

// outer limits of case
back_of_case = screw_locs[2][1] + bezel_r * case_thickness_factor;
right_edge_of_case = screw_locs[2][0] + bezel_r * case_thickness_factor;



// m3 heat sert diameter
m3_hs_d = 5.5; 

jack_hole_d = 6.35;
jack_barrel_d = 8.5;

// pro micro
mcu_l = 33.75;
mcu_w = 18;
mcu_h = 1.5;
usb_w = 8;
usb_h = 3.75;

solder_channel_w = 3;
solder_channel_d = 2;