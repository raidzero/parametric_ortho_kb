include <vars.scad>;

// return the location for a switch hole given a column and row grid number
function switch_location(column, row) = [ 
    (column * ss) + bezel_r, 
    (row * ss) + bezel_r ];

module screw() {
    union() {
        cylinder(d=screw_d + screw_head_diff, h=screw_head_h);
        translate([0, 0, screw_head_h])
            cylinder(d=screw_d, h=screw_h);
    }
}

module countersunk_screw() {
    union() {
        cylinder(d1=screw_d + cs_head_diff, d2=screw_d, h=cs_head_h);
        translate([0, 0, cs_head_h-0.01])
            cylinder(d=screw_d, h=screw_h + 0.01);
    }
}

module case_shape(height) {
    hull() {
        for (i = [0:len(screw_locs) - 1]) {
            screw_x = screw_locs[i][0]; screw_y = screw_locs[i][1];

            translate([screw_x, screw_y, 0])
                cylinder(r=bezel_r * case_thickness_factor, h=height);
        }
    }
}

module case_cavity(height) {
    right_switch = (split) ? columns/2 : columns;

    front_left = switch_location(0, 0);
    back_right = switch_location(right_switch, rows);

    cavity_length = back_right[0] - switch_spacing*2 - front_left[0];
    cavity_depth = back_right[1] - switch_spacing*2 - front_left[1];

    translate([front_left[0], front_left[1], 0])
        cube([cavity_length, cavity_depth, height]);
}

module heatsert_guide(height) {
    union() {
        cylinder(d=m3_hs_d, h=height);
        translate([0, 0, height*0.85])
            cylinder(d=m3_hs_d+0.5, h=height*0.23);
    }
}

module pro_micro() {
    union() {
        // board base
        cube([mcu_w, mcu_l, mcu_h + usb_h]);

        // usb port
        //translate([mcu_w/2 - usb_w/2, 0, mcu_h - 0.1])
        //    cube([usb_w, mcu_l, usb_h + 0.1]);

        // room for pins at front
        translate([0, 0, mcu_h])
            cube([mcu_w, mcu_l - 3, base_height]);

        // inside solder channel
        translate([0, 0, -solder_channel_d])
            cube([solder_channel_w, mcu_l - 1, solder_channel_d + 0.1]);

        // outside solder channel
        translate([mcu_w - solder_channel_w, 0, -solder_channel_d])
            cube([solder_channel_w, mcu_l - 1, solder_channel_d + 0.1]);
    }
}

module jack_hole() {
    // trrs jack mounting hole
    rotate(90, [1, 0, 0])
        #cylinder(d=jack_hole_d, h=case_depth/2);
    
    // trrs jack barrel hole
    translate([0, -1.75, 0])
        rotate(90, [1, 0, 0])
            #cylinder(d=jack_barrel_d, h=case_depth/2);
}

// screw holes
module screw_holes() {
    for (i = [0:len(screw_locs) - 1]) {
        screw_x = screw_locs[i][0]; screw_y = screw_locs[i][1];
        
        translate([screw_x, screw_y, plate_thickness + 0.1])
            rotate(180, [1, 0, 0])
                countersunk_screw();
    }
}

module magnet_holes() {
    union() {
        for (i = [1:rows]) {
            switch_loc = switch_location(1, i);

            translate([right_edge_of_case - magnet_t + 0.01, switch_loc[1] - magnet_d, base_height/2])
            rotate(90, [0, 1, 0])
                cylinder(d=magnet_d, h=magnet_t);
        }
    }
}