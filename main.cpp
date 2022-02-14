#include <iostream>
#include <stack>

bool is_opening(char par) {
    return par == '(' || par == '[' || par == '{';
}

bool is_closing(char par) {
    return par == ')' || par == ']' || par == '}';
}

bool is_par(char par) {
    return is_opening(par) || is_closing(par);
}

bool is_pair(char par1, char par2) {
    return (par1 == '(' && par2 == ')') ||
           (par1 == '[' && par2 == ']') ||
           (par1 == '{' && par2 == '}');
}

int main() {
    char par;
    std::stack<char> pars;
    bool correct = true;
    while (std::cin.get(par) && is_par(par) && correct) {
        if (is_opening(par)) {
            pars.push(par);
        } else if (pars.empty() || !is_pair(pars.top(), par)) {
            correct = false;
        } else {
            pars.pop();
        }
    }
    if (!correct || !pars.empty()) {
        std::cout << "false" << std::endl;
    } else {
        std::cout << "true" << std::endl;
    }
    return 0;
}
