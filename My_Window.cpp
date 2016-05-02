#include "My_Window.h"

const uint32_t time_us = 100000;
const char* window_title = "RaspberryPi Interface";
const char* input_btn_text = "Input";
const char* output_btn_text = "Output";
const char* toggle_btn_text = "Toggle";
const char* read_btn_text = "Read";
const char* quit_btn_text = "Quit";

const uint16_t my_window_w = 510;
const uint16_t my_window_h = 640;

const uint16_t wPi_lbl_x = 130;
const uint16_t wPi_lbl_y = 35;
const uint16_t wPi_lbl_w = 30;
const uint16_t wPi_lbl_h = 20;

const uint16_t input_btn_x = 180;
const uint16_t input_btn_y = 35;
const uint16_t input_btn_w = 70;
const uint16_t input_btn_h = 20;

const uint16_t output_btn_x = 260;
const uint16_t output_btn_y = 35;
const uint16_t output_btn_w = 70;
const uint16_t output_btn_h = 20;

const uint16_t toggle_btn_x = 340;
const uint16_t toggle_btn_y = 35;
const uint16_t toggle_btn_w = 70;
const uint16_t toggle_btn_h = 20;

const uint16_t read_btn_x = 420;
const uint16_t read_btn_y = 35;
const uint16_t read_btn_w = 70;
const uint16_t read_btn_h = 20;

const uint16_t quit_btn_x = 230;
const uint16_t quit_btn_y = 610;
const uint16_t quit_btn_w = 70;
const uint16_t quit_btn_h = 20;

