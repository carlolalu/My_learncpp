In general it would be useful to take a look to UML diagrams, of all the three major types spoken of on wikipedia

## Object composition ('has-a')

We call *Object Composition* the category which includes the two subtypes *composition* and *aggregation*. Object composition models the *'has-a'* relationship between an object called *the whole* and another one called *the part*.

When to use it? 
A good rule of thumb is that each class should be built to accomplish a single task. That task should either be the storage and manipulation of some kind of data (e.g. Point2D, std::string), OR the coordination of its members (e.g. Creature). Ideally not both. Creature’s job is to worry about how to coordinate the data flow and ensure that each of the class members knows what it is supposed to do. It’s up to the individual classes to worry about how they will do it.

### composition  ('is-part-of')
It models the relationship between for example a body (the whole) and its hand (the part):
1. if the body dies the hand dies (but not necessarily viceversa)
2. the hand is part of one body per time
3. the hand is unaware of being part of the body
4. (the hand is part of the body - memeber of it -)

The key point is the composition should manage its parts without the user having to do it.

### aggregation