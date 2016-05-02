// Tymoteusz Lekszycki
// 18.04.2016

#include "My_Window.h"

//---------------------------------------------------------------------
// Main
//---------------------------------------------------------------------

int main(int argc, char* argv[])
{
	try {
		My_Window* win = new My_Window();
		
		win->show(argc,argv);
	} catch (std::exception& e) {
		std::cerr << e.what();
		exit (1);
	}
	
	return Fl::run();
}