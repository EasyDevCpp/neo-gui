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
#ifndef _NeoScene
#define _NeoScene

class Scene {
private:
	Style style;
	std::string title;
	bool title_upd=false;
	Renderer* ren;
	std::array<Font*, 3> fonts;
	std::vector<Widget*> widgets;
	
public:
	Scene() {
		//Empty
	}
	~Scene() {
		for(auto f: fonts) {
			f->~Font();
		}
	}
	virtual int wndEvents(SDL_Event e)=0;
	virtual int widgetEvents()=0;
	void display(int x,int y,int max_w,int max_h) {
		ren->fillRect(0,0,max_w,max_h,style.getBackgroundColor());
		for(auto t: widgets) {
			t->display();
		}
	}
	
	void setStyle(std::string file) {
		style=Style(file);
		for(int i=0;i<fonts.size();i++) {
			fonts[i]=new Font("res"+SEPERATOR+style.getFont(),style.getFontSizes()[i]);
		}				
	}
	void setTitle(std::string t) {
		title=t;
		title_upd=true;
	}
	void setRenderer(Renderer* r) {
		ren=r;
	}
	void createScene(std::string file,std::string t,Renderer* r) {
		setStyle(file);
		setTitle(t);
		setRenderer(r);
	}
	void addWidget(Widget* w) {
		widgets.push_back(w);
	}
	Widget* getWidget(int i) {
		return widgets.at(i);
	}
	int widgetMsg(int value) {
		int c=0;
		for(auto t: widgets) {
			if(t->getEvent()==value) {
				return c; 
			}
			c++;
		}
	}
	
	std::array<Font*, 3> getFonts() {
		return fonts;
	}
	Style getStyle() {
		return style;
	}
	Renderer* getRenderer() {
		return ren;
	}
	
	//@INTERNAL USE ONLY
	std::string __getTitle() { 
		title_upd=false;
		return title;
	}
	bool __getTitleUpdate() { return title_upd; }
};

#endif
#endif
