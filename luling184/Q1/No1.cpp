# include <iostream>
# include <string>

std::string toFizzBuzz(int value)
{
	if (value % 15 == 0)
	{
		return "FizzBuzz";
	}
	else if (value % 5 == 0)
	{
		return "Buzz";
	}
	else if (value % 3 == 0)
	{
		return "Fizz";
	}
	else
	{
		return std::to_string(value);
	}
}

int main()
{
	for (int i = 1; i <= 50; ++i)
	{
		std::cout << toFizzBuzz(i) << " ";
	}

	return 0;
}
