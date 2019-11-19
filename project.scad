include <vars.scad>;
use <plate.scad>;
use <base.scad>;

module board() {
    base();
    translate([0, 0, base_height*2])
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
            board();
} else {
    translate([-case_length/2, 0, 0])
        board();
}