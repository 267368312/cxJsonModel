#include <cxJsonModel.h>
#include <string>

#define DEFINE_TEST_CLASS(types) _DEFINE_TEST_CLASS(types)
#define _DEFINE_TEST_CLASS(types) \
template<typename T> \
class types## Detection : public testing::Test{ \
public:types## Detection(){ memset(&value, 0x00, sizeof(value)); } \
protected:T value; \
}

#define IMPLEMENT_TYPED_TEST(types) _IMPLEMENT_TYPED_TEST(types)
#define _IMPLEMENT_TYPED_TEST(types) \
	TYPED_TEST_CASE(types## Detection, types); \
	TYPED_TEST(types## Detection, types)


DEFINE_TEST_CLASS(TESTING_TYPES);
IMPLEMENT_TYPED_TEST(TESTING_TYPES)
{
	std::string name = typeid(this->value).name();
	name = name.erase(0, strlen("struct "));
	EXPECT_EQ(sizeof(value), cxGetObjectSize(name.c_str()));
}