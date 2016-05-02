#ifndef MY_WINDOW
#define MY_WINDOW

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <exception>
#include <string>
#include <unistd.h>
#include <stdint.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Group.H>

#include <wiringPi.h>

class My_Window : public Fl_Window {
private:
	// Variables
	
	
	// Methods:
	template<typename T>
	std::string to_str(T value) {
		std::ostringstream os;
		
		os << value;
		
		return os.str();
	}
	
	double to_voltage(uint8_t value) {
		return (value * (3.3 / 1024));
	}
	
	// Widgets:
	Fl_Group* grpState;
	Fl_Group* grpControl;
	
	Fl_Output* lbl_wPi_0;
	Fl_Output* lbl_wPi_1;
	Fl_Output* lbl_wPi_2;
	Fl_Output* lbl_wPi_3;
	Fl_Output* lbl_wPi_4;
	Fl_Output* lbl_wPi_5;
	Fl_Output* lbl_wPi_6;
	Fl_Output* lbl_wPi_7;
	Fl_Output* lbl_wPi_8;
	Fl_Output* lbl_wPi_9;
	Fl_Output* lbl_wPi_10;
	Fl_Output* lbl_wPi_11;
	Fl_Output* lbl_wPi_12;
	Fl_Output* lbl_wPi_13;
	Fl_Output* lbl_wPi_14;
	Fl_Output* lbl_wPi_15;
	Fl_Output* lbl_wPi_16;
	Fl_Output* lbl_wPi_21;
	Fl_Output* lbl_wPi_22;
	Fl_Output* lbl_wPi_23;
	Fl_Output* lbl_wPi_24;
	Fl_Output* lbl_wPi_25;
	Fl_Output* lbl_wPi_26;
	Fl_Output* lbl_wPi_27;
	Fl_Output* lbl_wPi_28;
	Fl_Output* lbl_wPi_29;
	Fl_Output* lbl_wPi_30;
	Fl_Output* lbl_wPi_31;
	
	Fl_Button* btn_toggle_wPi_0;
	Fl_Button* btn_toggle_wPi_1;
	Fl_Button* btn_toggle_wPi_2;
	Fl_Button* btn_toggle_wPi_3;
	Fl_Button* btn_toggle_wPi_4;
	Fl_Button* btn_toggle_wPi_5;
	Fl_Button* btn_toggle_wPi_6;
	Fl_Button* btn_toggle_wPi_7;
	Fl_Button* btn_toggle_wPi_8;
	Fl_Button* btn_toggle_wPi_9;
	Fl_Button* btn_toggle_wPi_10;
	Fl_Button* btn_toggle_wPi_11;
	Fl_Button* btn_toggle_wPi_12;
	Fl_Button* btn_toggle_wPi_13;
	Fl_Button* btn_toggle_wPi_14;
	Fl_Button* btn_toggle_wPi_15;
	Fl_Button* btn_toggle_wPi_16;
	Fl_Button* btn_toggle_wPi_21;
	Fl_Button* btn_toggle_wPi_22;
	Fl_Button* btn_toggle_wPi_23;
	Fl_Button* btn_toggle_wPi_24;
	Fl_Button* btn_toggle_wPi_25;
	Fl_Button* btn_toggle_wPi_26;
	Fl_Button* btn_toggle_wPi_27;
	Fl_Button* btn_toggle_wPi_28;
	Fl_Button* btn_toggle_wPi_29;
	Fl_Button* btn_toggle_wPi_30;
	Fl_Button* btn_toggle_wPi_31;
	
	Fl_Button* btn_input_wPi_0;
	Fl_Button* btn_input_wPi_1;
	Fl_Button* btn_input_wPi_2;
	Fl_Button* btn_input_wPi_3;
	Fl_Button* btn_input_wPi_4;
	Fl_Button* btn_input_wPi_5;
	Fl_Button* btn_input_wPi_6;
	Fl_Button* btn_input_wPi_7;
	Fl_Button* btn_input_wPi_8;
	Fl_Button* btn_input_wPi_9;
	Fl_Button* btn_input_wPi_10;
	Fl_Button* btn_input_wPi_11;
	Fl_Button* btn_input_wPi_12;
	Fl_Button* btn_input_wPi_13;
	Fl_Button* btn_input_wPi_14;
	Fl_Button* btn_input_wPi_15;
	Fl_Button* btn_input_wPi_16;
	Fl_Button* btn_input_wPi_21;
	Fl_Button* btn_input_wPi_22;
	Fl_Button* btn_input_wPi_23;
	Fl_Button* btn_input_wPi_24;
	Fl_Button* btn_input_wPi_25;
	Fl_Button* btn_input_wPi_26;
	Fl_Button* btn_input_wPi_27;
	Fl_Button* btn_input_wPi_28;
	Fl_Button* btn_input_wPi_29;
	Fl_Button* btn_input_wPi_30;
	Fl_Button* btn_input_wPi_31;
	
