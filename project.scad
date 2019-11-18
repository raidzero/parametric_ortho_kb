include <vars.scad>;
use <plate.scad>;
use <base.scad>;

module half() {
    base();
    translate([0, 0, base_height*2])
    plate();
}

dist = 20;
angle = 7;

translate([-case_length - dist, 0, 0])
    rotate(angle, [0, 0, 1])
        half();

translate([case_length + dist, 0, 0])
    rotate(-angle, [0, 0, 1])
        mirror([1, 0, 0])
            half();