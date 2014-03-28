INFO3220 Assignment 1
=====================

## Extensions
* Ability to change colour of the ball and background from the configuration file.
* Ability to pause and restart the program.

## Configuration Format
* The `config.txt` file is used to set parameters within the program, the available parameters are as follows:
	* **Radius** `int` - The radius of the ball
	* **InitialX** `int` - The initial X position of the ball.
	* **InitialY** `int` - The initial Y position of the ball.
	* **xVelocity** `double` - How quickly the ball moves across the X plane.
	* **yVelocity** `double` - How quickly the ball moves across the Y plane.
	* **BackgroundColor** `string` - The background colour of the dialog.
	* **BallColor** `string` - The colour of the ball.
	* **WindowHeight** `int` - The height of the window.
	* **WindowWidth** `int` - The width of the window.


* If any of these fields are missing, they are set to a default value, as specified in the constructor.


## Marking Criteria

#### Pass (50% or more)
* Sensible/Appropriate OO Design;
* it must use objects;
* it must compile and run;
* it must read the configuration file;
* the ball must bounce off the sides

#### Credit (65% or more)
* appropriate use of a *creational* design pattern
* clear code structure, that will be simple to maintain and extend
* sensible error checking, e.g. for missing or incorrect files
* informative, clear commenting of code

#### Distinction (75% or more)
* memory is handled efficiently
* correct bouncing from the surface, not the midpoint of the ball

#### High Distinction (85% or more)
* extensions to the functionality that are simple and effective, e.g.:
	* sound effects,
	* ability to change colours and position of the ball or table within the program,
	* pause and resume play,
	* ability to dynamically change the framerate or box properties
	
