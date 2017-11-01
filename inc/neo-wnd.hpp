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
#ifndef _NeoWnd
#define _NeoWnd

class Wnd {
private:
	SDL_Window *wnd;
	Renderer* ren;
	SDL_Event event;
	std::vector<Scene*> scenes; 
	bool exit;
	int scene_id=0;
	int xpos;
	int ypos;
	int wndw;
	int wndh;
	
public:
	Wnd() {
		wnd=NULL;
		exit=false;
	}
	~Wnd() {
		ren->~Renderer();
		SDL_DestroyWindow(wnd);
	}
	void createWnd(int x,int y,int width,int height,int flags) {
		wnd=SDL_CreateWindow("Neo-Gui",x,y,width,height,flags);
		xpos=x;
		ypos=y;
		wndw=width;
		wndh=height;
		ren=new Renderer(wnd);
	}
	void showWnd() {
		SDL_StartTextInput();
		do {
			while(SDL_PollEvent(&event)) {
				if(scenes.size()>scene_id&&scenes.at(scene_id)!=nullptr) {
					if(scenes.at(scene_id)->wndEvents(event)==-1) {
						exit=true;
					}
				}	
			}
			if(scenes.size()>scene_id&&scenes.at(scene_id)!=nullptr) {
				if(scenes.at(scene_id)->__getTitleUpdate()) {
					SDL_SetWindowTitle(wnd,scenes.at(scene_id)->__getTitle().c_str());
				}
			}
			ren->clear();
			if(scenes.size()>scene_id&&scenes.at(scene_id)!=nullptr) {
				
				scenes.at(scene_id)->display(xpos,ypos,wndw,wndh);
				int w_event=scenes.at(scene_id)->widgetEvents();
				if(w_event!=scene_id) {
					if(w_event==-1) {
						exit=true;
					} else {
						scene_id=w_event;
					}
				}
			}
			ren->present();
			SDL_Delay(5);
		} while(!exit);
		SDL_StopTextInput();
	}
	void addScene(Scene* scene) {
		scenes.push_back(scene);
	}
	Renderer* getRenderer() { return ren; }
};

#endif
#endif
