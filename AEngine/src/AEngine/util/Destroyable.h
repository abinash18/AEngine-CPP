#pragma once
#include "AEngine/Core.h"

namespace AEngine {
	class Destroyable {
		public:
			Destroyable() {};
			~Destroyable() {};
			virtual void destroy() = 0;
	};
}
