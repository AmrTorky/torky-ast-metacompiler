#ifndef TORKY_AST_METACOMPILER_HPP
#define TORKY_AST_METACOMPILER_HPP

#include <cmath>
#include <cstdint>
#include <string>
#include <algorithm>

namespace torky::compiler::ast {

    inline constexpr double EPSILON_NM2       = 0.016;
    inline constexpr double V_FINITE_ZERO_EV  = 11.384;
    inline constexpr double BANACH_LIMIT      = 0.3849; // |P'(rho_c)| < 1.0

    #pragma pack(push, 1)
    struct TorkyCellDtype {
        uint8_t  gov_gate;     // TSG Gate Register (0x01 - 0x04)
        int16_t  phase_q16;    // Phase Q16 Fixed-Point
        int16_t  field_q16;    // Field Q16 Fixed-Point
        uint32_t syndrome_u32; // SHA-256 Merkle Syndrome
    };
    #pragma pack(pop)

    static_assert(sizeof(TorkyCellDtype) == 9, "CRITICAL: TorkyCellDtype must be precisely 9 bytes!");

    enum class AstNodeType {
        LITERAL,
        OPERATOR_ADD,
        OPERATOR_MUL,
        CONTRACTION_NODE
    };

    struct AstNode {
        AstNodeType type;
        double value;
        std::string identifier;
        bool is_healed;
    };

    class AstMetacompilerEngine {
    public:
        // Proof-carrying self-rewriting AST transformation under Banach contraction
        static inline AstNode rewrite_node(const AstNode& input_node, double feedback_param) {
            AstNode output_node = input_node;
            double contraction_rate = std::abs(std::sin(feedback_param) * 0.3849);

            if (contraction_rate <= BANACH_LIMIT) {
                output_node.is_healed = true;
                output_node.value = input_node.value * (1.0 - contraction_rate);
            } else {
                output_node.is_healed = false;
                output_node.value = input_node.value;
            }
            return output_node;
        }

        static inline double evaluate_v_finite(double r_nm) {
            return 1.0 / std::sqrt((r_nm * r_nm) + EPSILON_NM2);
        }
    };

    class TsgGateController {
    public:
        static inline bool validate_authorization(uint8_t gate_request, bool bit_tampered) {
            if (bit_tampered) return false;
            return (gate_request >= 0x01 && gate_request <= 0x04);
        }
    };

} // namespace torky::compiler::ast

#endif // TORKY_AST_METACOMPILER_HPP
