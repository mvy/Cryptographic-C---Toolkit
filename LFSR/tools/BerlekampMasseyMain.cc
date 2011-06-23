#include "BerlekampMassey.hh"
#include "LFSR.hh"
#include <string>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {

    std::string input = argv[1];

    CCTkAlgorithm::BerlekampMasseyOutput* out = CCTkAlgorithm::BerlekampMassey(input);

    std::cout << "LFSR linear complexity is " << out->getComplexity() << " / " << std::endl;
    
    std::vector<int> pol = out->getPolynome();

    int i = 0;
    bool first = true;
    for(std::vector<int>::iterator it = pol.begin(); 
            it != pol.end(); it++) {
        if(*it != 0) {

            if(!first) {
                std::cout << " + ";
            } else {
                first = false;
            }

            if(i == 0) {
                std::cout << "1";
            } else {
                std::cout << "X^" << i;
            }
        }
        i++;
    }

    std::cout << std::endl;

}