//---------------------------------------------------------------------
// Constructor
//---------------------------------------------------------------------
My_Window::My_Window()
		: Fl_Window(my_window_w,my_window_h,window_title)
	{
		try {
			wiringPiSetup();
		} catch (std::exception& e) {
			std::cerr << e.what();
			exit (1);
		}
		
		// Attach:
		{grpState = new Fl_Group(10,20,160,600,"State");
			
			lbl_wPi_0 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 0),
						wPi_lbl_w,wPi_lbl_h,"| wPi   0 | Pin 11 |");
			lbl_wPi_0->value(to_str(digitalRead(0)).c_str());
			
			lbl_wPi_1 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 1),
						wPi_lbl_w,wPi_lbl_h,"| wPi   1 | Pin 12 |");
			lbl_wPi_1->value(to_str(digitalRead(1)).c_str());
			
			lbl_wPi_2 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 2),
						wPi_lbl_w,wPi_lbl_h,"| wPi   2 | Pin 13 |");
			lbl_wPi_2->value(to_str(digitalRead(2)).c_str());
			
			lbl_wPi_3 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 3),
						wPi_lbl_w,wPi_lbl_h,"| wPi   3 | Pin 15 |");
			lbl_wPi_3->value(to_str(digitalRead(3)).c_str());
			
			lbl_wPi_4 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 4),
						wPi_lbl_w,wPi_lbl_h,"| wPi   4 | Pin 16 |");
			lbl_wPi_4->value(to_str(digitalRead(4)).c_str());
			
			lbl_wPi_5 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 5),
						wPi_lbl_w,wPi_lbl_h,"| wPi   5 | Pin 18 |");
			lbl_wPi_5->value(to_str(digitalRead(5)).c_str());
			
			lbl_wPi_6 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 6),
						wPi_lbl_w,wPi_lbl_h,"| wPi   6 | Pin 22 |");
			lbl_wPi_6->value(to_str(digitalRead(6)).c_str());
			
			lbl_wPi_7 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 7),
						wPi_lbl_w,wPi_lbl_h,"| wPi   7 | Pin   7 |");
			lbl_wPi_7->value(to_str(digitalRead(7)).c_str());
			
			lbl_wPi_8 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 8),
						wPi_lbl_w,wPi_lbl_h,"| wPi   8 | Pin   3 |");
			lbl_wPi_8->value(to_str(digitalRead(8)).c_str());
			
			lbl_wPi_9 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 9),
						wPi_lbl_w,wPi_lbl_h,"| wPi   9 | Pin   5 |");
			lbl_wPi_9->value(to_str(digitalRead(9)).c_str());
			
			lbl_wPi_10 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 10),
						wPi_lbl_w,wPi_lbl_h,"| wPi 10 | Pin 24 |");
			lbl_wPi_10->value(to_str(digitalRead(10)).c_str());
			
			lbl_wPi_11 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 11),
						wPi_lbl_w,wPi_lbl_h,"| wPi 11 | Pin 26 |");
			lbl_wPi_11->value(to_str(digitalRead(11)).c_str());
			
			lbl_wPi_12 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 12),
						wPi_lbl_w,wPi_lbl_h,"| wPi 12 | Pin 19 |");
			lbl_wPi_12->value(to_str(digitalRead(12)).c_str());
			
			lbl_wPi_13 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 13),
						wPi_lbl_w,wPi_lbl_h,"| wPi 13 | Pin 21 |");
			lbl_wPi_13->value(to_str(digitalRead(13)).c_str());
			
			lbl_wPi_14 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 14),
						wPi_lbl_w,wPi_lbl_h,"| wPi 14 | Pin 23 |");
			lbl_wPi_14->value(to_str(digitalRead(14)).c_str());
			
			lbl_wPi_15 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 15),
						wPi_lbl_w,wPi_lbl_h,"| wPi 15 | Pin   8 |");
			lbl_wPi_15->value(to_str(digitalRead(15)).c_str());
			
			lbl_wPi_16 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 16),
						wPi_lbl_w,wPi_lbl_h,"| wPi 16 | Pin 10 |");
			lbl_wPi_16->value(to_str(digitalRead(16)).c_str());
			
			lbl_wPi_21 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 17),
						wPi_lbl_w,wPi_lbl_h,"| wPi 21 | Pin 29 |");
			lbl_wPi_21->value(to_str(digitalRead(21)).c_str());
			
			lbl_wPi_22 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 18),
						wPi_lbl_w,wPi_lbl_h,"| wPi 22 | Pin 31 |");
			lbl_wPi_22->value(to_str(digitalRead(22)).c_str());
			
			lbl_wPi_23 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 19),
						wPi_lbl_w,wPi_lbl_h,"| wPi 23 | Pin 33 |");
			lbl_wPi_23->value(to_str(digitalRead(23)).c_str());
			
			lbl_wPi_24 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 20),
						wPi_lbl_w,wPi_lbl_h,"| wPi 24 | Pin 35 |");
			lbl_wPi_24->value(to_str(digitalRead(24)).c_str());
			
			lbl_wPi_25 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 21),
						wPi_lbl_w,wPi_lbl_h,"| wPi 25 | Pin 37 |");
			lbl_wPi_25->value(to_str(digitalRead(25)).c_str());
			
			lbl_wPi_26 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 22),
						wPi_lbl_w,wPi_lbl_h,"| wPi 26 | Pin 32 |");
			lbl_wPi_26->value(to_str(digitalRead(26)).c_str());
			
			lbl_wPi_27 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 23),
						wPi_lbl_w,wPi_lbl_h,"| wPi 27 | Pin 36 |");
			lbl_wPi_27->value(to_str(digitalRead(27)).c_str());
			
			lbl_wPi_28 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 24),
						wPi_lbl_w,wPi_lbl_h,"| wPi 28 | Pin 38 |");
			lbl_wPi_28->value(to_str(digitalRead(28)).c_str());
			
			lbl_wPi_29 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 25),
						wPi_lbl_w,wPi_lbl_h,"| wPi 29 | Pin 40 |");
			lbl_wPi_29->value(to_str(digitalRead(29)).c_str());
			
			lbl_wPi_30 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 26),
						wPi_lbl_w,wPi_lbl_h,"| wPi 30 | Pin 27 |");
			lbl_wPi_30->value(to_str(digitalRead(30)).c_str());
			
			lbl_wPi_31 = new Fl_Output(wPi_lbl_x,wPi_lbl_y + (wPi_lbl_h * 27),
						wPi_lbl_w,wPi_lbl_h,"| wPi 31 | Pin 28 |");
			lbl_wPi_31->value(to_str(digitalRead(31)).c_str());
			
		grpState->end();}
		
		{grpControl = new Fl_Group(180,20,320,600,"Control");
		
			// input
			btn_input_wPi_0 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 0),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_0->callback(cb_input_0,(void*)this);
			
			btn_input_wPi_1 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 1),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_1->callback(cb_input_1,(void*)this);
			
			btn_input_wPi_2 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 2),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_2->callback(cb_input_2,(void*)this);
			
			btn_input_wPi_3 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 3),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_3->callback(cb_input_3,(void*)this);
			
			btn_input_wPi_4 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 4),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_4->callback(cb_input_4,(void*)this);
			
			btn_input_wPi_5 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 5),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_5->callback(cb_input_5,(void*)this);
			
			btn_input_wPi_6 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 6),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_6->callback(cb_input_6,(void*)this);
			
			btn_input_wPi_7 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 7),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_7->callback(cb_input_7,(void*)this);
			
			btn_input_wPi_8 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 8),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_8->callback(cb_input_8,(void*)this);
			
			btn_input_wPi_9 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 9),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_9->callback(cb_input_9,(void*)this);
			
			btn_input_wPi_10 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 10),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_10->callback(cb_input_10,(void*)this);
			
			btn_input_wPi_11 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 11),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_11->callback(cb_input_11,(void*)this);
			
			btn_input_wPi_12 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 12),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_12->callback(cb_input_12,(void*)this);
			
			btn_input_wPi_13 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 13),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_13->callback(cb_input_13,(void*)this);
			
			btn_input_wPi_14 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 14),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_14->callback(cb_input_14,(void*)this);
			
			btn_input_wPi_15 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 15),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_15->callback(cb_input_15,(void*)this);
			
			btn_input_wPi_16 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 16),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_16->callback(cb_input_16,(void*)this);
			
			btn_input_wPi_21 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 17),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_21->callback(cb_input_21,(void*)this);
			
			btn_input_wPi_22 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 18),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_22->callback(cb_input_22,(void*)this);
			
			btn_input_wPi_23 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 19),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_23->callback(cb_input_23,(void*)this);
			
			btn_input_wPi_24 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 20),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_24->callback(cb_input_24,(void*)this);
			
			btn_input_wPi_25 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 21),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_25->callback(cb_input_25,(void*)this);
			
			btn_input_wPi_26 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 22),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_26->callback(cb_input_26,(void*)this);
			
			btn_input_wPi_27 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 23),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_27->callback(cb_input_27,(void*)this);
			
			btn_input_wPi_28 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 24),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_28->callback(cb_input_28,(void*)this);
			
			btn_input_wPi_29 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 25),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_29->callback(cb_input_29,(void*)this);
			
			btn_input_wPi_30 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 26),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_30->callback(cb_input_30,(void*)this);
			
			btn_input_wPi_31 = new Fl_Button(input_btn_x,input_btn_y + (input_btn_h * 27),
							input_btn_w,input_btn_h,input_btn_text);
			btn_input_wPi_31->callback(cb_input_31,(void*)this);
			
			// output
			btn_output_wPi_0 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 0),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_0->callback(cb_output_0,(void*)this);
			
			btn_output_wPi_1 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 1),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_1->callback(cb_output_1,(void*)this);
			
			btn_output_wPi_2 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 2),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_2->callback(cb_output_2,(void*)this);
			
			btn_output_wPi_3 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 3),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_3->callback(cb_output_3,(void*)this);
			
			btn_output_wPi_4 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 4),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_4->callback(cb_output_4,(void*)this);
			
			btn_output_wPi_5 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 5),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_5->callback(cb_output_5,(void*)this);
			
			btn_output_wPi_6 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 6),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_6->callback(cb_output_6,(void*)this);
			
			btn_output_wPi_7 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 7),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_7->callback(cb_output_7,(void*)this);
			
			btn_output_wPi_8 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 8),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_8->callback(cb_output_8,(void*)this);
			
			btn_output_wPi_9 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 9),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_9->callback(cb_output_9,(void*)this);
			
			btn_output_wPi_10 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 10),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_10->callback(cb_output_10,(void*)this);
			
			btn_output_wPi_11 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 11),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_11->callback(cb_output_11,(void*)this);
			
			btn_output_wPi_12 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 12),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_12->callback(cb_output_12,(void*)this);
			
			btn_output_wPi_13 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 13),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_13->callback(cb_output_13,(void*)this);
			
			btn_output_wPi_14 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 14),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_14->callback(cb_output_14,(void*)this);
			
			btn_output_wPi_15 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 15),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_15->callback(cb_output_15,(void*)this);
			
			btn_output_wPi_16 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 16),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_16->callback(cb_output_16,(void*)this);
			
			btn_output_wPi_21 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 17),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_21->callback(cb_output_21,(void*)this);
			
			btn_output_wPi_22 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 18),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_22->callback(cb_output_22,(void*)this);
			
			btn_output_wPi_23 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 19),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_23->callback(cb_output_23,(void*)this);
			
			btn_output_wPi_24 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 20),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_24->callback(cb_output_24,(void*)this);
			
			btn_output_wPi_25 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 21),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_25->callback(cb_output_25,(void*)this);
			
			btn_output_wPi_26 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 22),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_26->callback(cb_output_26,(void*)this);
			
			btn_output_wPi_27 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 23),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_27->callback(cb_output_27,(void*)this);
			
			btn_output_wPi_28 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 24),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_28->callback(cb_output_28,(void*)this);
			
			btn_output_wPi_29 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 25),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_29->callback(cb_output_29,(void*)this);
			
			btn_output_wPi_30 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 26),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_30->callback(cb_output_30,(void*)this);
			
			btn_output_wPi_31 = new Fl_Button(output_btn_x,output_btn_y + (output_btn_h * 27),
							output_btn_w,output_btn_h,output_btn_text);
			btn_output_wPi_31->callback(cb_output_31,(void*)this);
			
			// toggle
			btn_toggle_wPi_0 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 0),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_0->callback(cb_toggle_0,(void*)this);
			btn_toggle_wPi_0->deactivate();
			
			btn_toggle_wPi_1 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 1),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_1->callback(cb_toggle_1,(void*)this);
			btn_toggle_wPi_1->deactivate();
			
			btn_toggle_wPi_2 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 2),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_2->callback(cb_toggle_2,(void*)this);
			btn_toggle_wPi_2->deactivate();
			
			btn_toggle_wPi_3 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 3),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_3->callback(cb_toggle_3,(void*)this);
			btn_toggle_wPi_3->deactivate();
			
			btn_toggle_wPi_4 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 4),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_4->callback(cb_toggle_4,(void*)this);
			btn_toggle_wPi_4->deactivate();
			
			btn_toggle_wPi_5 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 5),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_5->callback(cb_toggle_5,(void*)this);
			btn_toggle_wPi_5->deactivate();
			
			btn_toggle_wPi_6 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 6),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_6->callback(cb_toggle_6,(void*)this);
			btn_toggle_wPi_6->deactivate();
			
			btn_toggle_wPi_7 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 7),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_7->callback(cb_toggle_7,(void*)this);
			btn_toggle_wPi_7->deactivate();
			
			btn_toggle_wPi_8 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 8),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_8->callback(cb_toggle_8,(void*)this);
			btn_toggle_wPi_8->deactivate();
			
			btn_toggle_wPi_9 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 9),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_9->callback(cb_toggle_9,(void*)this);
			btn_toggle_wPi_9->deactivate();
			
			btn_toggle_wPi_10 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 10),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_10->callback(cb_toggle_10,(void*)this);
			btn_toggle_wPi_10->deactivate();
			
			btn_toggle_wPi_11 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 11),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_11->callback(cb_toggle_11,(void*)this);
			btn_toggle_wPi_11->deactivate();
			
			btn_toggle_wPi_12 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 12),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_12->callback(cb_toggle_12,(void*)this);
			btn_toggle_wPi_12->deactivate();
			
			btn_toggle_wPi_13 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 13),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_13->callback(cb_toggle_13,(void*)this);
			btn_toggle_wPi_13->deactivate();
			
			btn_toggle_wPi_14 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 14),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_14->callback(cb_toggle_14,(void*)this);
			btn_toggle_wPi_14->deactivate();
			
			btn_toggle_wPi_15 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 15),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_15->callback(cb_toggle_15,(void*)this);
			btn_toggle_wPi_15->deactivate();
			
			btn_toggle_wPi_16 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 16),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_16->callback(cb_toggle_16,(void*)this);
			btn_toggle_wPi_16->deactivate();
			
			btn_toggle_wPi_21 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 17),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_21->callback(cb_toggle_21,(void*)this);
			btn_toggle_wPi_21->deactivate();
			
			btn_toggle_wPi_22 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 18),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_22->callback(cb_toggle_22,(void*)this);
			btn_toggle_wPi_22->deactivate();
			
			btn_toggle_wPi_23 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 19),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_23->callback(cb_toggle_23,(void*)this);
			btn_toggle_wPi_23->deactivate();
			
			btn_toggle_wPi_24 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 20),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_24->callback(cb_toggle_24,(void*)this);
			btn_toggle_wPi_24->deactivate();
			
			btn_toggle_wPi_25 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 21),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_25->callback(cb_toggle_25,(void*)this);
			btn_toggle_wPi_25->deactivate();
			
			btn_toggle_wPi_26 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 22),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_26->callback(cb_toggle_26,(void*)this);
			btn_toggle_wPi_26->deactivate();
			
			btn_toggle_wPi_27 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 23),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_27->callback(cb_toggle_27,(void*)this);
			btn_toggle_wPi_27->deactivate();
			
			btn_toggle_wPi_28 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 24),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_28->callback(cb_toggle_28,(void*)this);
			btn_toggle_wPi_28->deactivate();
			
			btn_toggle_wPi_29 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 25),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_29->callback(cb_toggle_29,(void*)this);
			btn_toggle_wPi_29->deactivate();
			
			btn_toggle_wPi_30 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 26),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_30->callback(cb_toggle_30,(void*)this);
			btn_toggle_wPi_30->deactivate();
			
			btn_toggle_wPi_31 = new Fl_Button(toggle_btn_x,toggle_btn_y + (toggle_btn_h * 27),
							toggle_btn_w,toggle_btn_h,toggle_btn_text);
			btn_toggle_wPi_31->callback(cb_toggle_31,(void*)this);
			btn_toggle_wPi_31->deactivate();
			
			// read
			btn_read_wPi_0 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 0),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_0->callback(cb_read_0,(void*)this);
			
			btn_read_wPi_1 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 1),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_1->callback(cb_read_1,(void*)this);
			
			btn_read_wPi_2 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 2),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_2->callback(cb_read_2,(void*)this);
			
			btn_read_wPi_3 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 3),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_3->callback(cb_read_3,(void*)this);
			
			btn_read_wPi_4 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 4),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_4->callback(cb_read_4,(void*)this);
			
			btn_read_wPi_5 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 5),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_5->callback(cb_read_5,(void*)this);
			
			btn_read_wPi_6 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 6),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_6->callback(cb_read_6,(void*)this);
			
			btn_read_wPi_7 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 7),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_7->callback(cb_read_7,(void*)this);
			
			btn_read_wPi_8 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 8),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_8->callback(cb_read_8,(void*)this);
			
			btn_read_wPi_9 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 9),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_9->callback(cb_read_9,(void*)this);
			
			btn_read_wPi_10 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 10),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_10->callback(cb_read_10,(void*)this);
			
			btn_read_wPi_11 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 11),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_11->callback(cb_read_11,(void*)this);
			
			btn_read_wPi_12 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 12),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_12->callback(cb_read_12,(void*)this);
			
			btn_read_wPi_13 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 13),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_13->callback(cb_read_13,(void*)this);
			
			btn_read_wPi_14 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 14),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_14->callback(cb_read_14,(void*)this);
			
			btn_read_wPi_15 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 15),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_15->callback(cb_read_15,(void*)this);
			
			btn_read_wPi_16 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 16),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_16->callback(cb_read_16,(void*)this);
			
			btn_read_wPi_21 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 17),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_21->callback(cb_read_21,(void*)this);
			
			btn_read_wPi_22 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 18),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_22->callback(cb_read_22,(void*)this);
			
			btn_read_wPi_23 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 19),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_23->callback(cb_read_23,(void*)this);
			
			btn_read_wPi_24 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 20),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_24->callback(cb_read_24,(void*)this);
			
			btn_read_wPi_25 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 21),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_25->callback(cb_read_25,(void*)this);
			
			btn_read_wPi_26 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 22),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_26->callback(cb_read_26,(void*)this);
			
			btn_read_wPi_27 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 23),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_27->callback(cb_read_27,(void*)this);
			
			btn_read_wPi_28 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 24),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_28->callback(cb_read_28,(void*)this);
			
			btn_read_wPi_29 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 25),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_29->callback(cb_read_29,(void*)this);
			
			btn_read_wPi_30 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 26),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_30->callback(cb_read_30,(void*)this);
			
			btn_read_wPi_31 = new Fl_Button(read_btn_x,read_btn_y + (read_btn_h * 27),
							read_btn_w,read_btn_h,read_btn_text);
			btn_read_wPi_31->callback(cb_read_31,(void*)this);
		
		grpControl->end();}
		
		btn_quit = new Fl_Button(quit_btn_x,quit_btn_y,quit_btn_w,quit_btn_h,quit_btn_text);
		btn_quit->callback(cb_quit,(void*)this);
	}

