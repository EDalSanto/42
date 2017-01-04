## My implementation of the C standard library's printf
####General approach: 
* Initialize large struct(refactor into smaller data structures in future) of to keep track of different flags and arguments
* Loop through each char of fmt string. If I don't find a %, I simply print the
  char. Otherwise, I pass the location after the % to handlearg which leads it
  to a parser. The parser then obtains any relevant data about the format
  conversion and saves it in the "pf detective struct"
* Once I have the arg information, I obtain the argument, its length(used to
  calculate proper field width and precision), spacing and zeros to print, and
  justification(left or right)
* Each arg is handled according to its specifications
* The function returns the total numbers of chars printed

####To-do
* Break up data structure into smaller parts
* Make it pass all 30000 tests in "testftprintf file"..missing a few edge cases
* Optimize for speed where possible
