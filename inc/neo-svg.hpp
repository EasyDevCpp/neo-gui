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
#ifndef _NeoSVG
#define _NeoSVG

class SVG {
private:
	SDL_Surface *svg_sur;
	
public:
	SVG() {
		//Empty
	}
	SVG(std::string file,float scale=1) {
		NSVGimage *image=NULL;
  	    NSVGrasterizer *rast=NULL;
        unsigned char *pixel_data=NULL;
        int w=0;
        int h=0;
        image=nsvgParseFromFile(file.c_str(),"px",96.0f);
        if(image!=NULL) {
            w=(int)image->width;
  	        h=(int)image->height;
  	        rast=nsvgCreateRasterizer();
  	        pixel_data=(unsigned char*)malloc(w*h*4);
  	        nsvgRasterize(rast,image,0,0,scale,pixel_data,w,h,w*4);
            svg_sur=SDL_CreateRGBSurfaceFrom((void*)pixel_data,w,h,32,4*w,0x000000ff,0x0000ff00,0x00ff0000,0xff000000);
  		    SDL_SetSurfaceBlendMode(svg_sur,SDL_BLENDMODE_BLEND);
        } else {
            SDL_SetError("Unable to load SVG Image!");
        }
	}
	~SVG() {
        SDL_FreeSurface(svg_sur);
	}
	SDL_Surface *getSurface() {
	    return svg_sur;
	}
	void setSVG(std::string file,float scale=1) {
        NSVGimage *image=NULL;
        NSVGrasterizer *rast=NULL;
        unsigned char *pixel_data=NULL;
        int w=0;
        int h=0;
        image=nsvgParseFromFile(file.c_str(),"px",96.0f);
        if(image!=NULL) {
            w=(int)image->width;
          	h=(int)image->height;
          	rast=nsvgCreateRasterizer();
          	pixel_data=(unsigned char*)malloc(w*h*4);
          	nsvgRasterize(rast,image,0,0,scale,pixel_data,w,h,w*4);
            svg_sur=SDL_CreateRGBSurfaceFrom((void*)pixel_data,w,h,32,4*w,0x000000ff,0x0000ff00,0x00ff0000,0xff000000);
            SDL_SetSurfaceBlendMode(svg_sur,SDL_BLENDMODE_BLEND);
        } else {
            SDL_SetError("Unable to load SVG Image!");
        }
    }
};

#endif
#endif
