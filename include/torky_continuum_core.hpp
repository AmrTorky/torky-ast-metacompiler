#ifndef TORKY_CONTINUUM_CORE_HPP
#define TORKY_CONTINUUM_CORE_HPP

#include <cmath>
#include <cstdint>
#include <cstring>
#include <array>
#include <chrono>
#include <iostream>

namespace torky::continuum {

inline constexpr double EPSILON_NM2        = 0.016;
inline constexpr double V_FINITE_ZERO_EV   = 11.384;
inline constexpr double FIM_LAMBDA_MIN     = 7.38905609893065;

#pragma pack(push, 1)
struct TORKY_CELL_DTYPE {
    uint32_t quantized_manifold_coord;
    uint16_t fim_metric_mantissa;
    uint16_t phase_coherence_rad;
    uint8_t autopoietic_status_flags;
};
#pragma pack(pop)
static_assert(sizeof(TORKY_CELL_DTYPE) == 9, "9-byte invariant violated");

[[nodiscard]] inline constexpr double oslash_epsilon(double numerator, double r_nm) noexcept {
    return numerator / std::sqrt((r_nm * r_nm) + EPSILON_NM2);
}

[[nodiscard]] inline constexpr double v_finite_ev(double r_nm) noexcept {
    constexpr double k_scale = V_FINITE_ZERO_EV * 0.12649110640673518; // 11.384 * sqrt(0.016)
    return k_scale / std::sqrt((r_nm * r_nm) + EPSILON_NM2);
}

} // namespace torky::continuum

namespace torky {
    using namespace continuum;
}

#endif // TORKY_CONTINUUM_CORE_HPP
