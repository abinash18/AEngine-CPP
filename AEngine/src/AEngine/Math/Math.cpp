#include "aepch.h"
#include "Math.h"

namespace AEngine {
	float fast_inv_sqrt(const float _value) {
		long        i;
		float       x2, y;
		const float threehalfs = 1.5F;

		x2 = _value * 0.5F;
		y  = _value;
		i  = *(long*)&y;            // evil floating point bit level hacking
		i  = 0x5f3759df - (i >> 1); // what the fuck? 
		y  = *(float*)&i;
		y  = y * (threehalfs - (x2 * y * y)); // 1st iteration
		//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

		return y;
	}

}


