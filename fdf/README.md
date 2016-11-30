#FDF

###3D Graphics Project using [MinilibX library](https://github.com/abouvier/minilibx)

####Overview
1. Parse file of X, Y, Z coordinates into 2D-array of point structs and store in
   map structure
2. Print initial grid without rotations
3. Infinite "key hook loop" handles expose events, or input from keyboard
  * Q: rotate up around X axis 
  * A: rotate down around X axis 
  * W: rotate left around Y axis
  * S: roate right around Y axis
  * E: rotate left around Z axis
  * D: rotate right around Z axis
  * Z: zoom 10%
  * X: unzoom 10%
  * R: reset to initial state

####Ideas for improvements
* Make Centering and Scaling more precise
* Add Coloring for Altitude 
