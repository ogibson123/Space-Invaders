# Space-Invaders
Remake of the classic arcade game Space Invaders, developed with C++ and the Qt library

![demonstration gif1](https://github.com/ogibson123/Space-Invaders/blob/master/demo%20gifs/demo1.gif)
![demonstration gif2](https://github.com/ogibson123/Space-Invaders/blob/master/demo%20gifs/demo2.gif)

# Game Details
- Use the spacebar to shoot, and left and right arrows to move
- Killing all aliens will give you an extra life, and then the next wave will spawn
- Red UFO's will spawn randomly throughout the game
- An alien is worth 100 pts, a UFO is worth 500 pts
- If two bullets collide, both are cancelled out
- If all lives are lost, you are given the option to retry or quit the game

# Build Requirements
- Project built using the Qt Creator IDE. Qt 5.9.7+ required, only tested on Ubuntu 18.04 so far
- Click New Project -> New Qt Widgets Application
- Run qmake and run the project to play
