// http://acm.timus.ru/problem.aspx?space=1&num=1353

#include <cstdlib>
#include <iostream>
#include <array>
#include <vector>

size_t sol1(int S, size_t Ndig)
{
    //std::array<int> digit_sols(n + 1);
    if (Ndig == 0) {
        return (S == 0) ? 1 : 0;
    }

    size_t vf = 0;
    for (int i=0; i < 10; ++i) {
        vf += sol1(S-i, Ndig-1);
    }
    return vf;
}

size_t sol(int S, size_t Ndig)
{
    std::vector<std::vector<int>> sols(Ndig+1);
    for (size_t i=1; i <= Ndig; ++i) {
        sols[i] = std::vector<int>(9*i+1);
        for (size_t j=0; j < 9*i+1; ++j) {
            if (i == 1) {
                sols[i][j] = 1;
            } else {
                sols[i][j] = 0;
                for (size_t k=0; k < 10; ++k) {
                    if (j-k >= 0) {
                        sols[i][j] += sols[i-1][j-k];
                        std::cout << i << "," << j << ": " << sols[i][j] << "\n";
                    }
                }
            }
        }
    }
    
    for (size_t i=1; i <= Ndig; ++i) {
        std::cout << "\n" << i << ": ";
        for (size_t j=1; j < 9*i+1; ++j) {
            std::cout << " " << sols[i][j];
        }
    }    
    return sols[Ndig][S] + ((S == 1) ? 1 : 0);
}

int main()
{
    try {
        std::cout << "Solving..." << std::endl;
        const int S = 1;
        std::cout << S << ": " << sol(S, 2) << std::endl;
        std::cout << "Done!" << std::endl;
    }
    catch(std::exception &e) {
        std::cerr << "Exception " << e.what() << std::endl;
    }
    catch(...) {
        std::cerr << "Unknown exception" << std::endl;
    }
}


size_t sol2(int S, size_t Ndig)
{
    std::vector<std::vector<int>> sols(Ndig+1);
    for (size_t i=1; i <= Ndig; ++i) {
        sols[i] = std::vector<int>(9*Ndig+1);
        for (size_t j=0; j < 9*i+1; ++j) {
            if (i == 1) {
                sols[i][j] = 1;
            } else {
                sols[i][j] = 0;
                for (size_t k=0; k < 10; ++k) {
                    if (j >= k) {
                        sols[i][j] += sols[i-1][j-k];
                        //std::cout << i << "," << j << ": " << sols[i][j] << " " << j-k << "\n";
                    }
                }
            }
        }
    }
    
    for (size_t i=1; i <= Ndig; ++i) {
        std::cout << "\n" << i << ": ";
        for (size_t j=0; j < 9*i+1; ++j) {
            std::cout << " " << sols[i][j];
        }
    }    
    std::cout << "\n";
    return sols[Ndig][S] + ((S == 1) ? 1 : 0);
}
