export module nstd.concepts;

export template <typename X>
concept String = requires (X x, char c) {
	(char const*) x;
	c = x [0];
};

export template <typename X>
concept Number = requires (X x, int i, double d, float f) {
	i = (int) x;
	d = (double) x;
	f = (float) x;
};

static_assert (String <decltype ("hej")>);
static_assert (Number <double>);
static_assert (Number <float>);
static_assert (Number <int>);