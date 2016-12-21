/**********************************************************************
 *  Randomized Queues and Deques
 **********************************************************************/

Name:SHI Zhenmei
ID:20329335
Login:zshiad
Hours to complete assignment (optional):12


/**********************************************************************
 *  Explain briefly how you implemented the randomized queue and deque.
 *  Which data structure did you choose (array, linked list, etc.)
 *  and why?
 **********************************************************************/
Deque: 
      Linked listed.
      Reason:Deque is constructed by Node which has next pointer and prev pointer. 
             Pointer can link all Nodes. Pointer is convenient in this situation.
             
The iterator has a menmber ptr which point to the current Node.Then, itrator can 
move to other Node by next and prev pointer.
There is a sentinel Node in Deque. At beginning, head and rear point to it to 
avoid segmentation fault.


Randomized queue: 
      Array.
      Reason:For the list need be random. Each time construct an iterator, I need
             copy all item into a new list and give random permitation. Use linked
             list will be complex to arrange the pointer. Use array will be 
             convient to swap two item to disorder the list.

The array is changable. When it is full, a new array with double size will 
constuct and copy all item from original array and delete original array.
Similarly, when item numuber is half of the maxsize of array, a new array with 
half size will constuct and copy all item from original array and delete original 
array. To achieve random, the iterator first copy all item. Then it disorder the 
list. The itrator has a member index to record its position.
             


/**********************************************************************
 *  Briefly describe why any sequence of N randomized queue operations,
 *  starting from an empty randomized queue, takes O(N) time.
 **********************************************************************/
Enqueue and dequeue:
For convenient calculation, suppose there are (2^k) items in the array.
If it add an item when the array is full, it uses cN time copy and construct a 
new array.
Else it use c time to add a new item. c is a constant number.
Amortized time is c(2^k+2+2^2+...+2^k)/2^k~3c. 3c is a constant number.
So, it takes O(N) time, starting from an empty randomized queue.
Iterator:
It use O(N) time to consruct.
Other operation:
They do not have raltionship with N. Use O(1) time.

/**********************************************************************
 *  Briefly describe why each Deque operation takes O(1) time.
 **********************************************************************/
All operation do not use the deque.size, except size(). Therefore, these 
operation use O(1) time. size() just return a number, so use O(1) time. 


/**********************************************************************
 *  How much memory (in bytes) does your data type use to store N items.
 *  Use tilde notation to simplify your answer. Use the memory requirements
 *  for a "typical machine" given in Lecture. In your analysis, don't include
 *  the memory for the items themselves (as this memory is allocated by
 *  the client and depends on the item type.
 *  For a typical machine, refer to page 11 of 
 *  http://www.cs.princeton.edu/courses/archive/spring10/cos226/lectures/02-14Analysis-2x2.pdf 
 **********************************************************************/

RandomizedQueue:
Best case: the array is full use ~N memory.
Worst case: the array is half full use ~2N memory.
Average case: ~1.5N.

Dequeue:
Best case, Worst case, Average case: There are N nodes use ~N memory.



/**********************************************************************
 *  Known bugs / limitations.
 **********************************************************************/
NA

/**********************************************************************
 *  List whatever help (if any) that you received and from whom,
 *  including help from staff members or lab TAs.
 **********************************************************************/
Asked some questions about iterator from classmate ZHOU Sheng.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
NA



/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
It not clearly mentioned what iterator operation need to be written,
which make me a little bit confused. The whole project is really helpful, 
which make me deeply understand what iterator is.
