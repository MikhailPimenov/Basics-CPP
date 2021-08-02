#include <iostream>
#include <utility>


class Verbose_string final: public std::string {
	using Base = std::string;
public:
	template<typename... Args>
	Verbose_string(Args... args) : 
		Base(std::forward<Args>(args)...) {
		std::cout << "Verbose_string(Args...):\n";
	}
	Verbose_string(const std::string& string) :
		Base(string) {
		std::cout << "Verbose_string(const std::string&):\n";
	}
	Verbose_string(std::string&& string) :
		Base(std::move_if_noexcept(string)) {
		std::cout << "Verbose_string(std::string&&):\n";
	}
	Verbose_string(const Verbose_string& object) :
		Base(static_cast<const Base&>(object)) {
		std::cout << "Verbose_string(const Verbose_string&):\n";
	}
	Verbose_string(Verbose_string&& object) noexcept:
		Base(std::move_if_noexcept(static_cast<Base&>(object))) {
		std::cout << "Verbose_string(Verbose_string&&):\n";
	}
	
};

int main() 
{
    std::string source("Hello, world!");

    std::cout << "Expected Verbose_string(std::string&&):\n";
    Verbose_string string(std::string("Hello, world!"));
    std::cout << string << '\n';


    std::cout << "Expected Verbose_string(const Verbose_string&):\n";
    Verbose_string string2(string);
    std::cout << string2 << '\n';


    std::cout << "Expected Verbose_string(Args...):\n";
    Verbose_string string3(source.rbegin(), source.rend());
    std::cout << string3 << '\n';


    std::cout << "If no_except-rule is upheld, expected Verbose_string(Verbose_string&&):\n";
    Verbose_string string4(std::move_if_noexcept(string3));
    std::cout << string4 << '\n';
    std::cout << string3 << '\n';
    
    std::cout << "If no_except-rule is upheld, expected Verbose_string(std::string&&):\n";
    Verbose_string string5(std::move_if_noexcept(source));
    std::cout << string5 << '\n';
    std::cout << source << '\n';
    
    return 0;
}
