# Implementation-of-RRT-in-C-

The map lies in a 50x50 matrix which consisits of '0's

blockages are represented as '4'
Nodes are represented as '1'
(1s can travel through 0 but not 4)

INPUT: 
eg:
30 20 40 40
q
45 35
17 30


r1 c1 r2 c2								//first line			
r1,c1 represents top left corner of the obstable(rectangle)     
r2,c2 represents bottom right corner of the obstable(rectangle)

hence a rectangluar obstable is created from the position x1,y1 to x2,y2
we can create as many as we want, press 'q' to quit.

Enter row and column position(row,col wise) for start node and goal node

**NOTE: When the main loop is running keep pressing any key to keep iterating, if you want to increase number of
iterations per key, just go to line:140, replace 2 with 10 or any number.
