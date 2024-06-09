# CS 260 Assignment 7

## Hashtables

Hashtables map keys to values for simpler lookup than other kinds of structures that require searching. The keys in these key-value pairs are run through a hashing function which determines the index where the value will be stored. 

### Naïve Attempt (`HashTable`)

#### Hashing

For ease of testing, hashing the key values will be done by counting the length of the string mod the number of buckets we have. This lets me easily confirm if I know two values will (or will not) collide. I would use a more mature method of hashing if this were going into production.

#### Testing

- An empty (newly-created) `HashTable` object should correctly print it has nothing stored.
- The `insertItem` function should correctly add the `value` argument to the `HashTable`'s `storage` based on the hashed value of the `key` argument. For example, the key/value pair ("foo"/"barbaz") will put "barbaz" in the *third bucket* (zero-indexed).
- The `removeItem` function will hash the `key` argument, grab the value from the bucket indicated, set the value in the bucket to an empty string (effectively erasing it), then returns the grabbed value. For already-empty buckets, this will return an empty string; otherwise, it will return the value stored in that bucket.
- The `getItem` function works similarly to `removeItem`, but doesn't overwrite the bucket value.

#### Collisions

Collisions in the `HashTable` class just overwrite what was in the bucket. This is a bare-bones, completely naïve attempt at a hashtable. But good news! This means that the `insertItem` function is `O(1)`.

### `ChainedHashTable`

We have to store both the key **and** the value in order to get better collision behavior than `HashTable`'s overwriting. We use C++ builtin `std::pair` to make a tuple of the two strings to treat them as a single object. A dictionary or map would work well here as well (especially if using another language like Swift or Java with those built-in) but I'm unsure if C++ has those natively.

Hashing and testing are the same, although collision is now detected and values are moved to the next un-occupied index in `storage`.

#### Collisions

Collisions are detected by the use of our new `std::pair` tuple that holds the original key, as well as a separate `isOccupied` boolean array. We check if the key in storage is equal to the key given to the `insert` function, and whether we've marked the index as occupied; if the location is occupied and the keys are not equal, we move to the next index and check again, looping over the end of the array to the beginning if necessary, until the key is found or we find an unoccupied index.

This has a complexity of O(n), since at worst we could loop over the entire table to find an unoccupied index, which is strictly worse than the "collision detection" present in `HashTable`, and we have to use more memory for storage with the pairs and additional array, but we aren't at risk of losing data this way.