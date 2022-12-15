#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>
#include <chrono>
#include <memory>
#include <cstddef>

class Randomizer
{
	std::random_device rd;
	std::mt19937::result_type seed;
	std::unique_ptr<std::mt19937> gen;
public:
	Randomizer()
	{
		seed = rd() ^ (
			(std::mt19937::result_type)
			std::chrono::duration_cast<std::chrono::seconds>(
				std::chrono::system_clock::now().time_since_epoch()
				).count() +
			(std::mt19937::result_type)
			std::chrono::duration_cast<std::chrono::microseconds>(
				std::chrono::high_resolution_clock::now().time_since_epoch()
				).count());
		gen = std::make_unique<std::mt19937>(seed);
	}

	int64_t get_int(int64_t a, int64_t b)
	{
		std::uniform_int_distribution<int64_t> distrib(a, b);
		return distrib(*gen);
	}

    double get_double(double a, double b)
    {
        std::uniform_real_distribution<double> distrib(a, b);
        return distrib(*gen);
    }

    bool get_bool()
    {
        int64_t value = get_int(0, std::numeric_limits<int64_t>::max());
        return static_cast<bool>(value % 2);
    }
};

#endif // RANDOMIZER_H
