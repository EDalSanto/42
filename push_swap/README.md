# PushSwap

* A Stack is a data structure with LIFO (last in, first out) behavior. 
	* It an be implemented with an array or a linked list, each of which have
	  various tradeoffs in time and memory complexity, which were really not relevant
	  for this project. I choose to use an array, because I already had
	  functions in place to work better with arrays.
* In this project, we were given a sequence of numbers via command line
  arguments and had to parse the input into a stack of numbers, stack A.
* We were also given a series of operations: swap a given stack's top values,
  swap both stacks' top values, push onto stack A, push onto stack B, rotate or
  reverse rotate A and/or B.
* Given these limited number of operations, and only ONE other empty stack,
  stack B, we had to sort stack A in ascending order
* This project broke down into two programs: a checker program and a push\_swap
  program
	* Checker takes a series of numbers as arguments, creates stack A, and then reads from stdin for any of the given operations. After reading is done (CRTL-D), it states whether stack A has been sorted.
	* Push\_Swap again takes a series of numbers as arguments, creates stack A,
	  and then performs one of two homemade sorting algorithms based on stack
	  size. 
		* Small stacks use a min-num-solver algorithm, where the minimum number
		  from stack A is funneled up to the top of A and then pushed on B until
		  both A and B(in descending order) are sorted
		* Larger stacks utilize an algorithm that pushes on B whichever number
		  requires the least number of operations to keep B sorted(descending
		  order) and then pushed back onto A.
* Bonuses: the -v flag enables you to see the initial stacks, the stacks after
  each operation, and the final stacks. The -c flag adds color to the last
  changed numbers.
