/* * * * * * *
 * Implementation of the Inside Hull algorithm for Assignment 1
 *
 * created for COMP20007 Design of Algorithms 2019
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

//                   WRITE YOUR IMPLEMENTATION HERE
//
// You should fill in the function definitions for orientation() and
// inside_hull() in this file.
//
// Don't be shy to add any extra functions or types you may need.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "convex-hull.h"
// Remove this after testing
#include "point.h"
// Returns the orientation of Point p2 in relation to the line segment p0p1.
// If p2 is to the left of p0p1 then it returns LEFT ('l'), if p2 is to the
// right it returns RIGHT ('r').
// If p0, p1 and p2 are collinear then COLLINEAR ('c') is returned.
#define DEBUG 0

char orientation(Point p0, Point p1, Point p2) {
    // Math: http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
    double slope_diff = (p1.y - p0.y)*(p2.x - p1.x) - (p2.y - p1.y)*(p1.x - p0.x);
    if (slope_diff == 0){
        return COLLINEAR;
    }
    else if (slope_diff > 0){
        return RIGHT;
    }
    else if (slope_diff > 0){
        return LEFT;
}


// Takes a polygon (i.e. an array of points) given in counter-clockwise order
// with n points.
//
// Stores the points of the convex hull into the hull array (the last point
// should NOT be the same as the first point), and returns the number of
// points which are in the convex hull.
//
// If three successive points in the polygon are collinear then the algorithm
// should terminate and COLLINEAR_POINTS should be returned.
//
// If an error occurs this function should return INSIDE_HULL_ERROR.
int inside_hull(Point *polygon, int n, Point *hull) {
  // TODO: Implement the InsideHull algorithm
  fprintf(stderr, "Error: inside_hull() not implemented\n");
  exit(EXIT_FAILURE);
}
//
//int main(){
//    // case 1a, expecting l
//    printf("%c\n", orientation(new_point(0.0, 0.0),new_point(2.0, 2.0),new_point(1.0, 3.0)));
//    // case 1b, expecting r
//    printf("%c\n", orientation(new_point(0.0, 0.0),new_point(2.0, 2.0),new_point(3.0, 1.0)));
//    // case 2a, expecting l
//    printf("%c\n", orientation(new_point(3.0, 0.0),new_point(1.0, 2.0),new_point(1.0, 1.0)));
//    // case 2b , expecting r
//    printf("%c\n", orientation(new_point(3.0, 0.0),new_point(0.0, 3.0),new_point(3.0, 1.0)));
//    // case 3a, expecting l
//    printf("%c\n", orientation(new_point(0.0, 0.0),new_point(3.0, 0.0),new_point(1.5, 1.5)));
//    // case 3a, expecting r
//    printf("%c\n", orientation(new_point(0.0, 0.0),new_point(3.0, 0.0),new_point(1.5, -1.5)));
//    // case 4a, expecting l
//    printf("%c\n", orientation(new_point(0.0, 0.0),new_point(0.0, 3.0),new_point(-1.5, 1.5)));
//    // case 4b, expecting 4
//   printf("%c\n", orientation(new_point(0.0, 0.0),new_point(0.0, 3.0),new_point(1.5, 1.5)));
//    printf("%c\n", orientation(new_point(0.0, 0.0),new_point(2.0, 2.0),new_point(1.0, 1.0)));
//}
