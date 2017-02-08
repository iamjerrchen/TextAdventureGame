# TextAdventureGame

<i>Overview</i>

After taking cs225, I started a project that applied various aspects of C++ such as polymorphism, abstract class, virtual functions. In addition, I implemented a tree

The basic idea of the project is a set of text adventure games. Starting off, the program will ask which storyline the user wants to play. The first storyline I will be working on is called Cave Explorer. The player will need to make decision throughout the game, and as the player progresses, various items will be picked up. Both of these two aspects will affect what dialogue will be outputed by the NPC (Non-Player Character) and the type of events that will occur.

# Storylines and Details

<i>Cave Explorer</i>

(More details about the storyline will be added later)

# Implementation and API

<i>main</i>

This file outputs some text about the creation of the game and the different adventure choices available to the player.

<i>game</i>

This class is very simple. It's a abstract parent class that fosters the different storylines. This class employs polymorphism by forcing the storyline classes to implement the play() method. In the main file, there is an instruction that calls a dynamically allocated storyline using a game pointer. This implementation allows the code to be reused by anyone who wants to write a new storyline, or allows the program to adapt to whatever storyline the player picks.

<i>caveExplorer</i>

This class is one of the storyline classes. The class implements the Big Three because it extensively uses dynamically allocated memory. The storyline will be created using a tree structure because it's simpler than creating by own graph class. There will be variables that are typed boolean. These variables are the items associated with the story. The class implements the play method that will make use of backstory (outputs text), create (builds the tree), and restart (reset all the attributes to the state of the game). Instead of freeing memory and creating the tree again, restart will be implemented so that the current pointer will just move to the main entrance room. String player is added just to create a more immersive storyline.

Most of the storyline needs to be hardcoded for a consistent story. Perhaps randomize some of the items, but that's a later design choice.

<i>room</i>

This class acts like a tree node, but much more complex in detail. In addition to event, the design of the class is difficult at the current state. Room is suppose to contain logic that dictates which event will occur.

<i>event</i>

This class is currently being designed to be an abstract class. Multiple different derived events will be created and it will allow the stories to become more unique from each other. I'm thinking about creating an array of events in the room class and the number of events will be passed in as a parameter.

<i>tests directory</i>

You can ignore this directory, I do C++ testing in that directory to separate it from the actual program. If you're interested in what I was testing, feel free to look. I can't gaurantee that I commented in those tests as much as I did with the game.
