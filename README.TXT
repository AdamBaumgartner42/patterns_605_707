Describe the reason for choosing the pattern you selected and for not choosing the other. 
Include the answer in a Readme.txt file along with the implementation of part 1.


An adapter pattern is the appropriate pattern to choose because it is an example of when we 
want to use an existing class and its interface does match the one we need. Here we are asked 
to use the w3c.dom structure as a wrapper around the Node and Document members of JHU\_EP dom 
structure.  

The prompt asks us why not a bridge, and the reason why we don't want a bridge pattern here 
is that the a bridge's intent is to decouple an abstraction from its implementation
so that the two can vary independently, but what we have here is two implementations that need 
converting between, and they aren't related to each other in any way, removing the motivation
for a bridge.