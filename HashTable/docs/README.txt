Robert Loberg 0980340
Assignment Description: Spell checker
How to Run: enter file directory and type "make" and then "./testmain" to run program.
Optional Features: None
Assumptions: None


hash function and collision resolution strategy:

	My hash function takes the first and last letter of the key, multiplies them together, multiplies them with a large prime number, and then mods them by the size of the hashtable. the result is then returned to the function call. my collision strategy is Linear Probing. I check to see if the index that is given to the key and data is equal to null and if so, send the node into the address. if the index has data in it, the node checks if there is data beside/on top. this process repeats until the node is placed into the hash table. I selected this process because I felt most comfortable with it and seemed the most basic as well as being a good fit for what we are doing with this assignment.
