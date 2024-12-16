module;
#include <iostream>
export module nstd;

export auto hej () noexcept -> void {
	std::cout << "hello world" << std::endl;
}