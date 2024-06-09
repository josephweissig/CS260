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

### 