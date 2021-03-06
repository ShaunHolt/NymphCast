

#ifndef SDL_RENDERER_H
#define SDL_RENDERER_H

#include "types.h"

#include <string>

#include <SDL2/SDL_image.h>


class SdlRenderer {
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static SDL_Texture* texture;
	//static SDL_RendererInfo renderer_info;
	//static SDL_AudioDeviceID audio_dev;
	
	static void fill_rectangle(int x, int y, int w, int h);
	static int realloc_texture(SDL_Texture **texture, Uint32 new_format, int new_width, 
								int new_height, SDL_BlendMode blendmode, int init_texture);
	static int upload_texture(SDL_Texture **tex, AVFrame *frame, struct SwsContext **img_convert_ctx);
	
public:
	static bool init();
	static void quit();
	static void resizeWindow(int width, int height);
	static void set_default_window_size(int width, int height, AVRational sar);
	static void set_fullscreen(bool fullscreen);
	static void video_display(VideoState *is);
	static void image_display(std::string image);
	static void video_audio_display(VideoState *s);
	static void video_image_display(VideoState *is);
};


#endif