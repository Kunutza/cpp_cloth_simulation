## The cloth will only have 
number of vertical & horizontal particles 

## Create a cloth particle class that will contain
* Individual values like
  * Vector2f for velocity
  * Vector2f for position
  * Vector2f for tension
  * a list of the other particles connected to it(0-4 connected particles)
* Ordinary values like
  * weight
  * friction(so that the momentum stops)
  * thread_width(maybe add at the end)
  * breaking_strength

  * THE ROPE WILL ALWAYS SNAP AT THE TOP PARTICLE(I THINK BECAUSE THE CLOTH WILL UPDATE FROM THE BOTTOM DOWN)

FOR START CREATE ONLY 2 PARTICLES AND SEE HOW THEY INTERACT WITH EACH OTHER
