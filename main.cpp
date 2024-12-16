#include <coroutine>
#include <chrono>
#include <utility>
import nstd.concepts;

using namespace std::chrono_literals;

template <typename T>
struct task_t {
	struct promise_type {

	};
};

struct seconds_t {
	unsigned int s;
};

// int operator""_sr(int);

// auto wait () noexcept -> task_t {
// 	co_await 5s;
// }
struct time_awaitable {
	std::chrono::system_clock::duration d_;
	time_awaitable(std::chrono::system_clock::duration d) : d_(d) {}
	bool await_ready() const { return d_.count() <= 0; }
	void await_suspend(std::coroutine_handle<> h) { /* ... */ }
	void await_resume() {}
 };

template <class Rep, class Period>
auto operator co_await(std::chrono::duration<Rep, Period> d) {
 
 return time_awaitable {d};
}

template <typename T>
class [[nodiscard]] Task {
	struct Promise { /* ... */ }; // See below
	std::coroutine_handle<Promise> h_;
	explicit Task(Promise & p) noexcept : h_{std::coroutine_handle<Promise>::from_promise(p)} {}
	public:
 using promise_type = Promise;
	Task(Task&& t) noexcept : h_{std::exchange(t.h_, {})} {}
	~Task() { if (h_) h_.destroy(); }
	// Awaitable interface
	bool await_ready() { return false; }
	auto await_suspend(std::coroutine_handle<> c) {
	h_.promise().continuation_ = c;
	return h_;
	}
	auto await_resume() -> T {
	auto& result = h_.promise().result_;
	if (result.index() == 1) {
	return std::get<1>(std::move(result));
	} else {
	std::rethrow_exception(std::get<2>(std::move(result)));
	}
	}
	};

// auto wait () -> time_awaitable {
// 	co_await 10ms;
// }

auto main (int argc, char** argv) -> int {
	auto s = 5s;
	// hej ();
	return 0;
}