	Fl_Button* btn_output_wPi_0;
	Fl_Button* btn_output_wPi_1;
	Fl_Button* btn_output_wPi_2;
	Fl_Button* btn_output_wPi_3;
	Fl_Button* btn_output_wPi_4;
	Fl_Button* btn_output_wPi_5;
	Fl_Button* btn_output_wPi_6;
	Fl_Button* btn_output_wPi_7;
	Fl_Button* btn_output_wPi_8;
	Fl_Button* btn_output_wPi_9;
	Fl_Button* btn_output_wPi_10;
	Fl_Button* btn_output_wPi_11;
	Fl_Button* btn_output_wPi_12;
	Fl_Button* btn_output_wPi_13;
	Fl_Button* btn_output_wPi_14;
	Fl_Button* btn_output_wPi_15;
	Fl_Button* btn_output_wPi_16;
	Fl_Button* btn_output_wPi_21;
	Fl_Button* btn_output_wPi_22;
	Fl_Button* btn_output_wPi_23;
	Fl_Button* btn_output_wPi_24;
	Fl_Button* btn_output_wPi_25;
	Fl_Button* btn_output_wPi_26;
	Fl_Button* btn_output_wPi_27;
	Fl_Button* btn_output_wPi_28;
	Fl_Button* btn_output_wPi_29;
	Fl_Button* btn_output_wPi_30;
	Fl_Button* btn_output_wPi_31;
	
	Fl_Button* btn_read_wPi_0;
	Fl_Button* btn_read_wPi_1;
	Fl_Button* btn_read_wPi_2;
	Fl_Button* btn_read_wPi_3;
	Fl_Button* btn_read_wPi_4;
	Fl_Button* btn_read_wPi_5;
	Fl_Button* btn_read_wPi_6;
	Fl_Button* btn_read_wPi_7;
	Fl_Button* btn_read_wPi_8;
	Fl_Button* btn_read_wPi_9;
	Fl_Button* btn_read_wPi_10;
	Fl_Button* btn_read_wPi_11;
	Fl_Button* btn_read_wPi_12;
	Fl_Button* btn_read_wPi_13;
	Fl_Button* btn_read_wPi_14;
	Fl_Button* btn_read_wPi_15;
	Fl_Button* btn_read_wPi_16;
	Fl_Button* btn_read_wPi_21;
	Fl_Button* btn_read_wPi_22;
	Fl_Button* btn_read_wPi_23;
	Fl_Button* btn_read_wPi_24;
	Fl_Button* btn_read_wPi_25;
	Fl_Button* btn_read_wPi_26;
	Fl_Button* btn_read_wPi_27;
	Fl_Button* btn_read_wPi_28;
	Fl_Button* btn_read_wPi_29;
	Fl_Button* btn_read_wPi_30;
	Fl_Button* btn_read_wPi_31;
	
	Fl_Button* btn_quit;
	
