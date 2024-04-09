//
//  main.cpp
//  CS260
//
//  Created by Gold Weissig on 4/2/24.
//

#include <random>
#include <ctime>
#include <vector>

struct Marble {
    int rgb;
    float radius;

    // Two constructors, one with no arguments that makes a random marble, and one with arguments that makes a marble with the specified color and radius
    Marble() {
        this->rgb = createRGB(std::rand() % 256, std::rand() % 256, std::rand() % 256);
        this->radius = (std::rand() % 100) / 10.0;
    }
    Marble(int r, int g, int b, float radius) : radius(radius) {
        this->rgb = createRGB(r, g, b);
    }

    // Pretty print the marble's attributes
    void print() {
        printf("#%06X %.1fmm\n", rgb, radius);
    }

    // Shamelessly stolen from https://stackoverflow.com/a/14375308
    unsigned int createRGB(int r, int g, int b) {
        return ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
    }
};

class Bag {
    std::vector<Marble> marbles;

    public:
    Bag() {};
    void addMarble(Marble m) {
        marbles.push_back(m);
    }

    // Get a random marble from the bag, and delete it
    Marble pickRandomMarble() {
        int index = std::rand() % marbles.size();
        Marble m = marbles[index];
        marbles.erase(marbles.begin() + index);
        return m;
    }

    // Pretty print the contents of the bag
    void print() {
        printf("Contents of bag (%lu total):\n", marbles.size());
        for (int i = 0; i < marbles.size(); i++) {
            marbles[i].print();
        }
    }
};

int main(int argc, const char * argv[]) {
    // Seed the random number generator with the current time
    std::srand(std::time(nullptr));

    // Create a Bag object
    Bag bag;

    // Put 10 marbles in the bag
    for (int i = 0; i < 10; i++) {
        bag.addMarble(Marble());
    }

    // Print the contents of the bag
    bag.print();

    // Pick a random marble from the bag
    Marble m = bag.pickRandomMarble();
    printf("Picked marble: #%06X %.1fmm\n", m.rgb, m.radius);

    // Print the contents of the bag again
    bag.print();
    return 0;
}
