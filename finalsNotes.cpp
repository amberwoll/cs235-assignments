// same questions/ mostly the same questions as the pdf one
print(T)
base case checks if t is nullptr
print(t-> left)
print(t-> right)
cout t-> vlaue endl

// in order- print everything to the left, print self, and then print right
// self is top node
// pre order prints self before, then left, then right
// post order prints left, right, self
// all 3 are depth first searched (any recuresive tree traversal is depth first like stacks)
// queues are breadth first searches
// breath first hits level by level, but depth first goes all the way down one side and works its way back up
// big O n is the worst case, big Oh 1 is ideal, enough bins for big Oh 1
// 