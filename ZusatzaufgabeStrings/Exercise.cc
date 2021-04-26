#include "Exercise.h"

// Exercise 1
bool is_palindrom(const std::string &str)
{
    // std::string::iterator it; // begin(),     end()
    // std::string::const_iterator cit; // cbegin(),     cend()
    // std::string::const_reverse_iterator crit; // crbegin(), crend()

    // "anna" begin => 0, end() => 3
    // "anna" rbegin => 3, rend() => 0
    // crbegin()
    const std::string str_reversed(str.crbegin(), str.crend());

    if (str == str_reversed)
        return true;
    else
        return false;
}

// Exercise 2
bool is_in_string(const std::string str, const std::string sub_str)
{
    std::size_t str_len = str.length();
    std::size_t sub_str_len = sub_str.length();

    if (sub_str_len > str_len || sub_str_len == 0)
        return 0;

    // HALLO, 5
    // HAL
    // ALL
    // LLO

    // LO, 2
    for (std::string::const_iterator it = str.cbegin(); it != str.cend() - (sub_str_len - 1); ++it)
    {
        const std::string check_substr(it, it + sub_str_len);

        if (check_substr == sub_str)
            return true;
    }

    return false;
}

// Exercise 3
//unsigned int str_concat_exponent(const std::string str, const std::string base)
//{
//	//std::string str3 = "abab"; 6
//	// std::string base = "ab"; 2
//	// exponent = 2, ab + ab = abab = (ab){2}
//
//	unsigned int exponent = str.length() / base.length();
//	std::regex regexp("(" + base + "){" + std::to_string(exponent) + "}");
//
//	if (!regex_match(str, regexp))
//		return 0;
//	else
//		return exponent;
//}

// Exercise 3
unsigned int str_concat_exponent(const std::string str, const std::string base)
{
    std::string cmp_str = str;
    unsigned int count = 0;

    while (cmp_str.find(base) != std::string::npos)
    {
        // Wenn str zwingend ausschließlich aus base bestehen darf, folgende if-Abfrage:
        if (cmp_str.find(base) != 0)
            return 0;
        ++count;
        cmp_str = cmp_str.substr(cmp_str.find_first_of(base) + base.length());
    }

    // Wenn str zwingend ausschließlich aus base bestehen darf, folgende if-Abfrage:
    if (cmp_str.length() > 0)
        return 0;
    else
        return count;
}