	// Events:
	void wPi_0_toggle(Fl_Widget* w);
	void wPi_1_toggle(Fl_Widget* w);
	void wPi_2_toggle(Fl_Widget* w);
	void wPi_3_toggle(Fl_Widget* w);
	void wPi_4_toggle(Fl_Widget* w);
	void wPi_5_toggle(Fl_Widget* w);
	void wPi_6_toggle(Fl_Widget* w);
	void wPi_7_toggle(Fl_Widget* w);
	void wPi_8_toggle(Fl_Widget* w);
	void wPi_9_toggle(Fl_Widget* w);
	void wPi_10_toggle(Fl_Widget* w);
	void wPi_11_toggle(Fl_Widget* w);
	void wPi_12_toggle(Fl_Widget* w);
	void wPi_13_toggle(Fl_Widget* w);
	void wPi_14_toggle(Fl_Widget* w);
	void wPi_15_toggle(Fl_Widget* w);
	void wPi_16_toggle(Fl_Widget* w);
	void wPi_21_toggle(Fl_Widget* w);
	void wPi_22_toggle(Fl_Widget* w);
	void wPi_23_toggle(Fl_Widget* w);
	void wPi_24_toggle(Fl_Widget* w);
	void wPi_25_toggle(Fl_Widget* w);
	void wPi_26_toggle(Fl_Widget* w);
	void wPi_27_toggle(Fl_Widget* w);
	void wPi_28_toggle(Fl_Widget* w);
	void wPi_29_toggle(Fl_Widget* w);
	void wPi_30_toggle(Fl_Widget* w);
	void wPi_31_toggle(Fl_Widget* w);
	
	void wPi_0_input(Fl_Widget* w);
	void wPi_1_input(Fl_Widget* w);
	void wPi_2_input(Fl_Widget* w);
	void wPi_3_input(Fl_Widget* w);
	void wPi_4_input(Fl_Widget* w);
	void wPi_5_input(Fl_Widget* w);
	void wPi_6_input(Fl_Widget* w);
	void wPi_7_input(Fl_Widget* w);
	void wPi_8_input(Fl_Widget* w);
	void wPi_9_input(Fl_Widget* w);
	void wPi_10_input(Fl_Widget* w);
	void wPi_11_input(Fl_Widget* w);
	void wPi_12_input(Fl_Widget* w);
	void wPi_13_input(Fl_Widget* w);
	void wPi_14_input(Fl_Widget* w);
	void wPi_15_input(Fl_Widget* w);
	void wPi_16_input(Fl_Widget* w);
	void wPi_21_input(Fl_Widget* w);
	void wPi_22_input(Fl_Widget* w);
	void wPi_23_input(Fl_Widget* w);
	void wPi_24_input(Fl_Widget* w);
	void wPi_25_input(Fl_Widget* w);
	void wPi_26_input(Fl_Widget* w);
	void wPi_27_input(Fl_Widget* w);
	void wPi_28_input(Fl_Widget* w);
	void wPi_29_input(Fl_Widget* w);
	void wPi_30_input(Fl_Widget* w);
	void wPi_31_input(Fl_Widget* w);
	
	void wPi_0_output(Fl_Widget* w);
	void wPi_1_output(Fl_Widget* w);
	void wPi_2_output(Fl_Widget* w);
	void wPi_3_output(Fl_Widget* w);
	void wPi_4_output(Fl_Widget* w);
	void wPi_5_output(Fl_Widget* w);
	void wPi_6_output(Fl_Widget* w);
	void wPi_7_output(Fl_Widget* w);
	void wPi_8_output(Fl_Widget* w);
	void wPi_9_output(Fl_Widget* w);
	void wPi_10_output(Fl_Widget* w);
	void wPi_11_output(Fl_Widget* w);
	void wPi_12_output(Fl_Widget* w);
	void wPi_13_output(Fl_Widget* w);
	void wPi_14_output(Fl_Widget* w);
	void wPi_15_output(Fl_Widget* w);
	void wPi_16_output(Fl_Widget* w);
	void wPi_21_output(Fl_Widget* w);
	void wPi_22_output(Fl_Widget* w);
	void wPi_23_output(Fl_Widget* w);
	void wPi_24_output(Fl_Widget* w);
	void wPi_25_output(Fl_Widget* w);
	void wPi_26_output(Fl_Widget* w);
	void wPi_27_output(Fl_Widget* w);
	void wPi_28_output(Fl_Widget* w);
	void wPi_29_output(Fl_Widget* w);
	void wPi_30_output(Fl_Widget* w);
	void wPi_31_output(Fl_Widget* w);
	
