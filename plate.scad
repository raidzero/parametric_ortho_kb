include <vars.scad>;
use <misc.scad>;

// return the location for a switch hole given a column and row grid number
function switch_location(column, row) = [ 
    bezel_r + (column * ss), 
    bezel_r + (row * ss) ];

module plate() {
    switchColumns = (split) ? columns / 2 : columns;

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
