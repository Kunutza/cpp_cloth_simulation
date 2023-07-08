### (All the UPPERCASE will be consts that will be read from a values.txt that will be located next main.cpp)
## The cloth will only have 
NUMBER OF VERTICAL & HORIZONTAL PARTICLES 

## Create a cloth particle/point class that will contain
* Individual values like
  * Vector2f for velocity
  * Vector2f for position
  * Vector2f for tension
  * a list of the other particles connected to it(0-4 connected particles)
* Ordinary values like
  * GRAVITY
  * WEIGHT
  * FRICTION(SO THAT THE MOMENTUM STOPS)
  * THREAD_WIDTH(MAYBE ADD AT THE END)
  * BREAKING_STRENGTH

  * THE ROPE WILL ALWAYS SNAP AT THE TOP PARTICLE(I THINK BECAUSE THE CLOTH WILL UPDATE FROM THE BOTTOM DOWN)

FOR START CREATE ONLY 2 PARTICLES AND SEE HOW THEY INTERACT WITH EACH OTHER
