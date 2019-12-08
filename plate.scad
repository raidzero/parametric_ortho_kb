include <vars.scad>;
use <misc.scad>;

module plate() {
    switchColumns = (split) ? columns / 2 : columns;

    difference() {
        case_shape(plate_thickness + plate_spacer_thickness);
        
        // cut out grid
        for (x = [0:switchColumns - 1]) {
            for (y = [0:rows - 1]) {
                pos = switch_location(x, y);
                translate([pos[0], pos[1], -0.1])
                    cube([switch_hole_size - 0.1, switch_hole_size - 0.1, plate_thickness * 2]);
                
                // cut out the space to give the switch room to grab the top part
                translate([pos[0] - 1, pos[1] - 1, plate_thickness])
                    cube([switch_hole_size + 2, switch_hole_size + 2, plate_thickness * 3]);
            }
        }

        // cut out screw holes
        screw_holes();

        // center - if needed
        if (needs_center_plate_screw) {
            center_pos = switch_location(switchColumns/2, rows/2);
            center_x = center_pos[0] - switch_spacing; center_y = center_pos[1] - switch_spacing;

            translate([center_x, center_y, -0.01])
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
