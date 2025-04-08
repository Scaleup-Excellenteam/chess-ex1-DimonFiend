#pragma once

namespace Utility {
	const char stringToUpperChar(char c) {
		if (c >= 'a' && c <= 'z') {
			return c - ('a' - 'A');
		}
		return c;
	}
}
