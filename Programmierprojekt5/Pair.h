#pragma once

#include <type_traits>

namespace learncpp
{

template <class T1, class T2>
class pair
{
public:
    using first_type = T1;
    using second_type = T2;
public:
    /**
     * @brief Default constructor for same types.
     * 
     * @tparam U1 = T1
     * @tparam U2 = T2
     */
    template<class U1 = T1, class U2 = T2,
        std::enable_if_t<std::conjunction_v<
            std::is_default_constructible<U1>,
            std::is_default_constructible<U2>>,
        int> = 0>
    constexpr explicit(
        !std::is_default_constructible_v<U1> ||
        !std::is_default_constructible_v<U1>
    )
    pair() 
    noexcept(
        std::conjunction_v<
            std::is_nothrow_default_constructible_v<T1>, 
            std::is_nothrow_default_constructible_v<T2>>
    )
    : first(), second()
    {
    }

    /**
     * @brief Constructor for two const lvalue references of T1,T2.
     * 
     * @tparam U1 = T1
     * @tparam U2 = T2
     */
    template <class U1 = T1, class U2 = T2,
        std::enable_if_t<std::conjunction_v<
            std::is_copy_constructible<U1>,
            std::is_copy_constructible<U2>>,
        int> = 0>
    constexpr explicit(
        !std::is_convertible_v<const first_type&, first_type> ||
        !std::is_convertible_v<const second_type&, second_type>
    )
    pair(const T1& x, const T2& y) 
    noexcept(
        std::conjunction_v<
            std::is_nothrow_copy_constructible<U1>, 
            std::is_nothrow_copy_constructible<U2>>
    )
    : first(x), second(y)
    {
    }

    /**
     * @brief Constructor for two rvalue references of T1,T2.
     * 
     * @tparam U1 - is_constructible to T1
     * @tparam U2 - is_constructible to T2
     */
    template <class U1, class U2,
        std::enable_if_t<std::conjunction_v<
            std::is_constructible<T1, U1>,
            std::is_constructible<T2, U2>>,
        int> = 0>
    constexpr explicit(
        !std::is_convertible_v<U1, T1> ||
        !std::is_convertible_v<U2, T2>
    )
    pair(U1&& x, U2&& y)
    noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T1, U1>, 
            std::is_nothrow_constructible<T2, U2>>
    )
    : first(std::forward<U1>(x)), second(std::forward<U2>(y))
    {
    }

    /**
     * @brief Default copy constructor of const lvalue pair of same types.
     * 
     * @param p 
     */
    pair(const pair& p) = default;

    /**
     * @brief Default move constructor of rvalue pair of same types.
     * 
     * @param p 
     */
    pair(pair&& p) = default;

