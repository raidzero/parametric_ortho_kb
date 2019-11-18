include <vars.scad>;
use <misc.scad>;

module plate() {
    difference() {
        case_shape(plate_thickness);
        
        // cut out grid
        for (x = [0:columns - 1]) {
            for (y = [0:rows - 1]) {
                x_pos = (x * ss) + bezel_r;
                y_pos = (y * ss) + bezel_r;
                translate([x_pos, y_pos, -0.01])
                    cube([switch_hole_size, switch_hole_size, plate_thickness * 2]);
            }
        }

        // cut out screw holes

        // front left
        translate([bezel_d, bezel_d, plate_thickness + 0.1])
            rotate(180, [1, 0, 0])
                countersunk_screw();

        // front right
        translate([case_length + bezel_r, bezel_d, plate_thickness + 0.1])
            rotate(180, [1, 0, 0])
                countersunk_screw();

        // back left
        translate([bezel_d, case_depth + bezel_r, plate_thickness + 0.1])
            rotate(180, [1, 0, 0])
                countersunk_screw();        
    
        // back right
        translate([case_length + bezel_r, case_depth + bezel_r, plate_thickness + 0.1])
            rotate(180, [1, 0, 0])
                countersunk_screw();
    }
}


module test_corner() {
    intersection() {
        plate();

        translate([-10, -10, -5])
            cube(20, 20, 20);
    }
}

plate();