//---------------------------------------------------------------------
// Input
//---------------------------------------------------------------------
void My_Window::wPi_0_input(Fl_Widget* w) {
	pinMode(0,INPUT);
	
	w->deactivate();
	btn_output_wPi_0->activate();
	btn_toggle_wPi_0->deactivate();
	
	usleep(time_us);
	wPi_0_read(w);
}

void My_Window::cb_input_0(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_0_input(w);
}

void My_Window::wPi_1_input(Fl_Widget* w) {
	pinMode(1,INPUT);
	
	w->deactivate();
	btn_output_wPi_1->activate();
	btn_toggle_wPi_1->deactivate();
	
	usleep(time_us);
	wPi_1_read(w);
}

void My_Window::cb_input_1(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_1_input(w);
}

void My_Window::wPi_2_input(Fl_Widget* w) {
	pinMode(2,INPUT);
	
	w->deactivate();
	btn_output_wPi_2->activate();
	btn_toggle_wPi_2->deactivate();
	
	usleep(time_us);
	wPi_2_read(w);
}

void My_Window::cb_input_2(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_2_input(w);
}

void My_Window::wPi_3_input(Fl_Widget* w) {
	pinMode(3,INPUT);
	
	w->deactivate();
	btn_output_wPi_3->activate();
	btn_toggle_wPi_3->deactivate();
	
	usleep(time_us);
	wPi_3_read(w);
}

