# CPPVectorAndList
Compare performance between std::vector and std::list

## compared sorted insert
1. Original std:: list did not support random access
2. Assume using std:: vector to build a linked list library
3. Because of the large amount of elements, and each element should be a pointer, insert into vector  
   will be more efficient; the continuous move cost will lower than cache missed traversal.
4. When will using the original doubly linked list (std::list)?
   If the linked list library was used in small amount of an element or element was non trivial and 
   passed by value; the time worst complexity of insert will be O(n/2) 
5. Build sorted_list(base on arraylist) , sorted_list_(base on doubly linked list) and make a
   small test to show performance
