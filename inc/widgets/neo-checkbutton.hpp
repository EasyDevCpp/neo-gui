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
#ifndef _NeoCheckButton
#define _NeoCheckButton

class CheckButton: public Widget {
private:
	Widget *widget;
	
public:
	CheckButton(Widget *wid,int x,int y,int w,int h,Style s,Renderer *r) {
		widget=wid;
		setX(x);
		setY(y);
		setWidth(w);
		setHeight(h);
		setStyle(s);
		setRenderer(r);
		setCheckable(true);
		setType("NeoCheckButton");
	}
	CheckButton(Widget *wid,int x,int y,int w,Style s,Renderer *r) {
		widget=wid;
		setX(x);
		setY(y);
		setWidth(w);
		setHeight(wid->getHeight()+(2*s.getBtnPadding()));
		setStyle(s);
		setRenderer(r);
		setCheckable(true);
		setType("NeoCheckButton");
	}
	CheckButton(Widget *wid,int x,int y,Style s,Renderer *r) {
		widget=wid;
		setX(x);
		setY(y);
		setWidth(wid->getWidth()+(2*s.getBtnPadding()));
		setHeight(wid->getHeight()+(2*s.getBtnPadding()));
		setStyle(s);
		setRenderer(r);
		setCheckable(true);		
		setType("NeoCheckButton");
	}
	CheckButton(int x,int y,int w,int h,Style s,Renderer *r) {
		widget=nullptr;
		setX(x);
		setY(y);
		setWidth(w);
		setHeight(h);
		setStyle(s);
		setRenderer(r);
		setCheckable(true);		
		setType("NeoButton");
	}
	~CheckButton() {
		widget->~Widget();
	}
	void display() {
		__eventLoop();
		if(getEvent()==2||getEvent()==1||getChecked()) {
			getRenderer()->fillRect(getX()-getStyle().getBtnHoverBorderSize(),getY()-getStyle().getBtnHoverBorderSize(),
									getWidth()+(2*getStyle().getBtnHoverBorderSize()),getHeight()+(2*getStyle().getBtnHoverBorderSize()),
									getStyle().getBtnHoverBorderColor());
			getRenderer()->fillRect(getX(),getY(),getWidth(),getHeight(),getStyle().getBackgroundColor());
			getRenderer()->fillRect(getX(),getY(),getWidth(),getHeight(),getStyle().getBtnHoverColor());	
		} else {
			getRenderer()->fillRect(getX()-getStyle().getBtnBorderSize(),getY()-getStyle().getBtnBorderSize(),
									getWidth()+(2*getStyle().getBtnBorderSize()),getHeight()+(2*getStyle().getBtnBorderSize()),
									getStyle().getBtnBorderColor());
			getRenderer()->fillRect(getX(),getY(),getWidth(),getHeight(),getStyle().getBackgroundColor());	
			getRenderer()->fillRect(getX(),getY(),getWidth(),getHeight(),getStyle().getBtnColor());	
		}
		if(widget!=nullptr) {
			widget->setX(getX()+(getWidth()/2-widget->getWidth()/2));
			widget->setY(getY()+(getHeight()/2-widget->getHeight()/2));
			widget->display();
		}
	}
};

#endif
#endif
