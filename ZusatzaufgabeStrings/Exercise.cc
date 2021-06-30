#include "Exercise.h"

// Exercise 1
bool is_palindrom(const std::string &str)
{
    const std::string str_reversed(str.crbegin(), str.crend());

    if (str == str_reversed)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Exercise 2
bool is_in_string(const std::string &str, const std::string &sub_str)
{
    auto str_len = str.length();
    auto sub_str_len = sub_str.length();

    if (sub_str_len > str_len || sub_str_len == 0 || str_len == 0)
    {
        return false;
    }

    for (auto it = str.cbegin(); it != (str.cend() - (sub_str_len - 1)); ++it)
    {
        const std::string check_substr(it, it + sub_str_len);

        if (check_substr == sub_str)
        {
            return true;
        }
    }

    return false;
}

// Exercise 3
unsigned int str_concat_exponent(const std::string &str,
                                 const std::string &base)
{
    std::string cmp_str = str;
    unsigned int count = 0;

    while (cmp_str.find(base) != std::string::npos)
    {
        if (cmp_str.find(base) != 0)
        {
            return 0;
        }

        ++count;
        cmp_str = cmp_str.substr(cmp_str.find_first_of(base) + base.length());
    }

    if (cmp_str.length() > 0)
    {
        return 0;
    }
    else
    {
        return count;
    }
}
