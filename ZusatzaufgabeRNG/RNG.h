
template <typename T>
class RNG
{
public:
	RNG() : m_seed(0), m_state(0) {}
	RNG(T seed) : m_seed(seed), m_state(seed) {}

	T randomNumberGenerator()
	{
		m_state ^= m_state >> 1; // m_state = 110 >= 110 ^ 011 = 101
		m_state <<= 1; // 101 >= 010

		return m_state;
	}

	T randomNumberGeneratorRange(
		T &lower_bound,
		T &upper_bound)
	{
		m_state = randomNumberGenerator();

		// Case: Too small
		while (m_state < lower_bound)
			m_state <<= 1; // lb=100(4), m_state=011(3), m_state=110(6)

		// Case: Too big
		if (m_state > upper_bound)
			m_state %= (upper_bound + 1); // ub=100, m_state = 133, X % (101) = {0, 1, ..., 100}

		// Case: Too small
		while (m_state < lower_bound)
			m_state <<= 1; // lb=100(4), m_state=011(3), m_state=110(6)

		return m_state;
	}

private:
	T m_seed;
	T m_state;
};