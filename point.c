/* * * * * * *
 * Point data structure with x and y coordinate for Assignment 1
 *
 * created for COMP20007 Design of Algorithms 2019
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

// You must not change any of the code already provided in this file, such as
// type definitions, constants or functions.
//
// You may, however, add additional functions and/or types which you may need
// while implementing your algorithms and data structures.
#include <math.h>
#include <stdio.h>

#include "point.h"


// Returns a new Point (note, this is not a pointer to a Point)
// Since it's not allocated using dynamic memory allocation it does not
// need to be freed
Point new_point(double x, double y) {
    Point point = {x, y};
    return point;
}

// Prints (on its own line) the Point in the format "x y"
void print_point(Point p) {
    printf("%.2f %.2f\n", p.x, p.y);
}

double distance(Point p1, Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

Point point_subtraction(Point p1, Point p2){
    // return p2 - p1
    p2.x -= p1.x;
    p2.y -= p1.y;
    return p2;
}

Point point_scalarmuptiplication(Point p, double scale){
    p.x *= scale;
    p.y *= scale;
    return p;
}