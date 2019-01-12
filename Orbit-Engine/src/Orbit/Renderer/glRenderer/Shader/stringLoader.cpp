#include "obtpch.h"
#include <iostream>

#include <fstream>

#include "stringLoader.hpp"

std::string load(const char* path) {
	std::fstream stream(path, std::fstream::in);
	if (!stream) {
		ORBIT_CORE_ERROR("Failed to load the filepath {0}.", path);
		getchar();
	}

	std::string finalString;
	
	std::getline(stream, finalString, '\0');

	stream.close();
	return std::string(finalString.c_str());
}