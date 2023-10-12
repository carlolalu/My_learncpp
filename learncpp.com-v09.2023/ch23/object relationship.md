In general it would be useful to take a look to UML diagrams, of all the three major types spoken of on wikipedia. The models of this chapter are generally not feature of cpp, but rather SEMANTICAL models to exploit to design efficiently oop-programs.

## Object composition

We call *Object Composition* the category which includes the two subtypes *composition* and *aggregation*. Object composition models the *'has-a'* relationship between an object called *the whole* and another one called *the part*.

When to use it? 
A good rule of thumb is that each class should be built to accomplish **a single task**. That task should either be the storage and manipulation of some kind of data (e.g. Point2D, std::string), OR the coordination of its members (e.g. Creature). Ideally not both. Creature’s job is to worry about how to coordinate the data flow and ensure that each of the class members knows what it is supposed to do. It’s up to the individual classes to worry about how they will do it.

How to pick the right relationship? Make alot of simplification and model the most simple relationship which meets your need., not the one best fit to create a real model (utility > reality as a quality for a model). Example: a car might have an engine as aggregation if we are simulating a car shop, but this relationship could be implemented as composition if we try to build just a race simulator.

A class might have **both relationship** for different parts. Example: a house might have a door (composition) and an address (aggregation)

Composition should be possibly favoured over aggregation: less prone to have memory leaks, because the memory will be more orderly managed. 

### composition ('is-part-of')
It models the relationship between for example a body (the whole) which has-a hand (the part):
1. the body (whole) has-a hand (part) (i.e. has-a relationship)
2. the hand is unaware of being part of the body (i.e. unidirectional relationship)
3. the hand is part of one body per time
4. if the body dies the hand dies (but not necessarily viceversa)

In composition implementation:
- the hand/part is usually a class-member of the body/whole, which is the class itself. Sometimes is managed by some pointer, if we need memory allocation, but still with the idea of the class possessing those object.
- the key point is: the composition should manage its parts (creation adn destruction) without the user having to do it.


### aggregation ('has-a')
(different meaning with respect to 'aggregates', which means basically 'struct')

it models the relation between for example a house (the whole) which has-a address (the part)
1. the house (whole/class) has-a address (part/member) (i.e. has-a relationship)
2. the address (part) is unaware of the house (whole) (i.e. unidirectional relationship)
3. the address (part) can belong eventually to more than one house (whole) at time 
4. the address (part) does not have its existence managed by the house (whole)

(Notice: point 1 and 2 are in common between composition and aggregation)

Note: when an aggregation is created is not responsible to create its parts. When an aggregation is destroyed is not responsible to eliminate the parts

Implementation:
almost identical to compositon, ('the difference is usually semantic'), but the parts are **pointers and references** to **object preexisting** outside of the aggregation class itself. Thus the parts of the aggregation are usually either taken as constructor parameters or the aggregation is created 'empty' and the parts are added later through some access function or operator. At the destruction the pointer or reference will be destroyed without destroying the object being pointed to

Last note: aggregation does not have so fixed standard in its definition as much as composition, you might find different definitions online.

### philosophycal digression
In the real world composition relationship does not exist: nothing ceases to exist because something else dies. Even if we day, our hand dies becuase of the lack of services offered by the body itself (blood circulation, ie oxygenation), not literally because the body is dead. Composition is thus just an approximation of reality to cut shorts on overcomplex cause-and-effect nexuses, which have deterministic and obvious outcomes.



## Association ('uses-a')

weaker than object composition, still unsymmetrical

Example: doctor (object) "uses-a" (to earn income) patient (associated object). 
The doctor can see more patients, the patient can see more doctors. They exist indepentently from each other, and may or may not know about their existence.


1. The associated object is otherwise unrelated to the object
2. The associated object can belong to more than one object at a time
3. The associated object does NOT have its existence managed by the object
4. The associated object may or may not know about the existence of the object (bidirectional relationship allowed)

Note: points 2 and 3 are in common with the aggregation

Implementation: usually using pointers or references. The object points at the associated object. But there are times in which we implement this differently (only semantically): the object has a memeber which is an int variable which, called by a certain function, uniquely retrieves the associated object. This means there is no cpp-entity linking directly the two, only a kind of interface.

The association is called reflexive when it links objects of the same type. (example: a university course and its prerequisites, which are university courses)


## Dependency ('depends-on')

the weakest and simplest relationship of these 4.

an object 'depends-on' another object to do smt. Key example: classes depend std::ostream to print on the screen, but std::ostream does not depend on those classes.

Real life examples: Flowers depend on bees to impollinate them, but not viceversa. You depend on your shoes to walk outside an not viceversa. It is always unidirectional.

1. An object depends on the other to do smt (so not just uses it, but DEPENDS on it) (dependency)
2. The viceversa does not happen (unidirectional)
3. the two are otherwise unrelated

Differences with association: 

In **association** the doctor knows its patients, the doctor class has an array of references or pointers to the patients. The associated object is referenced through some direct or indirect link as a variable-member of the class. In **dependency** it is different, because there is usually no link, but the object being dependent on is instantiated when needed (eg opening a file to write data to) or passed into a function (std::ostream for the '<<' operator). We could thus say that association is LONG-TERM/'LINKED' while dependency is SHORT-TERM/'UNLINKED'.


