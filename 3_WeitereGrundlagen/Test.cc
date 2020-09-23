#define VAL 5

int f(int i)
{
	return i + VAL;
}

int main()
{
	for (int i = 0; i < 1000000; ++i)
	{
		f(2);
	}
}