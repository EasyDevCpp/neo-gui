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
#ifndef _NeoImage
#define _NeoImage

class Image: public Widget {
private:
	SDL_Texture *tex;
	
public:
	Image(SDL_Surface *img,int x,int y,int w,int h,Style s,Renderer *r) {
		tex=SDL_CreateTextureFromSurface(r->getRenderer(),img);
		setWidth(w);
		setHeight(h);
		setX(x);
		setY(y);
		setHover(false);
		setStyle(s);
		setRenderer(r);
		setType("NeoImage");
	}
	Image(SVG *svg,int x,int y,int w,int h,Style s,Renderer *r) {
		tex=SDL_CreateTextureFromSurface(r->getRenderer(),svg->getSurface());
		setWidth(w);
		setHeight(h);
		setX(x);
		setY(y);
		setHover(false);
		setStyle(s);
		setRenderer(r);
		setType("NeoImage");
	}
	~Image() {
		SDL_DestroyTexture(tex);
	}
	void display() {
		__eventLoop();
		getRenderer()->copy(tex,getX(),getY(),getWidth(),getHeight());
	}
	void setImage(SDL_Surface *img) {
		tex=SDL_CreateTextureFromSurface(getRenderer()->getRenderer(),img);
	}
};

#endif
#endif
