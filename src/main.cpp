#include "app.hpp"

App app;

int main(int argc, char* argv[])
{
	if(argc > 1)
		app.initApp(argv[1]);
	else
		app.initApp("res/bg.png");

	return 0;
}

