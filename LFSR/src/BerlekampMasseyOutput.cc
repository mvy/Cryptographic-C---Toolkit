#include "BerlekampMasseyOutput.hh"

namespace CCTkAlgorithm {
    BerlekampMasseyOutput::BerlekampMasseyOutput(int cpx, const std::vector<int>& poly) {
        complexity = cpx;
        polynome = poly;
    }

    BerlekampMasseyOutput::BerlekampMasseyOutput(const BerlekampMasseyOutput& out) {
        complexity = out.complexity;
        polynome = out.polynome;
    }


    int BerlekampMasseyOutput::getComplexity() {
        return complexity;
    }

    std::vector<int> BerlekampMasseyOutput::getPolynome() {
        return polynome;
    }
}
