#include <iostream>
#include "include/Window/WindowManagement.h"

using namespace std;

int main() {
	WindowManagement myWindow;
	myWindow.init(800, 600);
	myWindow.mainLoop();
	return 0;
}