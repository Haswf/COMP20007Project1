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
char orientation(Point p0, Point p1, Point p2) {
  // TODO: Implement orientation()
  Point p0p1 = point_subtraction(p0, p1);
  Point p0p2 = point_subtraction(p0, p2);
  double dot_product = p0p1.x * p2.x + p0p1.y * p2.y;
  double length = distance(p0, p1);
  Point unit_vector = new_point(p0p1.x / length, p0p1.y/length);
  Point Horizontal = new_point(unit_vector.x * dot_product, unit_vector.y* dot_product);
  Point Vertical = point_subtraction(Horizontal, p0p2);
  print_point(Horizontal);
  print_point(Vertical);
  if ((Vertical.x < 0 && Vertical.y > 0) || (Vertical.x>0 && Vertical.y<0)){
      return LEFT;
  }
  else if((Vertical.x < 0 && Vertical.y < 0)){
      return RIGHT;
  }
  else{
      return COLLINEAR;
  }

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

int main(){
    Point p0 = new_point(0.0, 0.0);
    Point p1 = new_point(2.0, 2.0);
    Point p2 = new_point(1.0, 1.0);
    printf("%c", orientation(p0,p1,p2));
}
