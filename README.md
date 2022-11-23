# Word-Composition-Problem

Problem Statement:

1. Reads provided files (Input_01.txt and Input_02.txt) containing alphabetically sorted words list (one
word per line, no spaces, all lower case)
2. Identifies & display below given data in logs/console/output file
   o longest compounded word
   o second longest compounded word
   o time taken to process the input file
   
Solution :

a) We will be using the Trie Data Structure for solving the above problem
b) Then we will be creating a map of size 26.
c) Then by using the create function in Tries using the heap and then we will be conerting words into the numbers.
d) Then by using longestCompoundWord function we will be checking if the new word is present or not. If the prefix is found then we will be checking the rest of the part    wheather it is present or not in the Trie.
e) We will be checking for the largest Compounded Word and the second one also and after that we will get the required result with its time duration.


