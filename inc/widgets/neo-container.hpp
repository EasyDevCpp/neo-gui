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
#ifndef _NeoContainer
#define _NeoContainer

class Container: public Widget {
private:
	std::vector<Widget*> widgets;
	
public:
	Container(std::vector<Widget*> wids,Style s) {
		int w=0;
		int h=0;
		widgets=wids;
		for(auto t: widgets) {
			w+=t->getWidth()+s.getContainerDistance();
			if(h<t->getHeight()) {
				h=t->getHeight();
			}
		}
		setWidth(w);
		setHeight(h);
		setX(0);
		setY(0);
		setHover(false);
		setStyle(s);
		setType("NeoContainer");
	}
	Container(std::vector<Widget*> wids,int x,int y,Style s) {
		int w=0;
		int h=0;
		widgets=wids;
		for(auto t: widgets) {
			w+=t->getWidth()+s.getContainerDistance();
			if(h<t->getHeight()) {
				h=t->getHeight();
			}
		}
		setWidth(w);
		setHeight(h);
		setX(x);
		setY(y);
		setHover(false);
		setStyle(s);
		setType("NeoContainer");
	}
	~Container() {
		//Empty
	}
	void display() {
		__eventLoop();
		int x=0;
		for(auto t: widgets) {
			t->setX(getX()+x);
			t->setY(getY()+getHeight()/2-t->getHeight()/2);
			t->display();
			x+=t->getWidth()+getStyle().getContainerDistance();
		}
	}
	void setWidgets(std::vector<Widget*> wids) {
		int w=0;
		int h=0;
		widgets=wids;
		for(auto t: widgets) {
			w+=t->getWidth()+getStyle().getContainerDistance();
			if(h<t->getHeight()) {
				h=t->getHeight();
			}
		}
		setWidth(w);
		setHeight(h);
	}
};

#endif
#endif
