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
#ifndef _NeoFont
#define _NeoFont

class Font {
private:
	TTF_Font* font;
	
public:
	Font() {
		//Empty
	}
	Font(std::string file,int size) {
		font=TTF_OpenFont(file.c_str(),size);
	}
	~Font() {
		TTF_CloseFont(font);
	}
	SDL_Surface* renderText(std::string text,SDL_Color color) {
		return TTF_RenderText_Blended(font,text.c_str(),color);
	}
	std::array<int, 2> sizeText(std::string text) {
		std::array<int, 2> txt_size;
		TTF_SizeText(font,text.c_str(),&txt_size[0],&txt_size[1]);
		return txt_size;
	}
};

#endif
#endif
