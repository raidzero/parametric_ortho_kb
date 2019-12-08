include <vars.scad>;
use <misc.scad>;

tolerance = 0.2; // my printer makes smaller holes than I ask it to

ht_r =(1.44 + tolerance) / 2;        // holtite diameter
ht_length = 4;      // holtite length

mx_post_h = 2.25; // length of center mx post
mx_center_post_r = (3.75 + tolerance) / 2; // mx center post diameter
mx_side_post_r = (1.7 + tolerance) / 2; // mx side post diameter
mx_side_x_offset = 5; // how far from the center post the side posts are

mx_spacing = 3;

// distances from center post of switch
right_ht_pos = [3.5, 2.5];
left_ht_pos = [2.5, 4.5];

mx_size = switch_hole_size; //15.85;

leds_south = true; // holtile holes go above center post 
led_leg_r = (0.4 + tolerance);
led_x_spacing = 2.5;
led_y_spacing = 5.2;

channel_depth = mx_post_h / 1.5;

module switch_helper(height) {
    // left holtite position
    l_x = left_ht_pos[0];
    l_y = left_ht_pos[1];

    // right holtite position
    r_x = -(right_ht_pos[0]);
    r_y = right_ht_pos[1];

    union() {
        linear_extrude(height = height * 2) {
            
            // mx center post (everything relative to this)
            translate([mx_size / 2, mx_size / 2]) {
                circle(r=mx_center_post_r);

                // left holtite
                translate([l_x, l_y]) {
                    circle(r=ht_r);
                }

                // right holtite
                translate([r_x, r_y]) {
                    circle(r=ht_r);
                }

                // left side post
                translate([mx_side_x_offset, 0])
                    circle(r=mx_side_post_r);

                // right side post
                translate([-mx_side_x_offset, 0])
                    circle(r=mx_side_post_r);

                // leds
                /*
                translate([0, -led_y_spacing]) {
                    translate([led_x_spacing/2, 0]) 
                        circle(r=led_leg_r);
                    translate([-led_x_spacing/2, 0]) 
                        circle(r=led_leg_r);
                }
                */
            }
        }
    }


    union() {
        // cut out channels
        translate([mx_size / 2, mx_size / 2, 0]) {

            channel_length = 8;
            channel_width = 1.6;

            translate([r_x, r_y]) {
                linear_extrude(height = channel_depth * 2) {
                    // room to loop diode leads and solder
                    circle(r=ht_r * 2.5);
                    
                    // diode channel under upper holtite
                    translate([0,-channel_length])
                        #square([channel_width, channel_length]);

                    // row wire channel
                    translate([-mx_size/2 - switch_spacing/4, -channel_length - channel_width / 2])
                        square([mx_size + switch_spacing*2, channel_width]);
                }
            }

            translate([l_x, l_y]) {
                linear_extrude(height = channel_depth * 2) {
                    // room to loop column wires and solder
                    circle(r=ht_r * 2.5);

                    // column wire channel - math not good here 
                    translate([0,-channel_length - 6])
                        #square([channel_width, channel_length * 2.5]);
                }
            }
        }
    }
}

module helper_plate() {
    difference () {
        case_shape(helper_thickness);

        // cut out switch helpers
        for (x = [0:switchColumns - 1]) {
            for (y = [0:rows - 1]) {
                pos = switch_location(x, y);
                translate([pos[0], pos[1], -0.1])
                    switch_helper(helper_thickness);
            }
        }
        
        // cut out screw holes
        for (i = [0:len(screw_locs) - 1]) {
            translate([screw_locs[i][0], screw_locs[i][1], - 0.1])
                cylinder(d=screw_d, h=helper_thickness * 2);
        }
        
        if (needs_center_plate_screw) {
            center_pos = switch_location(switchColumns/2, rows/2);
            center_x = center_pos[0] - switch_spacing; center_y = center_pos[1] - switch_spacing;

            translate([center_x, center_y, helper_thickness + 0.1])
                rotate(180, [1, 0, 0])
                    cylinder(d=screw_d, h=helper_thickness * 2);
        }

        // cut out empty space
        //translate([0,0, helper_thickness/2])
        //    case_cavity(helper_thickness);
    }

   
}

helper_plate();
//switch_helper();
