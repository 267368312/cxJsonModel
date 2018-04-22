#include <XFSVDM.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfsvdm310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfsvdm320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfsvdm330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfsvdm;
#define TESTING_TYPES		Xfsvdm
#include "detection.hpp"