void My_Window::cb_input_3(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_3_input(w);
}

void My_Window::wPi_4_input(Fl_Widget* w) {
	pinMode(4,INPUT);
	
	w->deactivate();
	btn_output_wPi_4->activate();
	btn_toggle_wPi_4->deactivate();
	
	usleep(time_us);
	wPi_4_read(w);
}

void My_Window::cb_input_4(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_4_input(w);
}

void My_Window::wPi_5_input(Fl_Widget* w) {
	pinMode(5,INPUT);
	
	w->deactivate();
	btn_output_wPi_5->activate();
	btn_toggle_wPi_5->deactivate();
	
	usleep(time_us);
	wPi_5_read(w);
}

void My_Window::cb_input_5(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_5_input(w);
}

void My_Window::wPi_6_input(Fl_Widget* w) {
	pinMode(6,INPUT);
	
	w->deactivate();
	btn_output_wPi_6->activate();
	btn_toggle_wPi_6->deactivate();
	
	usleep(time_us);
	wPi_6_read(w);
}

void My_Window::cb_input_6(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_6_input(w);
}

void My_Window::wPi_7_input(Fl_Widget* w) {
	pinMode(7,INPUT);
	
	w->deactivate();
	btn_output_wPi_7->activate();
	btn_toggle_wPi_7->deactivate();
	
	usleep(time_us);
	wPi_7_read(w);
}

void My_Window::cb_input_7(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_7_input(w);
}

void My_Window::wPi_8_input(Fl_Widget* w) {
	pinMode(8,INPUT);
	
	w->deactivate();
	btn_output_wPi_8->activate();
	btn_toggle_wPi_8->deactivate();
	
	usleep(time_us);
	wPi_8_read(w);
}

void My_Window::cb_input_8(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_8_input(w);
}

void My_Window::wPi_9_input(Fl_Widget* w) {
	pinMode(9,INPUT);
	
	w->deactivate();
	btn_output_wPi_9->activate();
	btn_toggle_wPi_9->deactivate();
	
	usleep(time_us);
	wPi_9_read(w);
}

void My_Window::cb_input_9(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_9_input(w);
}

void My_Window::wPi_10_input(Fl_Widget* w) {
	pinMode(10,INPUT);
	
	w->deactivate();
	btn_output_wPi_10->activate();
	btn_toggle_wPi_10->deactivate();
	
	usleep(time_us);
	wPi_10_read(w);
}

void My_Window::cb_input_10(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_10_input(w);
}

void My_Window::wPi_11_input(Fl_Widget* w) {
	pinMode(11,INPUT);
	
	w->deactivate();
	btn_output_wPi_11->activate();
	btn_toggle_wPi_11->deactivate();
	
	usleep(time_us);
	wPi_11_read(w);
}

void My_Window::cb_input_11(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_11_input(w);
}

void My_Window::wPi_12_input(Fl_Widget* w) {
	pinMode(12,INPUT);
	
	w->deactivate();
	btn_output_wPi_12->activate();
	btn_toggle_wPi_12->deactivate();
	
	usleep(time_us);
	wPi_12_read(w);
}

void My_Window::cb_input_12(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_12_input(w);
}

void My_Window::wPi_13_input(Fl_Widget* w) {
	pinMode(13,INPUT);
	
	w->deactivate();
	btn_output_wPi_13->activate();
	btn_toggle_wPi_13->deactivate();
	
	usleep(time_us);
	wPi_13_read(w);
}

void My_Window::cb_input_13(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_13_input(w);
}

void My_Window::wPi_14_input(Fl_Widget* w) {
	pinMode(14,INPUT);
	
	w->deactivate();
	btn_output_wPi_14->activate();
	btn_toggle_wPi_14->deactivate();
	
	usleep(time_us);
	wPi_14_read(w);
}

void My_Window::cb_input_14(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_14_input(w);
}

void My_Window::wPi_15_input(Fl_Widget* w) {
	pinMode(15,INPUT);
	
	w->deactivate();
	btn_output_wPi_15->activate();
	btn_toggle_wPi_15->deactivate();
	
	usleep(time_us);
	wPi_15_read(w);
}

void My_Window::cb_input_15(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_15_input(w);
}

void My_Window::wPi_16_input(Fl_Widget* w) {
	pinMode(16,INPUT);
	
	w->deactivate();
	btn_output_wPi_16->activate();
	btn_toggle_wPi_16->deactivate();
	
	usleep(time_us);
	wPi_16_read(w);
}

