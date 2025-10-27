#pragma once
#ifndef GEODESY_IO_FONT_H
#define GEODESY_IO_FONT_H

#include <string>

// #include "../../config.h"

// #include "../io/file.h"
#include <geodesy/gpu/image.h>

namespace geodesy::gfx {

	// Rename class to typeface?
	class font /* : public io::file */ {
	public:

		/*

		texture SymbolSet;

		int m, n, l;
		void *hptr;
		float *sx;
		float *sy;
		float *bx;
		float *by;
		float *ax;
		float *ay;

		font();
		~font();

		bool read(const char* Path);
		bool load();
		bool clear();
		*/

		font();
		font(std::string aFilePath);
		font(const char* aFilePath);

		~font();

	private:

		static bool initialize();
		static bool terminate();

		int m, n, l;
		void* hptr;
		float* sx;
		float* sy;
		float* bx;
		float* by;
		float* ax;
		float* ay;

		gpu::image Symbol;

		void zero_out();

	};

}

#endif // !GEODESY_IO_FONT_H
