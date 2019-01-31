#include <iostream>

int bunnies(int num_bunny, int num_ears);

int main()
{
    int bunny = 0;
    int ears = 2;
    std::cout << "give me the number of bunnies: " << std::endl;
    std::cin >> bunny;

    std::cout << "number of bunnies: " << " " << bunny << " how many ears they have: " << bunnies(bunny, ears);
}
int bunnies(int num_bunny, int num_ears)
{
    if (num_bunny == 1) {
        return num_ears;
    } else if (num_bunny % 2 == 0) {
        return num_ears + 1 + bunnies(num_bunny - 1, num_ears);
    } else {
        return num_ears + bunnies(num_bunny - 1, num_ears);
    }

}


// We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies
// (1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) we'll say
// have 3 ears, because they each have a raised foot. Recursively return the
// number of "ears" in the bunny line 1, 2, ... n (without loops or multiplication).