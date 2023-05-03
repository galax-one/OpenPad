#pragma once


std::string get_key_string(int key) {
	switch (key)
	{
		// aplhabets
		case sf::Keyboard::A:
			return "a";
		case sf::Keyboard::B:
			return "b";
		case sf::Keyboard::C:
			return "c";
		case sf::Keyboard::D:
			return "d";
		case sf::Keyboard::E:
			return "e";
		case sf::Keyboard::F:
			return "f";
		case sf::Keyboard::G:
			return "g";
		case sf::Keyboard::H:
			return "h";
		case sf::Keyboard::I:
			return "i";
		case sf::Keyboard::J:
			return "j";
		case sf::Keyboard::K:
			return "k";
		case sf::Keyboard::L:
			return "l";
		case sf::Keyboard::M:
			return "m";
		case sf::Keyboard::N:
			return "n";
		case sf::Keyboard::O:
			return "o";
		case sf::Keyboard::P:
			return "p";
		case sf::Keyboard::Q:
			return "q";
		case sf::Keyboard::R:
			return "r";
		case sf::Keyboard::S:
			return "s";
		case sf::Keyboard::T:
			return "t";
		case sf::Keyboard::U:
			return "u";
		case sf::Keyboard::V:
			return "v";
		case sf::Keyboard::W:
			return "w";
		case sf::Keyboard::X:
			return "x";
		case sf::Keyboard::Y:
			return "y";
		case sf::Keyboard::Z:
			return "z";

			// numberics
		case sf::Keyboard::Num1:
			return "1";
		case sf::Keyboard::Num2:
			return "2";
		case sf::Keyboard::Num3:
			return "3";
		case sf::Keyboard::Num4:
			return "4";
		case sf::Keyboard::Num5:
			return "5";
		case sf::Keyboard::Num6:
			return "6";
		case sf::Keyboard::Num7:
			return "7";
		case sf::Keyboard::Num8:
			return "8";
		case sf::Keyboard::Num9:
			return "9";
		case sf::Keyboard::Num0:
			return "0";
		

		// symbols

		case sf::Keyboard::Tilde:
			return "`";
		case sf::Keyboard::LBracket:
			return "[";
		case sf::Keyboard::RBracket:
			return "]";
		case sf::Keyboard::SemiColon:
			return ";";
		case sf::Keyboard::Comma:
			return ",";
		case sf::Keyboard::Period:
			return ".";
		case sf::Keyboard::Quote:
			return "'";
		case sf::Keyboard::Slash:
			return "/";
		case sf::Keyboard::BackSlash:
			return "\\";
		case sf::Keyboard::Equal:
			return "=";
		case sf::Keyboard::Hyphen:
			return "-";



		// miscell
		case sf::Keyboard::Space:
			return " ";

		default:
			return "";
	}
}


