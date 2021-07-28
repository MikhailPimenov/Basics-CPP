#include <iostream>
#include <utility>
#include <vector>

template <typename T>
void swap(T& a, T& b) {
	T temp(a);
	a = b;
	b = temp;
}

template <typename T>
void swap_move(T& a, T& b) {
	T temp(std::move(a));
	a = std::move(b);
	b = std::move(temp);
}


int main() {
	std::string s1("John");
	std::string s2("Andrew");

    std::cout << "s1: " << s1 << '\n';
    std::cout << "s2: " << s2 << '\n';
	std::cout << '\n';

	swap(s1, s2);

    std::cout << "s1: " << s1 << '\n';
    std::cout << "s2: " << s2 << '\n';
	std::cout << '\n';

	swap_move(s1, s2);

	std::cout << "s1: " << s1 << '\n';
	std::cout << "s2: " << s2 << '\n';
	std::cout << '\n';


	std::vector<std::string> vector;
	vector.push_back(s1);
	std::cout << "s1: " << s1 << '\n';
	vector.push_back(std::move(s2));
	std::cout << "s2 after it has been moved: " << s2 << '\n';

	return 0;
}