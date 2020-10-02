#pragma once

#include <utility>
#include <type_traits>

template <class T1, class T2>
class Pair
{
public:
    using first_type = T1;
    using second_type = T2;
public:
    template<class U1 = T1, class U2 = T2,
        enable_if_t<std::conjunction_v<std::is_default_constructible<U1>,
                                       std::is_default_constructible<U2>>, int> = 0>
    constexpr explicit(!std::is_default_constructible_v<U1> ||
                       !std::is_default_constructible_v<U1>)
    Pair() noexcept :
        first(), second()
    {
    }

    template <class U1 = T1, class U2 = T2,
        enable_if_t<std::conjunction_v<std::is_copy_constructible<U1>,
                                       std::is_copy_constructible<U2>>, int> = 0>
    constexpr explicit(!std::is_convertible_v<const first_type&, first_type> ||
                       !std::is_convertible_v<const second_type&, second_type>)
    Pair(const T1& x, const T2& y) noexcept :
        first(x), second(y)
    {
    }

    Pair(const Pair& p) = default;

    Pair(Pair&& p) = default;

    template <class _Pair = Pair,
        enable_if_t<std::conjunction_v<std::is_copy_assignable_v<typename _Pair::first_type>,
                                       std::is_copy_assignable_v<typename _Pair::second_type>>, int> = 0>
    constexpr Pair& operator=(const _Pair& other) noexcept
    {
        first = other.first;
        second = other.second;

        return *this;
    }

    template <class U1, class U2,
        enable_if_t<std::conjunction_v<std::negation<std::is_same<Pair, Pair<U1, U2>>>,
                                       std::is_assignable<T1&, const U1&>,
                                       std::is_assignable<T2&, const U2&>>, int> = 0>
    constexpr Pair& operator=(const Pair<U1,U2>& other) noexcept
    {
        first  = other.first;
        second = other.second;

        return *this;
    }

    template <class _Pair = Pair,
        enable_if_t<std::conjunction_v<std::is_move_assignable_v<typename _Pair::first_type>,
                                       std::is_move_assignable_v<typename _Pair::second_type>>, int> = 0>
    constexpr Pair& operator=(_Pair&& other) noexcept
    {
        first  = std::forward<T1>(_Right.first);
        second = std::forward<T2>(_Right.second);

        return *this;
    }

    constexpr void swap(Pair& other) noexcept
    {
        if (this != &other)
        {
            std::swap(first, _Right.first);
            std::swap(second, _Right.second);
        }
    }

    T1 first;
    T2 second;
};