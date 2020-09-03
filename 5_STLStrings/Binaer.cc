#include <iostream>
#include <bitset>

using std::bitset;
using std::string;

int main()
{
	// Bitset
	bitset<8> my_byte(string("00011101"));
	bitset<8> my_byte2(string("10010101"));

	std::cout << std::endl
			  << my_byte;
	std::cout << std::endl
			  << my_byte2;
	std::cout << std::endl
			  << std::endl;
	std::cout << std::endl
			  << (my_byte & my_byte2);
	std::cout << std::endl
			  << (my_byte ^ my_byte2);
	std::cout << std::endl
			  << (my_byte | my_byte2);
	std::cout << std::endl
			  << (my_byte2 << 8);
	std::cout << std::endl
			  << (~my_byte2);

	// Standard Bin�r
	/*unsigned char bin1 = 0b01;
	unsigned char bin2 = 0b10;

	unsigned char result = bin1 ^ bin2;*/

	// Hexa
	unsigned char hex1 = 0x01; // 0000 0001
	unsigned char hex2 = 0xff; // 1111 1111
							   // 1111 1110

	unsigned char hex3 = hex1 ^ hex2;
	std::cout << std::endl
			  << std::hex << (int)hex3;

	return 0;
}