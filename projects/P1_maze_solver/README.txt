Blake Conrad ~ README.txt

DFS:

The while loop asks if we are at the last cell in the maze (m-1,n-1) and if we are NOT then we proceed. First by using a currentCell object I can trace my way around the maze. Next, I have to test my boundaries to see if I am actually allowed to move there, because I was getting uncountable amounts of segmentation faults and errors due to my error of not respecting boundaries, therefore, the boundary “isAllowed..." simply tells me if I am able to advance to the next cell I am desiring to go to. Thus, hopping into the algorithm, check my currentCells east wall to see if its open, and if my neighbor has not been visited, AND finally assuming it is allowed to go east, if the first two are true and the last is true, progress in marking the cell visited and adding that new cell to my scroll. I wrote up a general case for all existing possibilities (north, south, west, and east) so placing them on the map would be easier. Repeat this process for every case that this is good, and for the case that my criteria is not met, I assume I must be in a wall, so pop() out and check again for new options east,south,west,north is the order of preference I chose. I push on the cell to a stack every time I progress through the maze.

Psuedo-algorithm:

if the cell at the top of my stack is not the last cell in the maze, then I want to check, in order, east, then south, then west, then north, and if any of these directions are true, one taking precedence over the others, push() that cell onto my stack. This will increment an index holding my stack which will come in handy later for using my linked list to output to a file. Repeat this process of checking and pushing until I don’t meet the conditions of: 1) walls are open, 2)next cell has not been visited, and 3)bounds are good. Again, assuming none of those are correct I will go to my else statement which says, now I have hit a wall, so I must pop. Proceed in this process until I have completely finished the maze. After completion, set pathLength to my stacks actual length after all of this traveling. for pathLength amount of times, I want to append the cell of that location to my linked list.

Compile on Linux:

I used a makefile, so this is the exact commands I used to compile the code

1) cd Desktop/
2) cd mazeCode/
3) make
4) ./MazeProject

Other notes:

I found several extremely helpful posts on stack overflow along the way which I derived multiple conclusions from because there was simply no good way of doing the matter at hand without weird tricks.  Some of these were found in the file input, my file output, and especially for cutting through a string with spaces. Please do not be alarmed at these scenarios, I did my absolute best to comment everything as cleanly and as clearly as possible, and I understand exactly what is happening if ANY further explanation is needed.