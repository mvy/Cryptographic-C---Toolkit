#include "BerlekampMassey.hh"
#include <vector>

namespace CCTkAlgorithm {

int BerlekampMassey(std::string finiteInputSequence) {
        const int N = finiteInputSequence.length();

        std::vector<int> bstore;
        std::vector<int> cstore;
        std::vector<int> tstore;

        bstore.push_back(1);
        cstore.push_back(1);
        for(int i = 1; i < N; i++) {
            bstore.push_back(0); 
        }

        cstore = bstore;

        int l = 0;
        int m = -1;

        for(int k = 0; k < N; k++) {
            int d = 0;
            for (int i = 0; i <= l; i++) {
                d ^= cstore[i] * finiteInputSequence[N - i];
            }

            if (d == 1) {
                tstore = cstore;
                int N_M = N - m;
                for (int j = 0; j < N - N_M; j++) {
                    cstore[N_M + j] ^= bstore[j];
                }
                if (l <= N / 2) {
                    l = N + 1 - l;
                    m = N;
                    bstore = tstore;
                }
            }

        }

        return l;
    }
}
