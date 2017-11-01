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
#ifndef _NeoRenderer
#define _NeoRenderer

class Renderer {
private:
	SDL_Renderer *ren;
	SDL_Rect rect;
	Mouse* mouse;

public:
	Renderer() {
		ren=NULL;
	}
	Renderer(SDL_Window *wnd) {
		ren=SDL_CreateRenderer(wnd,-1,0);
        SDL_SetRenderDrawBlendMode(ren,SDL_BLENDMODE_BLEND);
	    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"2");
        mouse=new Mouse();	
	}
	~Renderer() {
		SDL_DestroyRenderer(ren);
	}
	
	void clear() {
		SDL_RenderClear(ren);
	}
	void present() {
		SDL_RenderPresent(ren);
	}
	void drawRect(int x,int y,int w,int h,SDL_Color c) {
        rect={x,y,w,h};
        SDL_SetRenderDrawColor(ren,c.r,c.g,c.b,c.a);
        SDL_RenderDrawRect(ren,&rect);
    }
    void fillRect(int x,int y,int w,int h,SDL_Color c) {
        rect={x,y,w,h};
        SDL_SetRenderDrawColor(ren,c.r,c.g,c.b,c.a);
        SDL_RenderFillRect(ren,&rect);
    }
    void copy(SDL_Texture* tex,int x,int y,int w,int h) {
        rect={x,y,w,h};
        SDL_RenderCopy(ren,tex,NULL,&rect);
    }
	
	SDL_Renderer *getRenderer() {
		return ren;
	}
	Mouse* getMouse() {
		return mouse;
	}
};

#endif
#endif
