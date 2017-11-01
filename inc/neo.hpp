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
#ifndef _NeoGui
#define _NeoGui
	#if __cplusplus > 199711L
		#include <string>
		#include <vector>
		#include <array>
		#include <fstream>
		#include <iostream>
		
		#ifndef _SDL_H
			#ifndef _WIN32
				#include <SDL2/SDL.h>
				#include <SDL2/SDL_ttf.h>
				#include <SDL2/SDL_image.h>
				std::string SEPERATOR="/";
			#else
				#include <SDL.h>
				#include <SDL_ttf.h>
				#include <SDL_image.h>
				std::string SEPERATOR="\\";				
			#endif
		#endif
		
		#define NANOSVG_IMPLEMENTATION
	    #include "lib/nanosvg/src/nanosvg.h"
	    #define NANOSVGRAST_IMPLEMENTATION
	    #include "lib/nanosvg/src/nanosvgrast.h"

		namespace Neo {
			inline void initSDL(Uint32 sdl_flags,int img_flags) {
				SDL_Init(sdl_flags);
				TTF_Init();
				IMG_Init(img_flags);
			}
			inline void quitSDL() {
				TTF_Quit();
				IMG_Quit();
				SDL_Quit();
			}
			#include "neo-const.hpp"
			#include "neo-style.hpp"
			#include "neo-mouse.hpp"
			#include "neo-renderer.hpp"
			#include "neo-font.hpp"
			#include "neo-svg.hpp"
			#include "neo-widget.hpp"
			/*widgets*/
			#include "widgets/neo-label.hpp"
			#include "widgets/neo-button.hpp"
			#include "widgets/neo-checkbutton.hpp"
			#include "widgets/neo-image.hpp"
			#include "widgets/neo-container.hpp"
			/*main*/
			#include "neo-scene.hpp"
			#include "neo-wnd.hpp"
		}
		
	#else 
		#define error_cpp_version	
	#endif
#endif
