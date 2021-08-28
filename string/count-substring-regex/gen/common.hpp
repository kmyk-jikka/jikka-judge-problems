#include <string>
#include "random.h"

template <class RandomEngine>
std::string make_random_s(int n, RandomEngine &gen) {
    std::string s;
    int state = 0;
    while ((int)s.length() < n) {
        if (gen.uniform01() < 0.01) {
            state = gen.uniform(0, 10);
        }
        if (state == 0) {
            s += "re";
            if (gen.uniform01() < 0.3) {
                state += 1;
            }
        } else if (state == 1) {
            s += "g";
            if (gen.uniform01() < 0.5) {
                state += 1;
            } else {
                state = 5;
            }
        } else if (state == 2) {
            s += "e";
            state += 1;
        } else if (state == 3) {
            s += "x";
            state += 1;
        } else if (state == 4) {
            s += "p";
            state = 0;
        } else if (state == 5) {
            s += "u";
            state += 1;
        } else if (state == 6) {
            s += "l";
            state += 1;
        } else if (state == 7) {
            s += "a";
            state += 1;
            if (gen.uniform01() < 0.2) {
                state += 1;
            }
        } else if (state == 8) {
            s += "r";
            if (gen.uniform01() < 0.5) {
                state += 1;
                if (gen.uniform01() < 0.4) {
                    state += 1;
                }
            }
        } else if (state == 9) {
            s += "e";
            state += 1;
        } else if (state == 10) {
            s += "x";
            state += 1;
        } else if (state == 11) {
            s += "p";
            state += 1;
        } else if (state == 12) {
            s += "r";
            state += 1;
        } else if (state == 13) {
            s += "s";
            if (gen.uniform01() < 0.3) {
                state += 1;
            }
        } else if (state == 14) {
            s += "i";
            state += 1;
        } else if (state == 15) {
            s += "o";
            state += 1;
        } else if (state == 16) {
            s += "n";
            state += 1;
        } else {
            s += gen.uniform('a', 'z');
            state = 0;
        }
        if (gen.uniform01() < 0.01) {
            s += gen.uniform('a', 'z');
        }
    }
    s.resize(n);
    return s;
}
