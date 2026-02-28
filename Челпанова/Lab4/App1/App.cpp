#include "App.hpp"

#include "IO.hpp"
#include "Sample.hpp"
#include "Mean.hpp"

int Run()
{
	PrintWelcome();

	int sampleSize = 0;
	float minVal = 0.0f;
	float maxVal = 0.0f;
	if (!GetInputVariables(sampleSize, minVal, maxVal)) {
		return EXIT_FAILURE;
	}

	try {
		std::vector<float> sample = GenerateSample(static_cast<size_t>(sampleSize), minVal, maxVal);

		PrintSample(sample);

		float arithmethicMean = GetArithmeticMean(sample);
		PrintResult("Arithmetic Mean", arithmethicMean);

		float geometricMean = GetGeometricMean(sample);
		PrintResult("Geometric Mean", geometricMean);

		float harmonicMean = GetHarmonicMean(sample);
		PrintResult("Harmonic Mean", harmonicMean);

		float squareMean = GetSquareMean(sample);
		PrintResult("Square Mean", squareMean);

		size_t arithmethicMeanCountLT = CountLessThan(sample, arithmethicMean);
		PrintResult("The number of elements in a sample that is less than the arithmetic mean", arithmethicMeanCountLT);

		size_t geometricMeanCountLT = CountLessThan(sample, geometricMean);
		PrintResult("The number of elements in a sample that is less than the geometric mean", geometricMeanCountLT);

		size_t harmonicMeanCountLT = CountLessThan(sample, harmonicMean);
		PrintResult("The number of elements in a sample that is less than the harmonic mean", harmonicMeanCountLT);

		size_t squareMeanCountLT = CountLessThan(sample, squareMean);
		PrintResult("The number of elements in a sample that is less than the square mean", squareMeanCountLT);

		size_t sumNegativeIndices = SumNegativeIndices(sample);
		PrintResult("Sum of the numbers of negative elements of the sample", sumNegativeIndices);
	}
	catch (const std::exception& e) {
		PrintError(e.what());
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
