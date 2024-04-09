# CS 260 Assignment 1

To model a bag of marbles:

- We need a representation of a marble; in our program that's the structure `Marble`.
    - Two simple properties marbles have are color (represented in the hexadecimal integer `rgb`) and size (represented in the float `radius`)
    - We "need" two constructors: one that takes in user values and validates things like accurate colorspace and positive radius, and one that takes in zero information and uses random values.
- We need a representation of the bag of marbles; in our program that will be a simple vector array of `Marble` objects.
    - Sucks to have to use `<vector>` but C++ arrays are not nearly as full-featured as some other languages I could mention.
    - The `Bag` class has the following methods:
        - `void addMarble(Marble)` adds a Marble to the top of the vector.
        - `Marble pickRandomMarble()` gets a random Marble from the vector, deletes it from the vector, and returns it to the caller.
        - `print()` prints the contents of the bag, along with the number of Marbles inside.
- The `main` function does the following tests:
    - Seeds the RNG engine
    - Creates a new Bag
    - Adds 10 Marbles to the Bag
    - Prints the contents of the bag, showing off the random colors and radii
    - Picks a random Marble out of the bag
    - Prints the contents of the bag again, proving that the picked Marble is not there
    