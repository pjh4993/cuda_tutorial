#include <iostream>

#include "cuda_tutorial_config.h"

#ifdef USE_CH4
#   include "chapter_4/vector_sum.hpp"
#endif

int main(int argc, char **argv) {
    if (argc < 2){
        std::cout << argv[0] << " Version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
    }
    #ifdef USE_CH4
    vector_sum();
    #endif
}