    /**
     * @brief Copy constructor of const lvalue pair of different types.
     * 
     * @tparam U1 - is_constructible to T1
     * @tparam U2 - is_constructible to T2
     * 
     * TODO: std::is_constructible<T1, U1> <=> std::is_constructible<U1, T1> ??? 
     */
    template <class U1, class U2,
        std::enable_if_t<std::conjunction_v<
            std::is_constructible<T1, const U1&>,
            std::is_constructible<T2, const U2&>>,
        int> = 0>
    constexpr explicit(
        !std::is_convertible_v<const U1&, T1> ||
        !std::is_convertible_v<const U2&, T2>
    )
    pair(const pair<U1, U2>& other)
    noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T1, const U1&>, 
            std::is_nothrow_constructible<T2, const U2&>>
    )
    : first(other.first), second(other.second)
    {
    }

    /**
     * @brief Move constructor of rvalue pair of different types.
     * 
     * @tparam U1 - is_constructible to T1
     * @tparam U2 - is_constructible to T2
     * 
     * TODO: std::is_constructible<T1, U1> <=> std::is_constructible<U1, T1> ??? 
     */
    template <class U1, class U2,
        std::enable_if_t<std::conjunction_v<
            std::is_constructible<T1, U1>,
            std::is_constructible<T2, U2>>,
        int> = 0>
    constexpr explicit(
        !std::is_convertible_v<U1, T1> ||
        !std::is_convertible_v<U2, T2>
    )
    pair(pair<U1, U2>&& other) 
    noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T1, U1>, 
            std::is_nothrow_constructible<T2, U2>>
    )
    : first(std::forward<U1>(other.first)), second(std::forward<U2>(other.second)) 
    {
    }

    /**
     * @brief Delete copy assignment operator for const volatile lvalue pair
     * 
     * @param pair 
     * @return pair& 
     */
    pair& operator=(const volatile pair&) = delete;

    /**
     * @brief Copy assignment opeator of const lvalue pair of same types.
     * 
     * @param other 
     * @return constexpr pair& 
     */
    template <class U1 = T1, class U2 = T2>
    constexpr
    pair& operator=(const pair& other)
    noexcept(
        std::conjunction_v<
            std::is_nothrow_copy_assignable<U1>,
            std::is_nothrow_copy_assignable<U2>>
    ) 
    {
        first = other.first;
        second = other.second;

        return *this;
    }

    /**
     * @brief Copy assignment opeator of const lvalue pair of different types.
     * 
     * @tparam U1 - is_assignable and is_nothrow_assignable to T1
     * @tparam U2 - is_assignable and is_nothrow_assignable to T2
     * @param other 
     * @return constexpr pair& 
     */
    template <class U1, class U2,
        std::enable_if_t<std::conjunction_v<
            std::negation<std::is_same<pair, pair<U1, U2>>>,
            std::is_assignable<T1&, const U1&>,
            std::is_assignable<T2&, const U2&>>,
        int> = 0>
    constexpr 
    pair& operator=(const pair<U1,U2>& other) 
    noexcept(
        std::conjunction_v<
            std::is_nothrow_assignable<T1&, const U1&>, 
            std::is_nothrow_assignable<T2&, const U2&>>
    )
    {
        first  = other.first;
        second = other.second;

        return *this;
    }

    /**
     * @brief Move assignment opeator of rvalue pair of same types.
     * 
     * @param other 
     * @return constexpr pair& 
     */
    template <class _Pair = pair,
        std::enable_if_t<std::conjunction_v<
            std::is_move_assignable_v<typename _Pair::first_type>,
            std::is_move_assignable_v<typename _Pair::second_type>>,
        int> = 0>
    constexpr pair& operator=(_Pair&& other)
    noexcept(
        std::conjunction_v<
            std::is_nothrow_move_assignable<T1>,
            std::is_nothrow_move_assignable<T2>>
    )
    {
        first  = std::forward<T1>(other.first);
        second = std::forward<T2>(other.second);

        return *this;
    }

    /**
     * @brief Move assignment opeator of rvalue pair of different types.
     * 
     * @tparam U1 - is_assignable and is_nothrow_assignable_v to T1
     * @tparam U2 - is_assignable and is_nothrow_assignable_v to T2
     * @param other 
     * @return constexpr pair& 
     */
    template <class U1, class U2,
        std::enable_if_t<std::conjunction_v<
            std::negation<std::is_same<pair, pair<U1, U2>>>, 
            std::is_assignable<T1&, U1>, 
            std::is_assignable<T2&, U2>>,
        int> = 0>
    pair& operator=(pair<U1, U2>&& other)
    noexcept(
        std::conjunction_v<
            std::is_nothrow_assignable<T1&, U1>,
            std::is_nothrow_assignable<T2&, U2>>
    )
    {
        first  = std::forward<U1>(other.first);
        second = std::forward<U2>(other.second);

        return *this;
    }

    /**
     * @brief Swap pair values of same type.
     * 
     * @param other 
     */
    constexpr
    void swap(pair& other)
    noexcept(
        std::conjunction_v<
            std::is_nothrow_swappable<T1>,
            std::is_nothrow_swappable<T2>>
    )
    {
        if (this != std::addressof(other))
        {
            std::swap(first, other.first);
            std::swap(second, other.second);
        }
    }

    T1 first;
    T2 second;
};

}