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
#ifndef _NeoWidget
#define _NeoWidget

class Widget {
private:
	int x;
	int y;
	int w;
	int h;
	bool state=true;
	bool hover=true;
	bool check=false;
	bool checked=false;
	int event=0;
	Style style;
	Renderer* ren;
	std::string type;
	
public:
	Widget() {
		//Empty
	}
	~Widget() {
		//Empty
	}
	virtual void display()=0;
	//@INTERNAL USE ONLY
	void __eventLoop() {
		if(hover&&state) {
			ren->getMouse()->update();
			if(check) {
				if(checked) {
					if(ren->getMouse()->hover(x,y,w,h)&&ren->getMouse()->clicked()) {
						event=2;
						checked=false;
						ren->getMouse()->resetTimer();
					} else {
						event=0;
					}
				} else {
					if(ren->getMouse()->hover(x,y,w,h)&&ren->getMouse()->clicked()) {
						event=2;
						checked=true;
						ren->getMouse()->resetTimer();
					} else if(ren->getMouse()->hover(x,y,w,h)) {
						event=1;
					} else {
						event=0;
					}
				}
			} else {
				if(ren->getMouse()->hover(x,y,w,h)&&ren->getMouse()->clicked()) {
					event=2;
					ren->getMouse()->resetTimer();
				} else if(ren->getMouse()->hover(x,y,w,h)) {
					event=1;
				} else {
					event=0;
				}
			}
		}
	}
	//set-methods
	void setX(int x) { this->x=x; }
	void setY(int y) { this->y=y; }
	void setWidth(int w) { this->w=w; }
	void setHeight(int h) { this->h=h; }
	void setState(bool s) { this->state=s; }
	void setHover(bool h) { this->hover=h; }
	void setEvent(int e) { this->event=e; }
	void setStyle(Style s) { this->style=s; }
	void setCheckable(bool c) { this->check=c; }
	void setChecked(bool c) { this->checked=true; }
	void setRenderer(Renderer* r) { this->ren=r; }
	void setType(std::string t) { this->type=t; }
	//get-methods
	int getX() { return x; }
	int getY() { return y; }
	int getWidth() { return w; }
	int getHeight() { return h; }
	bool getState() { return state; }
	int getEvent() { return event; }
	Style getStyle() { return style; }
	bool getChecked() { return checked; }
	Renderer* getRenderer() { return ren; }
	std::string getType() { return type; }
};

#endif
#endif
