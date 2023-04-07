0x1A. C - Hash tables
------------------------------------------------------------------------------------------------------------
Learning Objectivities: What is a hash function? What makes a good hash function? What is a hash table, how do they work and how to use them? What is a collision and what are the main ways of dealing with collisions in the context of a hash table? What are the advantages and drawbacks of using hash tables? What are the most common use cases of hash tables

Requirements
-------------------------------------------------------------------------------------------------------------------
General: Allowed editors: vi, vim, emacs; All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89; All your files should end with a new line, A README.md file, at the root of the folder of the project is mandatory. Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl. You are not allowed to use global variables. No more than 5 functions per file. You are allowed to use the C standard library The prototypes of all your functions should be included in your header file called hash_tables.h Don’t forget to push your header file. All your header files should be include guarded

Data Structures: data structures used for this project:
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;

Task 0. >>> ht = {}
------------------------------------------------------------------------------------------------------------------
Write a function that creates a hash table.
Prototype: hash_table_t *hash_table_create(unsigned long int size); where size is the size of thearray. Returns a pointer to the newly created hash table, If something went wrong, your function should return NULL
Repo: GitHub repository: alx-low_level_programming, Directory: 0x1A-hash_tables File: 0-hash_table_create.c
 
Task 1. djb2
--------------------------------------------------------------------------------------------------------------------------------------
Write a hash function implementing the djb2 algorithm.
Prototype: unsigned long int hash_djb2(const unsigned char *str); Copy and paste the function from this page 
Repo: GitHub repository: alx-low_level_programming, Directory: 0x1A-hash_tables, File: 1-djb2.c

Task 2. key -> index
----------------------------------------------------------------------------------------------------------------------------
Write a function that gives you the index of a key.
Prototype: unsigned long int key_index(const unsigned char *key, unsigned long int size); where key is the key and size is the size of the array of the hash table. This function should use the hash_djb2 function that you wrote earlier Returns the index at which the key/value pair should be stored in the array of the hash table You will have to use this hash function for all the next tasks
Repo: GitHub repository: alx-low_level_programming, Directory: 0x1A-hash_tables, File: 2-key_index.c
 
Task 3. >>> ht['betty'] = 'cool'
--------------------------------------------------------------------------------------------------------------------------------------
Write a function that adds an element to the hash table.
Prototype: int hash_table_set(hash_table_t *ht, const char *key, const char *value); Where ht is the hash table you want to add or update the key/value to key is the key. key cannot be an empty string and value is the value associated with the key. value must be duplicated. value can be an empty string Returns: 1 if it succeeded, 0 otherwise, In case of collision, add the new node at the beginning of the list
Repo: GitHub repository: alx-low_level_programming, Directory: 0x1A-hash_tables, File: 3-hash_table_set.c
 
Task 4. >>> ht['betty']
-------------------------------------------------------------------------------------------------------------------
Write a function that retrieves a value associated with a key.
Prototype: char *hash_table_get(const hash_table_t *ht, const char *key); where ht is the hash table you want to look into and key is the key you are looking for Returns the value associated with the element, or NULL if key couldn’t be found
Repo: GitHub repository: alx-low_level_programming, Directory: 0x1A-hash_tables, File: 4-hash_table_get.c
 
Task 5. >>> print(ht)
-------------------------------------------------------------------------------------------------------------
Write a function that prints a hash table.
Prototype: void hash_table_print(const hash_table_t *ht); where ht is the hash table You should print the key/value in the order that they appear in the array of hash table Order: array, list
Repo: GitHub repository: alx-low_level_programming, Directory: 0x1A-hash_tables, File: 5-hash_table_print.c

Task 6. >>> del ht
------------------------------------------------------------------------------------------------------------------------------
Write a function that deletes a hash table.
Prototype: void hash_table_delete(hash_table_t *ht); where ht is the hash table; 
Repo GitHub repository: alx-low_level_programming,  Directory: 0x1A-hash_tables, File: 6-hash_table_delete.c

Task 7. $ht['Betty'] = 'Cool'
--------------------------------------------------------------------------------------------------------------------------
In PHP, hash tables are ordered. Wait… WAT? How is this even possible?
Please take a moment to think about it: how you would implement it if you were asked to during an interview or a job. What data structures would you use? How would it work? For this task, Read PHP Internals Book: HashTable, Use the same hash function. The key/value pair should be inserted in the sorted list at the right place. Note that here we do not want to do exactly like PHP: we want to create a sorted linked list, by key (sorted on ASCII value), that we can print by traversing it. 
Repo: GitHub repository: alx-low_level_programming,  Directory: 0x1A-hash_tables, File: 100-sorted_hash_table.c


