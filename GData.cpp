#include "GData.hpp"

namespace eth
{
	namespace GData
	{
		// Game variables
		int              mouse_x  =              0;     // mouse x
		int              mouse_y  =              0;     // mouse y
		float            view_x   =              0;     // view x
		float            view_y   =              0;     // view y
		unsigned         w_x      =              0;     // window x
		unsigned         w_y      =              0;     // window y
		unsigned         w_width  =           1366;     // window width
		unsigned         w_height =            768;     // window height
		unsigned         r_width  =           1366;     // resolution width
		unsigned         r_height =            768;     // resolution height
		unsigned         d_width  =              0;     // desktop resolution width
		unsigned         d_height =              0;     // desktop resolution height
		float            ppm      =             64;     // pixels per (box2d) meter
		bool             paused   =          false;     // game paused

		// Game data
		AssetManager                        assets;     // loader of assets

		// Map data
		int              chunk_size  =          16;     // size of chunk in tiles
		int              chunk_rows  =          16;     // number of rows of chunks
		int              chunk_cols  =          16;     // number of cols of chunks
		float            t_size      =          64;     // tile size

		// View data
		float            min_view_x =            0;     // Minimum view x coord
		float            min_view_y =            0;     // Minimum view y coord
		float            max_view_x =            0;     // Maximum view x coord
		float            max_view_y =            0;     // Maximum view y coord

		// Calculation data
		const float PI = static_cast<float>(std::atan(1)*4);    // 3.14159265358979...
	}
}