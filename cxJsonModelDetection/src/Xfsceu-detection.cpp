#include <XFSCEU.h>
#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfsceu310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfsceu320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfsceu330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfsceu;


#define TESTING_TYPES		Xfsceu

#include "detection.hpp"