include <vars.scad>;
use <misc.scad>

module base() {
    difference() {
        union() {
            case_shape(base_height);
        }

        union() {
            // case cavity
            translate([0, 0, base_height/3.75])
                case_cavity(base_height);

            // front left heatsert hole
            translate([bezel_d, bezel_d, base_height/2])
                heatsert_guide(base_height/2);

            // front right heatsert hole
            translate([case_length + bezel_r, bezel_d, base_height/2])
                heatsert_guide(base_height/2);

            // back left heatsert hole
            translate([bezel_d, case_depth + bezel_r, base_height/2])
                heatsert_guide(base_height/2);

            // back right heatsert hole
            translate([case_length + bezel_r, case_depth + bezel_r, base_height/2])
                heatsert_guide(base_height/2);

            // trrs jack mounting hole
            translate([case_length - bezel_r, case_depth + bezel_r*2 + 0.01, base_height/1.75])
                rotate(90, [1, 0, 0])
                    #cylinder(d=jack_hole_d, h=case_depth/2);
            
            // trrs jack barrel hole
            translate([case_length - bezel_r, case_depth + bezel_r*2 - 1.75, base_height/1.75])
                rotate(90, [1, 0, 0])
                    #cylinder(d=jack_barrel_d, h=case_depth/2);

            // pro micro board & usb port
            translate([bezel_r, case_depth + bezel_r*2 + 0.01 - mcu_l, plate_thickness - mcu_h - 1])
                pro_micro();
        }
    }
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
test_back_left();

//translate([5, 0, 6])
//pro_micro();
//base();