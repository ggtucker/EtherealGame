#ifndef GDATA_HPP
#define GDATA_HPP

#include <map>
#include <cmath>
#include <string>
#include "AssetManager.hpp"

namespace eth
{
	namespace GData
	{
		// Game variables
		extern int                mouse_x;      // mouse x
		extern int                mouse_y;      // mouse y
		extern float              view_x;       // view x
		extern float              view_y;       // view y
		extern unsigned           w_x;          // window x
		extern unsigned           w_y;          // window y
		extern unsigned           w_width;      // window width
		extern unsigned           w_height;     // window height
		extern unsigned           r_width;      // resolution width
		extern unsigned           r_height;     // resolution height
		extern unsigned           d_width;      // desktop resolution width
		extern unsigned           d_height;     // desktop resolution height
		extern float              ppm;          // pixels per (box2d) meter
		extern bool               paused;       // game paused

		// Game data
		extern AssetManager       assets;       // loader of assets

		// Map data
		extern int                chunk_size;   // size of chunk in tiles
		extern int                chunk_rows;   // number of rows of chunks
		extern int                chunk_cols;   // number of cols of chunks
		extern float              t_size;       // tile size

		// View data
		extern float              min_view_x;   // Minimum view x coord
		extern float              min_view_y;   // Minimum view y coord
		extern float              max_view_x;   // Maximum view x coord
		extern float              max_view_y;   // Maximum view y coord

		// Calculation data
		extern const float        PI;           // 3.14159265358979...
	}
}

#endif