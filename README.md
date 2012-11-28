**Fragmentation Remover**


This program can be used to efficiently remove Memory Fragmentation from an Array.

Consider this Array:


1 | 2 | 3 | 2 | 3 | 1 


On deleting entries containing 3, vacancies will be created.

Keeping the Relative Ordering for the remaining entities same, this program fills the 
vacant positions by shifting the remaining elements accordingly (towards the Left), thus
creating a continuous free space at the end.

Only a Single traversal of this Array is required.