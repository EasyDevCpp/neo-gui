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
#ifndef _NeoMouse
#define _NeoMouse

class Mouse {
private:
	int mx;
	int my;
	int gmx;
	int gmy;
	Uint32 mouseTimer=0;
	
public:
	Mouse() {
		mx=0;
		my=0;
		gmx=0;
		gmy=0;
	}
	~Mouse() {
		//Empty
	}
	void update() {
		SDL_GetMouseState(&mx,&my);
		SDL_GetGlobalMouseState(&gmx,&gmy);
	}
	bool clicked() {
		return SDL_MOUSEBUTTONDOWN&&SDL_BUTTON(SDL_GetMouseState(&mx,&my))==SDL_BUTTON_LEFT&&SDL_GetTicks()-mouseTimer>=180;
	}
	bool globalClicked() {
		return SDL_MOUSEBUTTONDOWN&&SDL_BUTTON(SDL_GetMouseState(&gmx,&gmy))==SDL_BUTTON_LEFT&&SDL_GetTicks()-mouseTimer>=180;
	}
	bool hover(int x,int y,int w,int h) {
		return mx>=x&&mx<=x+w&&my>=y&&my<=y+h;
	}
	bool globalHover(int x,int y,int w,int h) {
		return gmx>=x&&gmx<=x+w&&gmy>=y&&gmy<=y+h;
	}
	void resetTimer() {
		mouseTimer=SDL_GetTicks();
	}
	//get-methods
	int getMouseX() { return mx; }
	int getMouseY() { return my; }
	int getGlobalMouseX() { return gmx; }
	int getGlobalMouseY() { return gmy; }	
};

#endif
#endif
