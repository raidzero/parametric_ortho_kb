include <vars.scad>;
use <misc.scad>;


module plate() {

    difference() {
        case_shape(plate_thickness);
        
        // cut out grid
        for (x = [0:switchColumns - 1]) {
            for (y = [0:rows - 1]) {
                pos = switch_location(x, y);
                translate([pos[0], pos[1], -0.1])
                    cube([switch_hole_size, switch_hole_size, plate_thickness * 2]);
            }
        }

        // cut out screw holes
        screw_holes();

        // center - if needed
        if (needs_center_plate_screw) {
            center_pos = switch_location(switchColumns/2, rows/2);
            center_x = center_pos[0] - switch_spacing; center_y = center_pos[1] - switch_spacing;

            translate([center_x, center_y, plate_thickness + 0.1])
                rotate(180, [1, 0, 0])
                    countersunk_screw();
        }
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