void My_Window::cb_input_16(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_16_input(w);
}

void My_Window::wPi_21_input(Fl_Widget* w) {
	pinMode(21,INPUT);
	
	w->deactivate();
	btn_output_wPi_21->activate();
	btn_toggle_wPi_21->deactivate();
	
	usleep(time_us);
	wPi_21_read(w);
}

void My_Window::cb_input_21(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_21_input(w);
}

void My_Window::wPi_22_input(Fl_Widget* w) {
	pinMode(22,INPUT);
	
	w->deactivate();
	btn_output_wPi_22->activate();
	btn_toggle_wPi_22->deactivate();
	
	usleep(time_us);
	wPi_22_read(w);
}

void My_Window::cb_input_22(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_22_input(w);
}

void My_Window::wPi_23_input(Fl_Widget* w) {
	pinMode(23,INPUT);
	
	w->deactivate();
	btn_output_wPi_23->activate();
	btn_toggle_wPi_23->deactivate();
	
	usleep(time_us);
	wPi_23_read(w);
}

void My_Window::cb_input_23(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_23_input(w);
}

void My_Window::wPi_24_input(Fl_Widget* w) {
	pinMode(24,INPUT);
	
	w->deactivate();
	btn_output_wPi_24->activate();
	btn_toggle_wPi_24->deactivate();
	
	usleep(time_us);
	wPi_24_read(w);
}

void My_Window::cb_input_24(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_24_input(w);
}

void My_Window::wPi_25_input(Fl_Widget* w) {
	pinMode(25,INPUT);
	
	w->deactivate();
	btn_output_wPi_25->activate();
	btn_toggle_wPi_25->deactivate();
	
	usleep(time_us);
	wPi_25_read(w);
}

void My_Window::cb_input_25(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_25_input(w);
}

void My_Window::wPi_26_input(Fl_Widget* w) {
	pinMode(26,INPUT);
	
	w->deactivate();
	btn_output_wPi_26->activate();
	btn_toggle_wPi_26->deactivate();
	
	usleep(time_us);
	wPi_26_read(w);
}

void My_Window::cb_input_26(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_26_input(w);
}

void My_Window::wPi_27_input(Fl_Widget* w) {
	pinMode(27,INPUT);
	
	w->deactivate();
	btn_output_wPi_27->activate();
	btn_toggle_wPi_27->deactivate();
	
	usleep(time_us);
	wPi_27_read(w);
}

void My_Window::cb_input_27(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_27_input(w);
}

void My_Window::wPi_28_input(Fl_Widget* w) {
	pinMode(28,INPUT);
	
	w->deactivate();
	btn_output_wPi_28->activate();
	btn_toggle_wPi_28->deactivate();
	
	usleep(time_us);
	wPi_28_read(w);
}

void My_Window::cb_input_28(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_28_input(w);
}

void My_Window::wPi_29_input(Fl_Widget* w) {
	pinMode(29,INPUT);
	
	w->deactivate();
	btn_output_wPi_29->activate();
	btn_toggle_wPi_29->deactivate();
	
	usleep(time_us);
	wPi_29_read(w);
}

void My_Window::cb_input_29(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_29_input(w);
}

void My_Window::wPi_30_input(Fl_Widget* w) {
	pinMode(30,INPUT);
	
	w->deactivate();
	btn_output_wPi_30->activate();
	btn_toggle_wPi_30->deactivate();
	
	usleep(time_us);
	wPi_30_read(w);
}

void My_Window::cb_input_30(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_30_input(w);
}

void My_Window::wPi_31_input(Fl_Widget* w) {
	pinMode(31,INPUT);
	
	w->deactivate();
	btn_output_wPi_31->activate();
	btn_toggle_wPi_31->deactivate();
	
	usleep(time_us);
	wPi_31_read(w);
}

void My_Window::cb_input_31(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_31_input(w);
}

