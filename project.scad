include <vars.scad>;
use <plate.scad>;
use <base.scad>;
use <helper.scad>;

module board(include_usb=true) {
    base(include_usb);

    if (hotswap) {
        translate([0, 0, base_height*2])
            helper_plate();
    }

    translate([0, 0, base_height*4])
        mirror([0,0,1])
        plate();
}

if (split) {
    dist = 20;
    angle = 0;

    translate([-case_length - dist, 0, 0])
        rotate(angle, [0, 0, 1])
            board();

    translate([case_length + dist, 0, 0])
        rotate(-angle, [0, 0, 1])
            mirror([1, 0, 0])
            board(false); // no usb port on this one
} else {
    translate([-case_length/2, 0, 0])
        board();
}