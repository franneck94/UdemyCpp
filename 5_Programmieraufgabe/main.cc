#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "exercise.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;

int main()
{
	ifstream iffile;
	iffile.open("text.txt", std::ios::in);
	std::string content;
	iffile >> content;
	iffile.close();
	cout << "Content: " << content << endl;

	ByteArray plain_text(content.begin(), content.end());
	ByteArray key(8, 0xff);
	ByteArray cipher_text = hex_vector_xor(plain_text, key);

	for (int i = 0; i != cipher_text.size(); ++i)
	{
		cout << "Cipher[" << i << "] = " << cipher_text[i] << endl;
	}
	cout << endl;

	ByteArray message = hex_vector_xor(cipher_text, key);

	for (int i = 0; i != message.size(); ++i)
	{
		cout << "Message[" << i << "] = " << message[i] << endl;
	}
	cout << endl;

	return 0;
}