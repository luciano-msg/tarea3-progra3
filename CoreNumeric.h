#ifndef CORE_NUMERIC_H
#define CORE_NUMERIC_H

#include <concepts>
#include <iterator>
#include <cstddef>
#include <type_traits>

using namespace std;

namespace core_numeric {

template <typename C>
concept Iterable = requires(C c) {
    begin(c);
    end(c);
};

template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> same_as<T>;
};

template <typename T>
concept Divisible = requires(T a, size_t n) {
    { a / n } -> same_as<T>;
};

// Concept propio: exige que el tipo tenga operator< devolviendo bool.
template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> same_as<bool>;
};

template <Iterable C>
requires Addable<typename C::value_type>
auto sum(const C& container) {
    using T = typename C::value_type;
    T result{};
    for (const auto& v : container) result = result + v;
    return result;
}

template <Iterable C>
requires Addable<typename C::value_type> && Divisible<typename C::value_type>
auto mean(const C& container) {
    using T = typename C::value_type;
    size_t n = distance(begin(container), end(container));
    T s = sum(container);
    return s / n;
}

template <Iterable C>
requires Addable<typename C::value_type>
auto variance(const C& container) {
    using T = typename C::value_type;
    auto m = mean(container);
    T acc{};
    size_t n = 0;
    for (const auto& v : container) {
        T d = v - m;
        acc = acc + d * d;
        ++n;
    }
    return acc / n;
}

template <Iterable C>
requires Comparable<typename C::value_type>
auto max(const C& container) {
    auto it = begin(container);
    auto e = end(container);
    auto best = *it;
    ++it;
    while (it != e) {
        if (best < *it) best = *it;
        ++it;
    }
    return best;
}

template <Iterable C, typename F>
auto transform_reduce(const C& container, F fn) {
    auto it = begin(container);
    auto e = end(container);
    auto acc = fn(*it);
    ++it;
    while (it != e) {
        acc = acc + fn(*it);
        ++it;
    }
    return acc;
}

// --- Variadic con fold expressions ---

template <typename... Args>
requires (Addable<Args> && ...)
auto sum_variadic(Args... args) {
    return (args + ...);
}

// mean_variadic usa if constexpr para promover enteros a double
// y evitar division entera.
template <typename... Args>
requires (Addable<Args> && ...)
auto mean_variadic(Args... args) {
    auto s = (args + ...);
    if constexpr (is_integral_v<decltype(s)>) {
        return static_cast<double>(s) / sizeof...(args);
    } else {
        return s / sizeof...(args);
    }
}

template <typename... Args>
requires (Addable<Args> && ...)
auto variance_variadic(Args... args) {
    auto m = mean_variadic(args...);
    using R = decltype(m);
    // El fold necesita una expresion simple sobre el pack, asi que
    // envolvemos el calculo del cuadrado de la diferencia en un lambda.
    auto sq = [m](auto x) { R d = static_cast<R>(x) - m; return d * d; };
    R sum_sq = (sq(args) + ...);
    return sum_sq / sizeof...(args);
}

template <typename T, typename... Rest>
requires Comparable<T> && (Comparable<Rest> && ...)
T max_variadic(T first, Rest... rest) {
    T result = first;
    ((result = result < static_cast<T>(rest) ? static_cast<T>(rest) : result), ...);
    return result;
}

} // namespace core_numeric

#endif
