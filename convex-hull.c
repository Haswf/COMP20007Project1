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
#include "deque.h"
// Remove this after testing
#include "point.h"
// Returns the orientation of Point p2 in relation to the line segment p0p1.
// If p2 is to the left of p0p1 then it returns LEFT ('l'), if p2 is to the
// right it returns RIGHT ('r').
// If p0, p1 and p2 are collinear then COLLINEAR ('c') is returned.
#define DEBUG 0

char orientation(Point p0, Point p1, Point p2) {
    // Math: http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
    double slope_diff = (p1.y - p0.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p1.x - p0.x);
    if (slope_diff == 0) {
        return COLLINEAR;
    } else if (slope_diff > 0) {
        return RIGHT;
    } else if (slope_diff < 0) {
        return LEFT;
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
    // TODO: CHECK INPUT IS VALID
    Deque* hull_deque = new_deque();
    Point P0 = polygon[0];
    Point P1 = polygon[1];
    Point P2 = polygon[2];

    if (orientation(P0, P1, P2) == LEFT) {
        deque_push(hull_deque, P2);
        deque_push(hull_deque, P0);
        deque_push(hull_deque, P1);
        deque_push(hull_deque, P2);
    } else {
        deque_push(hull_deque, P2);
        deque_push(hull_deque, P1);
        deque_push(hull_deque, P0);
        deque_push(hull_deque, P2);
    }

    int i = 3;
    while (i<n){
        Point curr_point = polygon[i];
        if ((orientation(access_offset(hull_deque,-2), access_top(hull_deque), curr_point) == LEFT) &&
                (orientation(access_bottom(hull_deque), access_offset(hull_deque, 1), curr_point) == LEFT)
                ){
            i++;
            continue;
        }
        while (orientation(access_offset(hull_deque,-2),access_top(hull_deque), curr_point) == RIGHT){
            deque_pop(hull_deque);
        }
        deque_push(hull_deque, curr_point);
        while (orientation(access_bottom(hull_deque),
                           access_offset(hull_deque, 1),
                           curr_point) == RIGHT){
            deque_remove(hull_deque);
        }
        deque_insert(hull_deque, curr_point);
        i++;
    }

    // write hull_deque to hull
    Node* curr = hull_deque->list->head;
    int j = 0;
    while (curr->next){
        hull[j] = curr->data;
        curr = curr->next;
        j++;
    }
    return deque_size(hull_deque) - 1;
}