	void wPi_0_read(Fl_Widget* w);
	void wPi_1_read(Fl_Widget* w);
	void wPi_2_read(Fl_Widget* w);
	void wPi_3_read(Fl_Widget* w);
	void wPi_4_read(Fl_Widget* w);
	void wPi_5_read(Fl_Widget* w);
	void wPi_6_read(Fl_Widget* w);
	void wPi_7_read(Fl_Widget* w);
	void wPi_8_read(Fl_Widget* w);
	void wPi_9_read(Fl_Widget* w);
	void wPi_10_read(Fl_Widget* w);
	void wPi_11_read(Fl_Widget* w);
	void wPi_12_read(Fl_Widget* w);
	void wPi_13_read(Fl_Widget* w);
	void wPi_14_read(Fl_Widget* w);
	void wPi_15_read(Fl_Widget* w);
	void wPi_16_read(Fl_Widget* w);
	void wPi_21_read(Fl_Widget* w);
	void wPi_22_read(Fl_Widget* w);
	void wPi_23_read(Fl_Widget* w);
	void wPi_24_read(Fl_Widget* w);
	void wPi_25_read(Fl_Widget* w);
	void wPi_26_read(Fl_Widget* w);
	void wPi_27_read(Fl_Widget* w);
	void wPi_28_read(Fl_Widget* w);
	void wPi_29_read(Fl_Widget* w);
	void wPi_30_read(Fl_Widget* w);
	void wPi_31_read(Fl_Widget* w);
	
	void quit(Fl_Widget* w);
	
	// Callbacks:
	static void cb_input_0(Fl_Widget* w, void* f);
	static void cb_input_1(Fl_Widget* w, void* f);
	static void cb_input_2(Fl_Widget* w, void* f);
	static void cb_input_3(Fl_Widget* w, void* f);
	static void cb_input_4(Fl_Widget* w, void* f);
	static void cb_input_5(Fl_Widget* w, void* f);
	static void cb_input_6(Fl_Widget* w, void* f);
	static void cb_input_7(Fl_Widget* w, void* f);
	static void cb_input_8(Fl_Widget* w, void* f);
	static void cb_input_9(Fl_Widget* w, void* f);
	static void cb_input_10(Fl_Widget* w, void* f);
	static void cb_input_11(Fl_Widget* w, void* f);
	static void cb_input_12(Fl_Widget* w, void* f);
	static void cb_input_13(Fl_Widget* w, void* f);
	static void cb_input_14(Fl_Widget* w, void* f);
	static void cb_input_15(Fl_Widget* w, void* f);
	static void cb_input_16(Fl_Widget* w, void* f);
	static void cb_input_21(Fl_Widget* w, void* f);
	static void cb_input_22(Fl_Widget* w, void* f);
	static void cb_input_23(Fl_Widget* w, void* f);
	static void cb_input_24(Fl_Widget* w, void* f);
	static void cb_input_25(Fl_Widget* w, void* f);
	static void cb_input_26(Fl_Widget* w, void* f);
	static void cb_input_27(Fl_Widget* w, void* f);
	static void cb_input_28(Fl_Widget* w, void* f);
	static void cb_input_29(Fl_Widget* w, void* f);
	static void cb_input_30(Fl_Widget* w, void* f);
	static void cb_input_31(Fl_Widget* w, void* f);
	
	static void cb_output_0(Fl_Widget* w, void* f);
	static void cb_output_1(Fl_Widget* w, void* f);
	static void cb_output_2(Fl_Widget* w, void* f);
	static void cb_output_3(Fl_Widget* w, void* f);
	static void cb_output_4(Fl_Widget* w, void* f);
	static void cb_output_5(Fl_Widget* w, void* f);
	static void cb_output_6(Fl_Widget* w, void* f);
	static void cb_output_7(Fl_Widget* w, void* f);
	static void cb_output_8(Fl_Widget* w, void* f);
	static void cb_output_9(Fl_Widget* w, void* f);
	static void cb_output_10(Fl_Widget* w, void* f);
	static void cb_output_11(Fl_Widget* w, void* f);
	static void cb_output_12(Fl_Widget* w, void* f);
	static void cb_output_13(Fl_Widget* w, void* f);
	static void cb_output_14(Fl_Widget* w, void* f);
	static void cb_output_15(Fl_Widget* w, void* f);
	static void cb_output_16(Fl_Widget* w, void* f);
	static void cb_output_21(Fl_Widget* w, void* f);
	static void cb_output_22(Fl_Widget* w, void* f);
	static void cb_output_23(Fl_Widget* w, void* f);
	static void cb_output_24(Fl_Widget* w, void* f);
	static void cb_output_25(Fl_Widget* w, void* f);
	static void cb_output_26(Fl_Widget* w, void* f);
	static void cb_output_27(Fl_Widget* w, void* f);
	static void cb_output_28(Fl_Widget* w, void* f);
	static void cb_output_29(Fl_Widget* w, void* f);
	static void cb_output_30(Fl_Widget* w, void* f);
	static void cb_output_31(Fl_Widget* w, void* f);
	
