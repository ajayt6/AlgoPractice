/*
http://www.cnblogs.com/grandyang/p/5735205.html

Designa  phine directory
My logic:
1)use two unordered_set
2)populate available_set with range of numbers
3)when get() is used, available_set.erase(value)

On further thinking, this wont work out, since set does not support any operation like top() or dequeue
*/