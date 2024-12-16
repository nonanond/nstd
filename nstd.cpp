module;
#include <iostream>
export module nstd;
export import nstd.concepts;

// export import nstd.concepts;

export auto hej () noexcept -> void {
	std::cout << "hello world" << std::endl;
}