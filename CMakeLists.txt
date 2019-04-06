cmake_minimum_required(VERSION 3.10)
project(COMP20007Project1 C)

set(CMAKE_C_STANDARD 99)

add_executable(COMP20007Project1 dlist.c dlist.h deque.c deque.h point.c point.h point.h main.c convex-hull.h convex-hull.c)

target_link_libraries(COMP20007Project1 m)