#pragma once
#include <vector>

namespace ces {
    // ---------- DEFINES
#ifdef CES_USE_DOUBLE
    /// @brief The standard number type used; double if CES_USE_DOUBLE is defined, otherwhise float.
    typedef double number;
#else
    /// @brief The standard number type used; double if CES_USE_DOUBLE is defined, otherwhise float.
    typedef float number;
#endif

#ifdef CES_CUSTOM_PRECISION
    /// @brief The precision at which the result is calculated
    constexpr number PRECISION = CES_CUSTOM_PRECISION;
#else
    /// @brief The precision at which the result is calculated
    constexpr number PRECISION = 1e-6;
#endif

    // ---------- STRUCTS
    /// @brief A struct that holds a cubic equation.
    typedef struct CubicEquation_f {
        /// @brief The first constant of the cubic equation.
        float a;
        /// @brief The second constant of the cubic equation.
        float b;
        /// @brief The third constant of the cubic equation.
        float c;
        /// @brief The fourth constant of the cubic equation.
        float d;

        /// @brief Calculates the result of the equation.
        /// @param x The variable's value in the equation.
        /// @return The result of the equation.
        float GetResult(float x) {
            return a * x * x * x + b * x * x + c * x + d;
        }
        /// @brief Returns if the given variable is valid in the equation.
        /// @param x The variable's value in the equation.
        /// @return If the result opf the equation is between -PRECISION and PRECISION
        bool IsVariableValid(float x) {
            float result = GetResult(x);
            return result >= -PRECISION && result <= PRECISION;
        }
    } CubicEquation_f;
    /// @brief A struct that holds a cubic equation.
    typedef struct CubicEquation_d {
        /// @brief The first constant of the cubic equation.
        double a;
        /// @brief The second constant of the cubic equation.
        double b;
        /// @brief The third constant of the cubic equation.
        double c;
        /// @brief The fourth constant of the cubic equation.
        double d;

        /// @brief Calculates the result of the equation.
        /// @param x The variable's value in the equation.
        /// @return The result of the equation.
        double GetResult(double x) {
            return a * x * x * x + b * x * x + c * x + d;
        }
        /// @brief Returns if the given variable is valid in the equation.
        /// @param x The variable's value in the equation.
        /// @return If the result opf the equation is between -PRECISION and PRECISION
        bool IsVariableValid(double x) {
            double result = GetResult(x);
            return result >= -PRECISION && result <= PRECISION;
        }
    } CubicEquation_d;

#ifdef CES_USE_DOUBLE
    typedef CubicEquation_d CubicEquation;
#else
    typedef CubicEquation_f CubicEquation;
#endif

    // ---------- FUNCTIONS
    /// @brief Solves the given cubic equation.
    /// @param cubicEquation The cubic equation to solve.
    /// @return A vector with every solution to the equation.
    inline std::vector<number> SolveCubicEquation(CubicEquation cubicEquation) {
        std::vector<float>  SolveCubicEquation_f(CubicEquation_f cubicEquation, float  precision);
        std::vector<double> SolveCubicEquation_d(CubicEquation_d cubicEquation, double precision);

#ifdef CES_USE_DOUBLE
        return SolveCubicEquation_d(cubicEquation, PRECISION);
#else
        return SolveCubicEquation_f(cubicEquation, PRECISION);
#endif
    }
}