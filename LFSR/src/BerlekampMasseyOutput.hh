#ifndef __BERLEKAMPMASSEYOUTPUT_HH__
#define __BERLEKAMPMASSEYOUTPUT_HH__

#include <vector>
namespace CCTkAlgorithm {
    class BerlekampMasseyOutput {
        private:
            int complexity;
            std::vector<int> polynome;

        public:
            BerlekampMasseyOutput(int,const std::vector<int>&);
            BerlekampMasseyOutput(const BerlekampMasseyOutput &);

            int getComplexity();
            std::vector<int> getPolynome();
    };
}
#endif
