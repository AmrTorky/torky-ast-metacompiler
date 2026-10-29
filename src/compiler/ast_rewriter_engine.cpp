#include "torky_continuum_core.hpp"
#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::string rewrite_division_syntax(const std::string& input_code) {
    // Replace classical "A / B" with "torky::continuum::oslash_epsilon(A, B)"
    std::regex div_regex(R"(([a-zA-Z0-9_\.\(\)]+)\s*\/\s*([a-zA-Z0-9_\.\(\)]+))");
    return std::regex_replace(input_code, div_regex, "torky::continuum::oslash_epsilon($1, $2)");
}

int main() {
    std::cout << "==============================================================================\n";
    std::cout << "[TORKY AST METACOMPILER] Non-Singular Division Rewrite Engine\n";
    std::cout << "Target: Source-to-Source Syntax Transformation -> oslash_epsilon\n";
    std::cout << "==============================================================================\n";

    std::string sample_expr = "double potential = k_charge / r;";
    std::string rewritten = rewrite_division_syntax(sample_expr);

    std::cout << "Original Expression:  " << sample_expr << "\n";
    std::cout << "Rewritten Expression: " << rewritten << "\n";

    // Shadow Duel Verification: Classical division vs Rewritten oslash
    std::cout << "\n[RUNNING SHADOW DUEL: r in [-0.1 nm, 0.1 nm]]\n";
    double r_sweep[] = {-0.1, -0.05, 0.0, 0.05, 0.1};
    int stable_count = 0;

    for (double r : r_sweep) {
        double classical = (r == 0.0) ? std::numeric_limits<double>::infinity() : (1.0 / r);
        double rewritten_val = torky::continuum::oslash_epsilon(1.0, r);

        std::cout << "  r = " << std::setw(5) << r << " nm | Classical: " 
                  << std::setw(10) << (r == 0.0 ? "INF/CRASH" : std::to_string(classical)) 
                  << " | Rewritten: " << std::setw(10) << rewritten_val << "\n";

        if (!std::isnan(rewritten_val) && !std::isinf(rewritten_val)) {
            stable_count++;
        }
    }

    std::cout << "[STATUS] Non-Singular AST Stability: " << stable_count << "/5 evaluated points.\n";
    return (stable_count == 5) ? 0 : 1;
}
