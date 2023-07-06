# include "Huffman.h"
# include <iostream>
int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "-c") == 0)
        compress(argv[3]);
    if (strcmp(argv[1], "-u") == 0)
        decompress(argv[3],argv[5]);
    
    return 0;
}