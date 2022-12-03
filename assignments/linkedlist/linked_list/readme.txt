Grader (I think): Zakarie Leskowsky

Riley Rice 
ONID: 934127342
12-2-2022

Description:

This program has a singley linked list class which has a bunch of methods to do operations to the data in
linked list. It has two private member variables which are the length of the list and a Node pointer called head
which points to the first node in the list. The Node class is what holds our data and has a val attribute and a
pointer attribute which points the next node in the list. This allows you to have a list of nodes which you can 
iterate through in the forward direction but not the reverse direction, which is why it's a singley linked list.
This linked class has methods which allow you to push a node to the front of the list, back of the list, or 
insert it at a certain index. Additionally there are methods to print the list, clear the list, and get the length 
or head. Along with these are a sort_ascending method, which sorts the nodes by value in ascending order using a 
recursive merge sort algorithm, and a sort_descending method, which sorts the nodes by value in descending order 
using a recursive selection sort algorithm. When you run this program it is testing the operation of the linked list
to make sure the class actually operates like it supposed to.  

Instructions:

1. I compile this using make, as it makes everything alot easier especially when there are a lot of files. 
   The main commands for compiling and running this program are:
        make - will just compile all the code
        make run -  will run the binary since it's stored in bin, must be compiled
        make crun - will clear the bin directory, compile it, and then run it
        make clean - will clear out the bin directory
        make valgrind - will clean out the bin directory and recompile then run it with valgrind
        make debug - will clean out the bin directory and recompile then run it with gdb
2. All the .cpp files will be in the src folder and all the header files will be in the include folder. The
   object files and binary will be in the bin folder.
3. When you run the program it will output different tests. Each test will have a expected ouptut which is what 
   should be outputted if the linked list works properly and the actual output which is what the linked list class
   actually outputted. 
4. Between each test there will be a prompt for you to press enter to cotinue. To continue to the next
   test press enter. 
5. There is a total of 4 tests with sub-tests in some sections. If the linked list works properly then all the tests
   should run and the actual and expected output should match up for all the tests. 

Limitations:

Some limitations of my linked list class is that it's only a singley linked list class which means that you can 
only iterate through it in one direction, which can make it intensive on your computer to access nodes at the 
end of the list, especially if the list is longer in length. Additonally, the list doesn't have the ability to 
initialize a list using the common int arr = [1 , 2, 3, etc.] notation which means you have to use the push or 
insert methods every time you want to add a node. It also doesn't have the funcitonality to copy lists to each 
other through copy constructors or an AOO. 

Extra Credit:

I did the extra credit for the sort_descending method. I used a recursive Selection Sort algorithim for the sort_descending
method which has a time complexity of O(n^2) and a space complexity of constant space.

Complexity Analysis:

1. sort_ascending (Merge Sort):
   Merge Sort: The merge sort algorithm works by taking the list and splitting it in half
   until you have a list of size one. Then you compare the list to the other list and merge them
   based on their values until you have the original list that is sorted. 
   Time Complexity: The merge sort algorithm has a time complexity of O(nlog(n))
   Space Complexity: The merge sort algorithm has a space complexity of O(n)

2. sort_descending (Selection Sort):
   Selection Sort: The selection sort algorithm works by taking the list and splitting it into 
   a sorted and unsorted section. So you start at the first element and go through the list looking
   for the min or max value and then you swap the min or max value with the starting index. You then
   move the starting index to the right 1, so your still in the unsorted section, and do the same process
   again until you have a sorted list.
   Time Complexity: The selection sort algorithm has a time complexity of O(n^2)
   Space Complexity: The selection sort algorithm has a space complexity of constant space

3. count_prime():
   count_prime: My count_prime function works by going through the list and checking if the value is a 
   prime number, and if it is, then it adds one to the count variable and otherwise continues. Then at the 
   end it returns the count variable. In order to check if the number is a prime then you must first check 
   if the nubmer is 2 or 3, which means it's prime, and then also check to see if the number is divisible by 3
   or 2 which means it isn't prime, and otherwise it is prime. 
   Time Complexity: The time complexity of my count_prime function is O(n). 
   Space Complexity: The space complexity of my count_prime function is constant space.
