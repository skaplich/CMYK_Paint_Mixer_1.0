// Parameters
$fn = 100; // Resolution of circles
container_height = 100; // Height of the container in mm
container_radius = 50; // Radius of the container in mm
wall_thickness = 3; // Thickness of the container walls in mm
lid_height = 10; // Height of the lid in mm
label_height = 2; // Height of the label area in mm

// Main Container
module paint_container() {
    difference() {
        // Outer cylinder
        cylinder(h = container_height, r = container_radius, center = false);
        // Inner hollow
        translate([0, 0, wall_thickness])
            cylinder(h = container_height - wall_thickness, r = container_radius - wall_thickness, center = false);
    }
}

// Lid
module lid() {
    difference() {
        // Outer lid cylinder
        cylinder(h = lid_height, r = container_radius + 2, center = false);
        // Inner hollow to fit over the container
        translate([0, 0, -1])
            cylinder(h = lid_height + 2, r = container_radius - wall_thickness, center = false);
    }
}

// Label Area
module label_area() {
    translate([0, 0, container_height/2 - label_height/2])
        cube([container_radius*2, container_radius*2, label_height], center = true);
}

// Assemble the Container with Lid and Label
module assembled_container() {
    paint_container();
    lid();
    label_area();
}

// Render the assembled container
assembled_container();

// Mounting Bracket for Pumps
module pump_mount(x, y, z, hole_diameter) {
    translate([x, y, z])
        cylinder(h = 10, r = hole_diameter/2, center = false);
}

// Example: Add four mounting holes
module pump_holes() {
    pump_mount(container_radius - 10, container_radius - 10, 0, 5);
    pump_mount(-container_radius + 10, container_radius - 10, 0, 5);
    pump_mount(container_radius - 10, -container_radius + 10, 0, 5);
    pump_mount(-container_radius + 10, -container_radius + 10, 0, 5);
}

// Update assembled container to include pump holes
module assembled_container_with_pumps() {
    paint_container();
    lid();
    label_area();
    pump_holes();
}

// Render the updated assembly
assembled_container_with_pumps();
