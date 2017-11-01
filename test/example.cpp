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
#include "../inc/neo.hpp"

class Main: public Neo::Scene {
public:
	Main(Neo::Renderer* r) {
		createScene("example.style","Main",r);
		
		addWidget(new Neo::Button(new Neo::Label("Button",getFonts()[Neo::FONT_MEDIUM],getStyle(),r),50,50,200,40,getStyle(),r)); //widget: 0
		
		addWidget(new Neo::Label("Label",300,50,getFonts()[Neo::FONT_BIG],getStyle(),r)); //widget: 1
		getWidget(1)->setHover(true); //enable hover&click event
		
		addWidget(new Neo::Button(new Neo::Label("Button2",getFonts()[Neo::FONT_MEDIUM],getStyle(),r),50,120,getStyle(),r)); //widget: 2
		
		addWidget(new Neo::Image(new Neo::SVG("res"+SEPERATOR+"save.svg"),300,120,48,48,getStyle(),r)); //widget: 3
		
		std::vector<Neo::Widget*> w; //add to private to recieve events! events won't be stored in widgetMsg!
		w.push_back(new Neo::Image(new Neo::SVG("res"+SEPERATOR+"save.svg"),0,0,48,48,getStyle(),r));
		w.push_back(new Neo::Label("Save",getFonts()[Neo::FONT_MEDIUM],getStyle(),r));
		addWidget(new Neo::Button(new Neo::Container(w,getStyle()),50,200,150,45,getStyle(),r)); //widget: 4
		
		std::vector<Neo::Widget*> buttons;
		buttons.push_back(new Neo::CheckButton(new Neo::Label("tab 1",getFonts()[Neo::FONT_MEDIUM],getStyle(),r),0,0,120,40,getStyle(),r));
		buttons.push_back(new Neo::CheckButton(new Neo::Label("tab 2",getFonts()[Neo::FONT_MEDIUM],getStyle(),r),0,0,120,40,Neo::Style("example-2.style"),r));
		buttons.push_back(new Neo::CheckButton(new Neo::Label("tab 3",getFonts()[Neo::FONT_MEDIUM],getStyle(),r),0,0,120,40,getStyle(),r));
		addWidget(new Neo::Container(buttons,50,300,getStyle())); //widget: 5
	}
	int wndEvents(SDL_Event e) {
		if(e.type==SDL_QUIT) {
			return Neo::QUIT;
		}
	}
	int widgetEvents() {
		switch(widgetMsg(Neo::MSG_CLICK)) {
			case 0:
				return Neo::QUIT;
				break;
			case 1:
				((Neo::Label*)getWidget(1))->setText("Clicked!");
				break;
		}
		return 0;
	}
};

class App: public Neo::Wnd {
public:
	App() {
		createWnd(0,0,500,500,SDL_WINDOW_SHOWN);
		addScene(new Main(getRenderer()));
		showWnd();
	}
};

int main(int argc, char *argv[]) {
	Neo::initSDL(SDL_INIT_VIDEO,IMG_INIT_PNG);
	App app;
	Neo::quitSDL();
	return 0;
}
