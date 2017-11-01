/*
Neo-Gui - SDL2 based cross-plattform Gui-Toolkit
Copyright (C)  2017  Robin Krause

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef error_cpp_version
#ifndef _NeoStyle
#define _NeoStyle

class Style {
private:
	bool opened;
	std::array<std::string, 11> params={{"font:","font-sizes:","font-color:",
										 "background-color:",
										 "btn-padding:","btn-font-color:","btn-color:","btn-hover-color:","btn-border:","btn-hover-border:",
										 "container-distance:"}};
	/*MAIN*/
	/*FONT*/
	std::string font="Roboto.ttf";
	std::array<int, 3> font_sizes={{40,20,16}};
	SDL_Color font_color={0,0,0};
	/*BODY*/
	SDL_Color background_color={255,255,255,255};
	
	/*WIDGETS*/
	/*BUTTON*/
	int btn_padding=8;
	SDL_Color btn_color={0,0,0,255};
	SDL_Color btn_hover_color={235,85,80,255};
	int btn_border_size=0;
	SDL_Color btn_border_color={0,0,0,0};
	int btn_hover_border_size=0;
	SDL_Color btn_hover_border_color={0,0,0,0};
	/*CONTAINER*/
	int container_distance=0;

public:
	Style() {
		//Empty
	}
	Style(std::string file) {
		std::ifstream style_file;
		int tint=0;
		std::string tstr="";
		std::string tparam="";
		bool param=false;
		style_file.open(file,std::ios_base::in);
		if(style_file.is_open()) {
			opened=true;
			while(!style_file.eof()) {
				if(!param) {
					tparam="";
					style_file>>tparam;
					for(auto t: params) {
						if(tparam==t) {
							param=true;
						}
					}
				} else {
					if(tparam=="font:") {
						style_file>>font;
					} else if(tparam=="font-sizes:") {
						for(int i=0;i<font_sizes.size();i++) {
							style_file>>tint;
							font_sizes[i]=tint;
						}
					} else if(tparam=="font-color:") {
						style_file>>tint;
						font_color.r=tint;
						style_file>>tint;
						font_color.g=tint;
						style_file>>tint;
						font_color.b=tint;												
					} else if(tparam=="background-color:") {
						style_file>>tint;
						background_color.r=tint;
						style_file>>tint;
						background_color.g=tint;
						style_file>>tint;
						background_color.b=tint;
						background_color.a=255;			
					} else if(tparam=="btn-padding:") {
						style_file>>tint;
						btn_padding=tint;
					} else if(tparam=="btn-color:") {
						style_file>>tint;
						btn_color.r=tint;
						style_file>>tint;
						btn_color.g=tint;
						style_file>>tint;
						btn_color.b=tint;
						style_file>>tint;
						btn_color.a=tint;																		
					} else if(tparam=="btn-hover-color:") {
						style_file>>tint;
						btn_hover_color.r=tint;
						style_file>>tint;
						btn_hover_color.g=tint;
						style_file>>tint;
						btn_hover_color.b=tint;
						style_file>>tint;
						btn_hover_color.a=tint;																		
					} else if(tparam=="btn-border:") {
						style_file>>tint;
						btn_border_size=tint;
						style_file>>tint;
						btn_border_color.r=tint;
						style_file>>tint;
						btn_border_color.g=tint;
						style_file>>tint;
						btn_border_color.b=tint;
						btn_border_color.a=255;																		
					} else if(tparam=="btn-hover-border:") {
						style_file>>tint;
						btn_hover_border_size=tint;					
						style_file>>tint;
						btn_hover_border_color.r=tint;
						style_file>>tint;
						btn_hover_border_color.g=tint;
						style_file>>tint;
						btn_hover_border_color.b=tint;
						btn_hover_border_color.a=255;																		
					} else if(tparam=="container-distance:") {
						style_file>>tint;
						container_distance=tint;
					}
					param=false;
				}
			}
		} else {
			opened=false;
		}
	}
	~Style() {
		//Empty
	}
	/*get-methods*/
	bool isOpen() { return opened; }
	/*MAIN*/
	/*FONT*/
	std::string getFont() { return font; }
	std::array<int, 3> getFontSizes() { return font_sizes; }
	SDL_Color getFontColor() { return font_color; }
	/*BODY*/
	SDL_Color getBackgroundColor() { return background_color; }
	
	/*WIDGETS*/
	/*BUTTON*/
	int getBtnPadding() { return btn_padding; }
	SDL_Color getBtnColor() { return btn_color; }
	SDL_Color getBtnHoverColor() { return btn_hover_color; }
	int getBtnBorderSize() { return btn_border_size; }
	SDL_Color getBtnBorderColor() { return btn_border_color; }
	int getBtnHoverBorderSize() { return btn_hover_border_size; }
	SDL_Color getBtnHoverBorderColor() { return btn_hover_border_color; }
	/*CONTAINER*/
	int getContainerDistance() { return container_distance; }
};

#endif
#endif
