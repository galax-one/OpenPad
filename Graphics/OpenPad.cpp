#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <fstream>
#include "getfunc.h"

std::string get_key_string(int);
std::string get_alter_key_string(int);
void set_option_box_in(sf::RectangleShape&, sf::Color&);
void set_option_box_out(sf::RectangleShape&, sf::Color&);
int get_file_total_line(std::string);
void set_text_box(sf::RectangleShape&);
void load_font(sf::Font&, std::string);
std::string read_file_content(std::string);
void set_file_content_text(sf::Text&, std::string&, sf::Font&);
void set_file_option_out_text(sf::Text&, std::string, sf::Font&);

int main() {
	std::cout << "WordPad Started....." << std::endl;

	// ---------- Objects & Variables ----------
	std::fstream txt_file; // for loading text file
	sf::RectangleShape text_box; // for text writing box
	sf::RectangleShape file_option_out; // for file option selection box
	sf::RectangleShape file_option_in; // for file option box
	sf::Font font_arial; // text font
	sf::Color grey_color(230, 230, 230); // making a color for outer file option box
	sf::Event events; // events
	std::string line; // for reading text file lines
	std::string file_content_string; // for processing text into a string for further draw it and display
	sf::Text file_content_text; // text of a open file 
	sf::Text file_option_out_text; // 'File' option text
	sf::Text new_file_fileOption; // 'New' option text
	sf::Text open_file_fileOption; // 'Open' option text
	sf::Text save_file_fileOption; // 'Save File' option text
	sf::Text exit_fileOption; // 'Exit' option text

	int total_lines = 0; // total lines of text file

	bool is_option_selected = false;


	sf::VideoMode video_mode(1024, 768);
	sf::RenderWindow window(video_mode, "OpenPad");


	set_option_box_out(file_option_out, grey_color); // set outside option box
	set_text_box(text_box); // set text box


	load_font(font_arial, "./fonts/arial.ttf"); // load font
	total_lines = get_file_total_line("temp.txt"); // total lines in 'temp.txt' file
	file_content_string = read_file_content("temp.txt"); // getting content of `temp.txt` file
	file_content_string += "|";


	set_file_content_text(file_content_text, file_content_string, font_arial); // making a Text for display file content and setting it

	set_file_option_out_text(file_option_out_text, "File", font_arial); // making a Text for display `File` string and settting it


	window.clear(sf::Color::White);
	window.draw(text_box);
	window.draw(file_option_out);
	window.draw(file_content_text);
	window.draw(file_option_out_text);
	window.display();

	int hold_key = -2;

	while (window.isOpen()) {
		window.clear(sf::Color::White);

		while (window.pollEvent(events)) {


			if (events.type == sf::Event::KeyPressed || events.type == sf::Event::KeyReleased) {

				int current_key = -2;

				if (events.type == sf::Event::KeyPressed) {
					if (hold_key == -2) {
						hold_key = events.key.code;
					}
					current_key = events.key.code;
				}

				if (events.type == sf::Event::KeyReleased) {
					if (events.key.code == hold_key) {
						hold_key = -2;
					}
					current_key = -2; // Nothing happen's but let it be here :)
				}


				//	(condition for checking second is pressed not released) && (condition for checking key is press while a key is on hold)
				if (events.type == sf::Event::KeyPressed && hold_key != current_key) { // [HOLD KEY] + [NEW PRESS KEY] 2 key combination

					if (hold_key == sf::Keyboard::LShift || hold_key == sf::Keyboard::RShift) {
						//std::cout << "Hold Key: Shift" << std::endl;
						std::cout << "Key: " << get_alter_key_string(current_key) << std::endl;


						sf::Vector2f pos = file_content_text.findCharacterPos((file_content_string.length() - 1));
						if ((pos.x + 25) >= 1000) {
							file_content_string.pop_back();
							file_content_string += "\n";
							file_content_string += get_alter_key_string(events.key.code);
							file_content_string += "|";
						}
						else {
							file_content_string.pop_back();
							file_content_string += get_alter_key_string(events.key.code);
							file_content_string += "|";
						}

						file_content_text.setString(file_content_string);
						file_option_out.setFillColor(grey_color);

						window.draw(text_box);
						window.draw(file_option_out);
						window.draw(file_content_text);
						window.draw(file_option_out_text);
						window.display();
					}
				}

			}


			// ----- Key Pressed Event -----
			if (events.type == sf::Event::KeyPressed && hold_key != sf::Keyboard::LShift && hold_key != sf::Keyboard::RShift) {

				std::cout << "Hold Key: " << hold_key << std::endl;

				// --- Backspace ---
				if (events.key.code == sf::Keyboard::BackSpace) {
					if (!file_content_string.empty() && file_content_string.length() > 1) {
						file_content_string.pop_back();
						file_content_string.pop_back();
						file_content_string += "|";
						std::cout << "TEXT: " << file_content_string << " String Length: "<< file_content_string.length() << std::endl;
					}
				}

				// --- Enter ---
				else if (events.key.code == sf::Keyboard::Enter) {
					std::cout << "New Line!" << std::endl;
					file_content_string.pop_back();
					file_content_string += "\n";
					file_content_string += "|";
				}

				// --- Tab ---
				else if (events.key.code == sf::Keyboard::Tab) {
					std::cout << "Tab Space!" << std::endl;
					sf::Vector2f pos = file_content_text.findCharacterPos((file_content_string.length() - 1));
					std::cout << "pox.x: " << pos.x << std::endl;

					if ((pos.x + 25) >= 1000){
						file_content_string.pop_back();
						file_content_string += "\n";
						file_content_string += "\t";
						file_content_string += "|";
					}
					else {
						file_content_string.pop_back();
						file_content_string += "\t";
						file_content_string += "|";
					}
				}


				// --- Others Key ---
				else {
					sf::Vector2f pos = file_content_text.findCharacterPos((file_content_string.length() - 1));
					std::cout << "pox.x: " << pos.x << std::endl;

					if ((pos.x + 25) >= 1000) {
						std::cout << "End of line reached!" << std::endl;
						file_content_string.pop_back();
						file_content_string += "\n";
						file_content_string += get_key_string(events.key.code);
						file_content_string += "|";
					}
					else {
						file_content_string.pop_back();
						file_content_string += get_key_string(events.key.code);
						file_content_string += "|";
					}

				}


				file_content_text.setString(file_content_string);
				file_option_out.setFillColor(grey_color);

				window.draw(text_box);
				window.draw(file_option_out);
				window.draw(file_content_text);
				window.draw(file_option_out_text);
				window.display();
			}


			// ----- File Option Select Event -----
			if (events.type == sf::Event::MouseButtonPressed && events.mouseButton.button == sf::Mouse::Button::Left) {
				if (file_option_out.getPosition().x < sf::Mouse::getPosition(window).x && 50 > sf::Mouse::getPosition(window).x && file_option_out.getPosition().y < sf::Mouse::getPosition(window).y && 35 > sf::Mouse::getPosition(window).y) {

					if (is_option_selected == false) {
						is_option_selected = true;

						set_option_box_in(file_option_in, grey_color);
						set_fileOption_text(new_file_fileOption, "New", font_arial, 35);

						window.draw(text_box);
						window.draw(file_option_out);
						window.draw(file_content_text);

						// Inner File Option Box
						window.draw(file_option_in);
						window.draw(new_file_fileOption);

						window.draw(file_option_out_text);
						window.display();
					}
					else {
						is_option_selected = false;

						window.draw(text_box);
						window.draw(file_option_out);
						window.draw(file_content_text);
						window.draw(file_option_out_text);
						window.display();
					}


				}
			}


			// ----- Mouse Moved Event -----
			if (events.type == sf::Event::MouseMoved) {


				// --- Change File Option Color (on hover) ---
				if (file_option_out.getPosition().x < events.mouseMove.x && 50 > events.mouseMove.x && file_option_out.getPosition().y < events.mouseMove.y && 35 > events.mouseMove.y) {
					file_option_out.setFillColor(sf::Color::Blue);

					if (is_option_selected == true) { // When File option is on
						window.draw(text_box);
						window.draw(file_option_out);
						window.draw(file_content_text);

						// Inner File Option Box
						window.draw(file_option_in);
						window.draw(new_file_fileOption);

						window.draw(file_option_out_text);
						window.display();
					}
					else {
						window.draw(text_box);
						window.draw(file_option_out);
						window.draw(file_content_text);
						window.draw(file_option_out_text);
						window.display();
					}
				}


				// --- Event back File Option Color (on dis-hover) ---
				else {

					if (is_option_selected == true) { // When file option is on
						file_option_out.setFillColor(grey_color);

						window.draw(text_box);
						window.draw(file_option_out);
						window.draw(file_content_text);

						// Inner File Option Box
						window.draw(file_option_in);
						window.draw(new_file_fileOption);

						window.draw(file_option_out_text);
						window.display();
					}
					else {
						file_option_out.setFillColor(grey_color);
						window.draw(text_box);
						window.draw(file_content_text);
						window.draw(file_option_out);
						window.draw(file_option_out_text);
						window.display();
					}
				}

				//printf("Mouse Moved!   X: %d , Y: %d\n", events.mouseMove.x, events.mouseMove.y);
			}



			// ----- Close Window Events -----
			if ((events.type == sf::Event::KeyPressed) && (events.key.code == sf::Keyboard::Escape)) {
				printf("Escape Key Pressed!\n");
				window.close();
			}

			if (events.type == sf::Event::Closed()) {
				window.close();
			}
		}
	}
	return 0;
}