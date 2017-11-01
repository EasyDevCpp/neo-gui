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
#ifndef _NeoLabel
#define _NeoLabel

class Label: public Widget {
private:
	SDL_Texture *tex;
	Font *font;
	
public:
	Label(std::string text,int x,int y,Font *f,Style s,Renderer *r) {
		font=f;
		tex=SDL_CreateTextureFromSurface(r->getRenderer(),f->renderText(text,s.getFontColor()));
		setWidth(f->sizeText(text)[0]);
		setHeight(f->sizeText(text)[1]);
		setX(x);
		setY(y);
		setHover(false);
		setStyle(s);
		setRenderer(r);
		setType("NeoLabel");
	}
	Label(std::string text,Font *f,Style s,Renderer *r) {
		font=f;
		tex=SDL_CreateTextureFromSurface(r->getRenderer(),f->renderText(text,s.getFontColor()));
		setWidth(f->sizeText(text)[0]);
		setHeight(f->sizeText(text)[1]);
		setX(0);
		setY(0);
		setHover(false);
		setStyle(s);
		setRenderer(r);
		setType("NeoLabel");
	}
	~Label() {
		SDL_DestroyTexture(tex);
	}
	void display() {
		__eventLoop();
		getRenderer()->copy(tex,getX(),getY(),getWidth(),getHeight());
	}
	void setText(std::string text) {
		tex=SDL_CreateTextureFromSurface(getRenderer()->getRenderer(),font->renderText(text,getStyle().getFontColor()));
		setWidth(font->sizeText(text)[0]);
		setHeight(font->sizeText(text)[1]);
	}
	void setFont(Font *f) {
		font=f;
	}
};

#endif
#endif
