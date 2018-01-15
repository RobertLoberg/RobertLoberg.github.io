Robert Loberg 0980340
Assignment Description: Spell checker
How to Run: enter file directory and type "make" and then "./testmain"
Optional Features: None
Assumptions: None

Program works fine in testmain but when the user enteres words to be added it can only add one word and can not delete it. i believe this is an error in the insertData function but for some reason it works in the test main. Program also does not read in a file (take off marks for such). No menu options work perfectly accept for exit (3 & 4) are not implemented.



hash function and collision resolution strategy:

	My hash function takes the first and last letter of the key, multiplies them together, multiplies them with a large prime number, and then mods them by the size of the hashtable. the result is then returned to the function call. my collision strategy is Linear Probing. I check to see if the index that is given to the key and data is equal to null and if so, send the node into the address. if the index has data in it, the node checks if there is data beside/on top. this process repeats until the node is placed into the hash table. I selected this process because I felt most comfortable with it and seemed the most basic as well as being a good fit for what we are doing with this assignment.
