#include "header.h"

/**
 * @brief Entry point
 *
 * @param av char array
 * @return int Always 0
 */
int main(int ac, char **av)
{
    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", av[0]);
        return 1;
    }

    RSARef fact(av[1]);

    fact.run();

    return 0;
}