	static void cb_toggle_0(Fl_Widget* w, void* f);
	static void cb_toggle_1(Fl_Widget* w, void* f);
	static void cb_toggle_2(Fl_Widget* w, void* f);
	static void cb_toggle_3(Fl_Widget* w, void* f);
	static void cb_toggle_4(Fl_Widget* w, void* f);
	static void cb_toggle_5(Fl_Widget* w, void* f);
	static void cb_toggle_6(Fl_Widget* w, void* f);
	static void cb_toggle_7(Fl_Widget* w, void* f);
	static void cb_toggle_8(Fl_Widget* w, void* f);
	static void cb_toggle_9(Fl_Widget* w, void* f);
	static void cb_toggle_10(Fl_Widget* w, void* f);
	static void cb_toggle_11(Fl_Widget* w, void* f);
	static void cb_toggle_12(Fl_Widget* w, void* f);
	static void cb_toggle_13(Fl_Widget* w, void* f);
	static void cb_toggle_14(Fl_Widget* w, void* f);
	static void cb_toggle_15(Fl_Widget* w, void* f);
	static void cb_toggle_16(Fl_Widget* w, void* f);
	static void cb_toggle_21(Fl_Widget* w, void* f);
	static void cb_toggle_22(Fl_Widget* w, void* f);
	static void cb_toggle_23(Fl_Widget* w, void* f);
	static void cb_toggle_24(Fl_Widget* w, void* f);
	static void cb_toggle_25(Fl_Widget* w, void* f);
	static void cb_toggle_26(Fl_Widget* w, void* f);
	static void cb_toggle_27(Fl_Widget* w, void* f);
	static void cb_toggle_28(Fl_Widget* w, void* f);
	static void cb_toggle_29(Fl_Widget* w, void* f);
	static void cb_toggle_30(Fl_Widget* w, void* f);
	static void cb_toggle_31(Fl_Widget* w, void* f);
	
	static void cb_read_0(Fl_Widget* w, void* f);
	static void cb_read_1(Fl_Widget* w, void* f);
	static void cb_read_2(Fl_Widget* w, void* f);
	static void cb_read_3(Fl_Widget* w, void* f);
	static void cb_read_4(Fl_Widget* w, void* f);
	static void cb_read_5(Fl_Widget* w, void* f);
	static void cb_read_6(Fl_Widget* w, void* f);
	static void cb_read_7(Fl_Widget* w, void* f);
	static void cb_read_8(Fl_Widget* w, void* f);
	static void cb_read_9(Fl_Widget* w, void* f);
	static void cb_read_10(Fl_Widget* w, void* f);
	static void cb_read_11(Fl_Widget* w, void* f);
	static void cb_read_12(Fl_Widget* w, void* f);
	static void cb_read_13(Fl_Widget* w, void* f);
	static void cb_read_14(Fl_Widget* w, void* f);
	static void cb_read_15(Fl_Widget* w, void* f);
	static void cb_read_16(Fl_Widget* w, void* f);
	static void cb_read_21(Fl_Widget* w, void* f);
	static void cb_read_22(Fl_Widget* w, void* f);
	static void cb_read_23(Fl_Widget* w, void* f);
	static void cb_read_24(Fl_Widget* w, void* f);
	static void cb_read_25(Fl_Widget* w, void* f);
	static void cb_read_26(Fl_Widget* w, void* f);
	static void cb_read_27(Fl_Widget* w, void* f);
	static void cb_read_28(Fl_Widget* w, void* f);
	static void cb_read_29(Fl_Widget* w, void* f);
	static void cb_read_30(Fl_Widget* w, void* f);
	static void cb_read_31(Fl_Widget* w, void* f);
	
	static void cb_quit(Fl_Widget* w, void* f);
	
public:
	// Constructor
	My_Window();
};

#endif