std::string get_alter_key_string(int key) {
	switch (key)
	{
			// aplhabets
		case sf::Keyboard::A:
			return "A";
		case sf::Keyboard::B:
			return "B";
		case sf::Keyboard::C:
			return "C";
		case sf::Keyboard::D:
			return "D";
		case sf::Keyboard::E:
			return "E";
		case sf::Keyboard::F:
			return "F";
		case sf::Keyboard::G:
			return "G";
		case sf::Keyboard::H:
			return "H";
		case sf::Keyboard::I:
			return "I";
		case sf::Keyboard::J:
			return "J";
		case sf::Keyboard::K:
			return "K";
		case sf::Keyboard::L:
			return "L";
		case sf::Keyboard::M:
			return "M";
		case sf::Keyboard::N:
			return "N";
		case sf::Keyboard::O:
			return "O";
		case sf::Keyboard::P:
			return "P";
		case sf::Keyboard::Q:
			return "Q";
		case sf::Keyboard::R:
			return "R";
		case sf::Keyboard::S:
			return "S";
		case sf::Keyboard::T:
			return "T";
		case sf::Keyboard::U:
			return "U";
		case sf::Keyboard::V:
			return "V";
		case sf::Keyboard::W:
			return "W";
		case sf::Keyboard::X:
			return "X";
		case sf::Keyboard::Y:
			return "Y";
		case sf::Keyboard::Z:
			return "Z";

			// numberics
		case sf::Keyboard::Num1:
			return "!";
		case sf::Keyboard::Num2:
			return "@";
		case sf::Keyboard::Num3:
			return "#";
		case sf::Keyboard::Num4:
			return "$";
		case sf::Keyboard::Num5:
			return "%";
		case sf::Keyboard::Num6:
			return "^";
		case sf::Keyboard::Num7:
			return "&";
		case sf::Keyboard::Num8:
			return "*";
		case sf::Keyboard::Num9:
			return "(";
		case sf::Keyboard::Num0:
			return ")";


			// symbols

		case sf::Keyboard::Tilde:
			return "~";
		case sf::Keyboard::LBracket:
			return "{";
		case sf::Keyboard::RBracket:
			return "}";
		case sf::Keyboard::SemiColon:
			return ":";
		case sf::Keyboard::Comma:
			return "<";
		case sf::Keyboard::Period:
			return ">";
		case sf::Keyboard::Quote:
			return "\"";
		case sf::Keyboard::Slash:
			return "?";
		case sf::Keyboard::BackSlash:
			return "|";
		case sf::Keyboard::Equal:
			return "+";
		case sf::Keyboard::Hyphen:
			return "_";




			// miscell
		case sf::Keyboard::Space:
			return " ";

		default:
			return "";
	}
}


void set_option_box_in(sf::RectangleShape &file_option_in, sf::Color & grey_color) {
	file_option_in.setSize(sf::Vector2f(50, 100));
	file_option_in.setPosition(0, 35);
	file_option_in.setFillColor(grey_color);
}

void set_option_box_out(sf::RectangleShape &file_option_out, sf::Color &file_option_out_color) {
	file_option_out.setSize(sf::Vector2f(50, 35));
	file_option_out.setPosition(0, 0);
	file_option_out.setFillColor(file_option_out_color);
}

int get_file_total_line(std::string file_path) {
	std::fstream file;
	int total_lines = 0;
	std::string line;

	file.open(file_path, std::ios::in);
	while (std::getline(file, line)) {
		total_lines++;
	}
	file.close();

	return total_lines;
}

void set_text_box(sf::RectangleShape& text_box) {
	text_box.setSize(sf::Vector2f(1024, 733));
	text_box.setPosition(0, 35);
}

void load_font(sf::Font &file_font, std::string font_path) {
	file_font.loadFromFile(font_path);
}

std::string read_file_content(std::string file_path) {
	std::fstream file;
	std::string file_content;
	std::string line;
	int total_lines = get_file_total_line(file_path);


	file.open("temp.txt", std::ios::in);

	for (int i = 0; std::getline(file, line); i++) {
		if (total_lines == (i + 1)) {
			file_content += line;
		}
		else {
			file_content += line;
			file_content += "\n";
		}
	}

	return file_content;
}

void set_file_content_text(sf::Text &file_content_text, std::string &file_content_string, sf::Font &font_arial) {
	file_content_text.setString(file_content_string);
	file_content_text.setFont(font_arial);
	file_content_text.setFillColor(sf::Color::Black);
	file_content_text.setPosition(0, 35);
}

void set_file_option_out_text(sf::Text &file_option_out_text, std::string title, sf::Font &font_arial) {
	file_option_out_text.setString(title);
	file_option_out_text.setFont(font_arial);
	file_option_out_text.setCharacterSize(24);
	file_option_out_text.setFillColor(sf::Color::Black);
	file_option_out_text.setPosition(3, 3);
}

void set_fileOption_text(sf::Text& fileOption, std::string text, sf::Font& font_arial, int y) {
	fileOption.setString(text);
	fileOption.setFont(font_arial);
	fileOption.setCharacterSize(24);
	fileOption.setFillColor(sf::Color::Black);
	fileOption.setPosition(0, y);
}