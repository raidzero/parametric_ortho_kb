include <vars.scad>;
use <misc.scad>

center_pos = switch_location(switchColumns/2, rows/2);
center_x = center_pos[0] - switch_spacing; 
center_y = center_pos[1] - switch_spacing;
                
module base(include_usb=true) {
    
    difference() {
        union() {
            case_shape(base_height);
        }

        union() {
            // case cavity
            translate([0, 0, base_height/3.75])
                case_cavity(base_height);

            // heatsert guides
            for (i = [0:len(screw_locs)-1]) {
                translate([screw_locs[i][0], screw_locs[i][1], base_height/2])
                    heatsert_guide(base_height/2);
            }
            
            // trrs jack
            translate([case_length - jack_hole_d - bezel_r, back_of_case + 0.01, base_height/2])
                jack_hole();

            
            // pro micro board & usb port
            /*
            translate([bezel_r*2, back_of_case + 0.01 - mcu_l, plate_thickness - mcu_h - 1])
                #pro_micro();
            */

            // usb c port
            if (include_usb) {
                translate([bezel_r*2 + 5, back_of_case + 0.01, base_height/2])
                    usb_c_board();
            }
            
            // magnet holes
            magnet_holes();
        }
    }
    
    if (needs_center_plate_screw) {
        difference() {
            // center screw post
            translate([center_x, center_y, 0])
                cylinder(r=bezel_r * case_thickness_factor, h=base_height);
            
            // center heatsert guide
            translate([center_x, center_y, base_height/2])
                heatsert_guide(base_height/2);
        }
    }
    
    // pro micro retainer thing
    /*
    translate([bezel_r*2, back_of_case - mcu_l - 1, plate_thickness - 2])
        cube([mcu_w,1,2]);
    */
}

module test_back_right() {
    intersection() {
        translate([case_length - 15,case_depth- 10,0])
            cube([25,23,20]);
        base();
    }
}

module test_back_left() {
    intersection() {
        translate([-10,case_depth- 28,0])
            cube([35,47,20]);
        base();
    }
}

//test_back_right();
//test_back_left();

//translate([5, 0, 6])
//pro_micro();
base();