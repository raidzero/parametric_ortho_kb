include <vars.scad>;

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
            // front left
            cylinder(r=bezel_r, h=height);
            
            // front right
            translate([case_length + bezel_r, 0, 0]) cylinder(r=bezel_r, h=height);
            
            // back right
            translate([case_length + bezel_r, case_depth + bezel_r, 0]) cylinder(r=bezel_r, h=height);
            
            // back left
            translate([0, case_depth + bezel_r, 0]) cylinder(r=bezel_r, h=height);
        }
}

module case_cavity(height) {
    hull() {
            // front left
            translate([bezel_r*2 - bezel_r/2, bezel_r*2 - bezel_r/2, 0.01])
                cylinder(r=bezel_r, h=height);
            
            // front right
            translate([(case_length + bezel_r) - (bezel_r*2 - bezel_r/2) , bezel_r*2 - bezel_r/2, 0.01]) 
                cylinder(r=bezel_r, h=height);
            
            // back right
            translate([(case_length + bezel_r) - (bezel_r*2 - bezel_r/2), (case_depth + bezel_r) - (bezel_r*2 - bezel_r/2), 0.01]) 
                cylinder(r=bezel_r, h=height);
            
            // back left
            translate([bezel_r*2 - bezel_r/2, (case_depth + bezel_r) - (bezel_r*2 - bezel_r/2), 0.01]) 
                cylinder(r=bezel_r, h=height);
        }
}

module heatsert_guide(height) {
    union() {
        cylinder(d=m3_hs_d, h=height);
        translate([0, 0, height*0.85])
            cylinder(d=m3_hs_d+0.75, h=height*0.23);
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