//---------------------------------------------------------------------
// Output
//---------------------------------------------------------------------
void My_Window::wPi_0_output(Fl_Widget* w) {
	pinMode(0,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_0->activate();
	btn_toggle_wPi_0->activate();
	
	usleep(time_us);
	wPi_0_read(w);
}

void My_Window::cb_output_0(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_0_output(w);
}

void My_Window::wPi_1_output(Fl_Widget* w) {
	pinMode(1,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_1->activate();
	btn_toggle_wPi_1->activate();
	
	usleep(time_us);
	wPi_1_read(w);
}

void My_Window::cb_output_1(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_1_output(w);
}

void My_Window::wPi_2_output(Fl_Widget* w) {
	pinMode(2,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_2->activate();
	btn_toggle_wPi_2->activate();
	
	usleep(time_us);
	wPi_2_read(w);
}

void My_Window::cb_output_2(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_2_output(w);
}

void My_Window::wPi_3_output(Fl_Widget* w) {
	pinMode(3,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_3->activate();
	btn_toggle_wPi_3->activate();
	
	usleep(time_us);
	wPi_3_read(w);
}

void My_Window::cb_output_3(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_3_output(w);
}

void My_Window::wPi_4_output(Fl_Widget* w) {
	pinMode(4,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_4->activate();
	btn_toggle_wPi_4->activate();
	
	usleep(time_us);
	wPi_4_read(w);
}

void My_Window::cb_output_4(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_4_output(w);
}

void My_Window::wPi_5_output(Fl_Widget* w) {
	pinMode(5,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_5->activate();
	btn_toggle_wPi_5->activate();
	
	usleep(time_us);
	wPi_5_read(w);
}

void My_Window::cb_output_5(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_5_output(w);
}

void My_Window::wPi_6_output(Fl_Widget* w) {
	pinMode(6,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_6->activate();
	btn_toggle_wPi_6->activate();
	
	usleep(time_us);
	wPi_6_read(w);
}

void My_Window::cb_output_6(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_6_output(w);
}

void My_Window::wPi_7_output(Fl_Widget* w) {
	pinMode(7,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_7->activate();
	btn_toggle_wPi_7->activate();
	
	usleep(time_us);
	wPi_7_read(w);
}

void My_Window::cb_output_7(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_7_output(w);
}

void My_Window::wPi_8_output(Fl_Widget* w) {
	pinMode(8,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_8->activate();
	btn_toggle_wPi_8->activate();
	
	usleep(time_us);
	wPi_8_read(w);
}

void My_Window::cb_output_8(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_8_output(w);
}

void My_Window::wPi_9_output(Fl_Widget* w) {
	pinMode(9,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_9->activate();
	btn_toggle_wPi_9->activate();
	
	usleep(time_us);
	wPi_9_read(w);
}

void My_Window::cb_output_9(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_9_output(w);
}

void My_Window::wPi_10_output(Fl_Widget* w) {
	pinMode(10,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_10->activate();
	btn_toggle_wPi_10->activate();
	
	usleep(time_us);
	wPi_10_read(w);
}

void My_Window::cb_output_10(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_10_output(w);
}

void My_Window::wPi_11_output(Fl_Widget* w) {
	pinMode(11,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_11->activate();
	btn_toggle_wPi_11->activate();
	
	usleep(time_us);
	wPi_11_read(w);
}

void My_Window::cb_output_11(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_11_output(w);
}

void My_Window::wPi_12_output(Fl_Widget* w) {
	pinMode(12,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_12->activate();
	btn_toggle_wPi_12->activate();
	
	usleep(time_us);
	wPi_12_read(w);
}

void My_Window::cb_output_12(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_12_output(w);
}

void My_Window::wPi_13_output(Fl_Widget* w) {
	pinMode(13,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_13->activate();
	btn_toggle_wPi_13->activate();
	
	usleep(time_us);
	wPi_13_read(w);
}

void My_Window::cb_output_13(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_13_output(w);
}

void My_Window::wPi_14_output(Fl_Widget* w) {
	pinMode(14,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_14->activate();
	btn_toggle_wPi_14->activate();
	
	usleep(time_us);
	wPi_14_read(w);
}

void My_Window::cb_output_14(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_14_output(w);
}

void My_Window::wPi_15_output(Fl_Widget* w) {
	pinMode(15,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_15->activate();
	btn_toggle_wPi_15->activate();
	
	usleep(time_us);
	wPi_15_read(w);
}

void My_Window::cb_output_15(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_15_output(w);
}

void My_Window::wPi_16_output(Fl_Widget* w) {
	pinMode(16,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_16->activate();
	btn_toggle_wPi_16->activate();
	
	usleep(time_us);
	wPi_16_read(w);
}

void My_Window::cb_output_16(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_16_output(w);
}

void My_Window::wPi_21_output(Fl_Widget* w) {
	pinMode(21,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_21->activate();
	btn_toggle_wPi_21->activate();
	
	usleep(time_us);
	wPi_21_read(w);
}

void My_Window::cb_output_21(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_21_output(w);
}

void My_Window::wPi_22_output(Fl_Widget* w) {
	pinMode(22,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_22->activate();
	btn_toggle_wPi_22->activate();
	
	usleep(time_us);
	wPi_22_read(w);
}

void My_Window::cb_output_22(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_22_output(w);
}

void My_Window::wPi_23_output(Fl_Widget* w) {
	pinMode(23,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_23->activate();
	btn_toggle_wPi_23->activate();
	
	usleep(time_us);
	wPi_23_read(w);
}

void My_Window::cb_output_23(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_23_output(w);
}

void My_Window::wPi_24_output(Fl_Widget* w) {
	pinMode(24,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_24->activate();
	btn_toggle_wPi_24->activate();
	
	usleep(time_us);
	wPi_24_read(w);
}

void My_Window::cb_output_24(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_24_output(w);
}

void My_Window::wPi_25_output(Fl_Widget* w) {
	pinMode(25,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_25->activate();
	btn_toggle_wPi_25->activate();
	
	usleep(time_us);
	wPi_25_read(w);
}

void My_Window::cb_output_25(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_25_output(w);
}

void My_Window::wPi_26_output(Fl_Widget* w) {
	pinMode(26,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_26->activate();
	btn_toggle_wPi_26->activate();
	
	usleep(time_us);
	wPi_26_read(w);
}

void My_Window::cb_output_26(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_26_output(w);
}

void My_Window::wPi_27_output(Fl_Widget* w) {
	pinMode(27,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_27->activate();
	btn_toggle_wPi_27->activate();
	
	usleep(time_us);
	wPi_27_read(w);
}

void My_Window::cb_output_27(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_27_output(w);
}

void My_Window::wPi_28_output(Fl_Widget* w) {
	pinMode(28,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_28->activate();
	btn_toggle_wPi_28->activate();
	
	usleep(time_us);
	wPi_28_read(w);
}

void My_Window::cb_output_28(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_28_output(w);
}

void My_Window::wPi_29_output(Fl_Widget* w) {
	pinMode(29,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_29->activate();
	btn_toggle_wPi_29->activate();
	
	usleep(time_us);
	wPi_29_read(w);
}

void My_Window::cb_output_29(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_29_output(w);
}

void My_Window::wPi_30_output(Fl_Widget* w) {
	pinMode(30,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_30->activate();
	btn_toggle_wPi_30->activate();
	
	usleep(time_us);
	wPi_30_read(w);
}

void My_Window::cb_output_30(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_30_output(w);
}

void My_Window::wPi_31_output(Fl_Widget* w) {
	pinMode(31,OUTPUT);
	
	w->deactivate();
	btn_input_wPi_31->activate();
	btn_toggle_wPi_31->activate();
	
	usleep(time_us);
	wPi_31_read(w);
}

void My_Window::cb_output_31(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_31_output(w);
}

//---------------------------------------------------------------------
// Toggle
//---------------------------------------------------------------------
void My_Window::wPi_0_toggle(Fl_Widget* w) {
	if (digitalRead(0)) {
		digitalWrite(0,LOW);
	}
	else {
		digitalWrite(0,HIGH);
	}
	
	usleep(time_us);
	wPi_0_read(w);
}

void My_Window::cb_toggle_0(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_0_toggle(w);
}

void My_Window::wPi_1_toggle(Fl_Widget* w) {
	if (digitalRead(1)) {
		digitalWrite(1,LOW);
	}
	else {
		digitalWrite(1,HIGH);
	}
	
	usleep(time_us);
	wPi_1_read(w);
}

void My_Window::cb_toggle_1(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_1_toggle(w);
}

void My_Window::wPi_2_toggle(Fl_Widget* w) {
	if (digitalRead(2)) {
		digitalWrite(2,LOW);
	}
	else {
		digitalWrite(2,HIGH);
	}
	
	usleep(time_us);
	wPi_2_read(w);
}

void My_Window::cb_toggle_2(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_2_toggle(w);
}

void My_Window::wPi_3_toggle(Fl_Widget* w) {
	if (digitalRead(3)) {
		digitalWrite(3,LOW);
	}
	else {
		digitalWrite(3,HIGH);
	}
	
	usleep(time_us);
	wPi_3_read(w);
}

void My_Window::cb_toggle_3(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_3_toggle(w);
}

void My_Window::wPi_4_toggle(Fl_Widget* w) {
	if (digitalRead(4)) {
		digitalWrite(4,LOW);
	}
	else {
		digitalWrite(4,HIGH);
	}
	
	usleep(time_us);
	wPi_4_read(w);
}

void My_Window::cb_toggle_4(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_4_toggle(w);
}

void My_Window::wPi_5_toggle(Fl_Widget* w) {
	if (digitalRead(5)) {
		digitalWrite(5,LOW);
	}
	else {
		digitalWrite(5,HIGH);
	}
	
	usleep(time_us);
	wPi_5_read(w);
}

void My_Window::cb_toggle_5(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_5_toggle(w);
}

void My_Window::wPi_6_toggle(Fl_Widget* w) {
	if (digitalRead(6)) {
		digitalWrite(6,LOW);
	}
	else {
		digitalWrite(6,HIGH);
	}
	
	usleep(time_us);
	wPi_6_read(w);
}

void My_Window::cb_toggle_6(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_6_toggle(w);
}

void My_Window::wPi_7_toggle(Fl_Widget* w) {
	if (digitalRead(7)) {
		digitalWrite(7,LOW);
	}
	else {
		digitalWrite(7,HIGH);
	}
	
	usleep(time_us);
	wPi_7_read(w);
}

void My_Window::cb_toggle_7(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_7_toggle(w);
}

void My_Window::wPi_8_toggle(Fl_Widget* w) {
	if (digitalRead(8)) {
		digitalWrite(8,LOW);
	}
	else {
		digitalWrite(8,HIGH);
	}
	
	usleep(time_us);
	wPi_8_read(w);
}

void My_Window::cb_toggle_8(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_8_toggle(w);
}

void My_Window::wPi_9_toggle(Fl_Widget* w) {
	if (digitalRead(9)) {
		digitalWrite(9,LOW);
	}
	else {
		digitalWrite(9,HIGH);
	}
	
	usleep(time_us);
	wPi_9_read(w);
}

void My_Window::cb_toggle_9(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_9_toggle(w);
}

void My_Window::wPi_10_toggle(Fl_Widget* w) {
	if (digitalRead(10)) {
		digitalWrite(10,LOW);
	}
	else {
		digitalWrite(10,HIGH);
	}
	
	usleep(time_us);
	wPi_10_read(w);
}

void My_Window::cb_toggle_10(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_10_toggle(w);
}

void My_Window::wPi_11_toggle(Fl_Widget* w) {
	if (digitalRead(11)) {
		digitalWrite(11,LOW);
	}
	else {
		digitalWrite(11,HIGH);
	}
	
	usleep(time_us);
	wPi_11_read(w);
}

void My_Window::cb_toggle_11(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_11_toggle(w);
}

void My_Window::wPi_12_toggle(Fl_Widget* w) {
	if (digitalRead(12)) {
		digitalWrite(12,LOW);
	}
	else {
		digitalWrite(12,HIGH);
	}
	
	usleep(time_us);
	wPi_12_read(w);
}

void My_Window::cb_toggle_12(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_12_toggle(w);
}

void My_Window::wPi_13_toggle(Fl_Widget* w) {
	if (digitalRead(13)) {
		digitalWrite(13,LOW);
	}
	else {
		digitalWrite(13,HIGH);
	}
	
	usleep(time_us);
	wPi_13_read(w);
}

void My_Window::cb_toggle_13(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_13_toggle(w);
}

void My_Window::wPi_14_toggle(Fl_Widget* w) {
	if (digitalRead(14)) {
		digitalWrite(14,LOW);
	}
	else {
		digitalWrite(14,HIGH);
	}
	
	usleep(time_us);
	wPi_14_read(w);
}

void My_Window::cb_toggle_14(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_14_toggle(w);
}

void My_Window::wPi_15_toggle(Fl_Widget* w) {
	if (digitalRead(15)) {
		digitalWrite(15,LOW);
	}
	else {
		digitalWrite(15,HIGH);
	}
	
	usleep(time_us);
	wPi_15_read(w);
}

void My_Window::cb_toggle_15(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_15_toggle(w);
}

void My_Window::wPi_16_toggle(Fl_Widget* w) {
	if (digitalRead(16)) {
		digitalWrite(16,LOW);
	}
	else {
		digitalWrite(16,HIGH);
	}
	
	usleep(time_us);
	wPi_16_read(w);
}

void My_Window::cb_toggle_16(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_16_toggle(w);
}

void My_Window::wPi_21_toggle(Fl_Widget* w) {
	if (digitalRead(21)) {
		digitalWrite(21,LOW);
	}
	else {
		digitalWrite(21,HIGH);
	}
	
	usleep(time_us);
	wPi_21_read(w);
}

void My_Window::cb_toggle_21(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_21_toggle(w);
}

void My_Window::wPi_22_toggle(Fl_Widget* w) {
	if (digitalRead(22)) {
		digitalWrite(22,LOW);
	}
	else {
		digitalWrite(22,HIGH);
	}
	
	usleep(time_us);
	wPi_22_read(w);
}

void My_Window::cb_toggle_22(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_22_toggle(w);
}

void My_Window::wPi_23_toggle(Fl_Widget* w) {
	if (digitalRead(23)) {
		digitalWrite(23,LOW);
	}
	else {
		digitalWrite(23,HIGH);
	}
	
	usleep(time_us);
	wPi_23_read(w);
}

void My_Window::cb_toggle_23(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_23_toggle(w);
}

void My_Window::wPi_24_toggle(Fl_Widget* w) {
	if (digitalRead(24)) {
		digitalWrite(24,LOW);
	}
	else {
		digitalWrite(24,HIGH);
	}
	
	usleep(time_us);
	wPi_24_read(w);
}

void My_Window::cb_toggle_24(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_24_toggle(w);
}

void My_Window::wPi_25_toggle(Fl_Widget* w) {
	if (digitalRead(25)) {
		digitalWrite(25,LOW);
	}
	else {
		digitalWrite(25,HIGH);
	}
	
	usleep(time_us);
	wPi_25_read(w);
}

void My_Window::cb_toggle_25(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_25_toggle(w);
}

void My_Window::wPi_26_toggle(Fl_Widget* w) {
	if (digitalRead(26)) {
		digitalWrite(26,LOW);
	}
	else {
		digitalWrite(26,HIGH);
	}
	
	usleep(time_us);
	wPi_26_read(w);
}

void My_Window::cb_toggle_26(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_26_toggle(w);
}

void My_Window::wPi_27_toggle(Fl_Widget* w) {
	if (digitalRead(27)) {
		digitalWrite(27,LOW);
	}
	else {
		digitalWrite(27,HIGH);
	}
	
	usleep(time_us);
	wPi_27_read(w);
}

void My_Window::cb_toggle_27(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_27_toggle(w);
}

void My_Window::wPi_28_toggle(Fl_Widget* w) {
	if (digitalRead(28)) {
		digitalWrite(28,LOW);
	}
	else {
		digitalWrite(28,HIGH);
	}
	
	usleep(time_us);
	wPi_28_read(w);
}

void My_Window::cb_toggle_28(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_28_toggle(w);
}

void My_Window::wPi_29_toggle(Fl_Widget* w) {
	if (digitalRead(29)) {
		digitalWrite(29,LOW);
	}
	else {
		digitalWrite(29,HIGH);
	}
	
	usleep(time_us);
	wPi_29_read(w);
}

void My_Window::cb_toggle_29(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_29_toggle(w);
}

void My_Window::wPi_30_toggle(Fl_Widget* w) {
	if (digitalRead(30)) {
		digitalWrite(30,LOW);
	}
	else {
		digitalWrite(30,HIGH);
	}
	
	usleep(time_us);
	wPi_30_read(w);
}

void My_Window::cb_toggle_30(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_30_toggle(w);
}

void My_Window::wPi_31_toggle(Fl_Widget* w) {
	if (digitalRead(31)) {
		digitalWrite(31,LOW);
	}
	else {
		digitalWrite(31,HIGH);
	}
	
	usleep(time_us);
	wPi_31_read(w);
}

void My_Window::cb_toggle_31(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_31_toggle(w);
}

//---------------------------------------------------------------------
// Read
//---------------------------------------------------------------------
void My_Window::wPi_0_read(Fl_Widget* w) {
	lbl_wPi_0->value(to_str(digitalRead(0)).c_str());
}

void My_Window::cb_read_0(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_0_read(w);
}

void My_Window::wPi_1_read(Fl_Widget* w) {
	lbl_wPi_1->value(to_str(digitalRead(1)).c_str());
}

void My_Window::cb_read_1(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_1_read(w);
}

void My_Window::wPi_2_read(Fl_Widget* w) {
	lbl_wPi_2->value(to_str(digitalRead(2)).c_str());
}

void My_Window::cb_read_2(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_2_read(w);
}

void My_Window::wPi_3_read(Fl_Widget* w) {
	lbl_wPi_3->value(to_str(digitalRead(3)).c_str());
}

void My_Window::cb_read_3(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_3_read(w);
}

void My_Window::wPi_4_read(Fl_Widget* w) {
	lbl_wPi_4->value(to_str(digitalRead(4)).c_str());
}

void My_Window::cb_read_4(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_4_read(w);
}

void My_Window::wPi_5_read(Fl_Widget* w) {
	lbl_wPi_5->value(to_str(digitalRead(5)).c_str());
}

void My_Window::cb_read_5(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_5_read(w);
}

void My_Window::wPi_6_read(Fl_Widget* w) {
	lbl_wPi_6->value(to_str(digitalRead(6)).c_str());
}

void My_Window::cb_read_6(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_6_read(w);
}

void My_Window::wPi_7_read(Fl_Widget* w) {
	lbl_wPi_7->value(to_str(digitalRead(7)).c_str());
}

void My_Window::cb_read_7(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_7_read(w);
}

void My_Window::wPi_8_read(Fl_Widget* w) {
	lbl_wPi_8->value(to_str(digitalRead(8)).c_str());
}

void My_Window::cb_read_8(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_8_read(w);
}

void My_Window::wPi_9_read(Fl_Widget* w) {
	lbl_wPi_9->value(to_str(digitalRead(9)).c_str());
}

void My_Window::cb_read_9(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_9_read(w);
}

void My_Window::wPi_10_read(Fl_Widget* w) {
	lbl_wPi_10->value(to_str(digitalRead(10)).c_str());
}

void My_Window::cb_read_10(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_10_read(w);
}

void My_Window::wPi_11_read(Fl_Widget* w) {
	lbl_wPi_11->value(to_str(digitalRead(11)).c_str());
}

void My_Window::cb_read_11(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_11_read(w);
}

void My_Window::wPi_12_read(Fl_Widget* w) {
	lbl_wPi_12->value(to_str(digitalRead(12)).c_str());
}

void My_Window::cb_read_12(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_12_read(w);
}

void My_Window::wPi_13_read(Fl_Widget* w) {
	lbl_wPi_13->value(to_str(digitalRead(13)).c_str());
}

void My_Window::cb_read_13(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_13_read(w);
}

void My_Window::wPi_14_read(Fl_Widget* w) {
	lbl_wPi_14->value(to_str(digitalRead(14)).c_str());
}

void My_Window::cb_read_14(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_14_read(w);
}

void My_Window::wPi_15_read(Fl_Widget* w) {
	lbl_wPi_15->value(to_str(digitalRead(15)).c_str());
}

void My_Window::cb_read_15(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_15_read(w);
}

void My_Window::wPi_16_read(Fl_Widget* w) {
	lbl_wPi_16->value(to_str(digitalRead(16)).c_str());
}

void My_Window::cb_read_16(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_16_read(w);
}

void My_Window::wPi_21_read(Fl_Widget* w) {
	lbl_wPi_21->value(to_str(digitalRead(21)).c_str());
}

void My_Window::cb_read_21(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_21_read(w);
}

void My_Window::wPi_22_read(Fl_Widget* w) {
	lbl_wPi_22->value(to_str(digitalRead(22)).c_str());
}

void My_Window::cb_read_22(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_22_read(w);
}

void My_Window::wPi_23_read(Fl_Widget* w) {
	lbl_wPi_23->value(to_str(digitalRead(23)).c_str());
}

void My_Window::cb_read_23(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_23_read(w);
}

void My_Window::wPi_24_read(Fl_Widget* w) {
	lbl_wPi_24->value(to_str(digitalRead(24)).c_str());
}

void My_Window::cb_read_24(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_24_read(w);
}

void My_Window::wPi_25_read(Fl_Widget* w) {
	lbl_wPi_25->value(to_str(digitalRead(25)).c_str());
}

void My_Window::cb_read_25(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_25_read(w);
}

void My_Window::wPi_26_read(Fl_Widget* w) {
	lbl_wPi_26->value(to_str(digitalRead(26)).c_str());
}

void My_Window::cb_read_26(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_26_read(w);
}

void My_Window::wPi_27_read(Fl_Widget* w) {
	lbl_wPi_27->value(to_str(digitalRead(27)).c_str());
}

void My_Window::cb_read_27(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_27_read(w);
}

void My_Window::wPi_28_read(Fl_Widget* w) {
	lbl_wPi_28->value(to_str(digitalRead(28)).c_str());
}

void My_Window::cb_read_28(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_28_read(w);
}

void My_Window::wPi_29_read(Fl_Widget* w) {
	lbl_wPi_29->value(to_str(digitalRead(29)).c_str());
}

void My_Window::cb_read_29(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_29_read(w);
}

void My_Window::wPi_30_read(Fl_Widget* w) {
	lbl_wPi_30->value(to_str(digitalRead(30)).c_str());
}

void My_Window::cb_read_30(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_30_read(w);
}

void My_Window::wPi_31_read(Fl_Widget* w) {
	lbl_wPi_31->value(to_str(digitalRead(31)).c_str());
}

void My_Window::cb_read_31(Fl_Widget* w, void* f) {
	((My_Window*)f)->wPi_31_read(w);
}

void My_Window::quit(Fl_Widget* w) {
	this->hide();
}

void My_Window::cb_quit(Fl_Widget* w, void* f) {
	((My_Window*)f)->quit(w);
}
