//#include "Entity.h"
//#include "gtest/gtest.h"
//#include "gmock/gmock.h"
//
//#include <memory>
//
//using ::testing::StartsWith;
//using ::testing::HasSubstr;
//
//TEST(EntityTestNoFixture, StringReprPrefixTest)
//{
//	const auto entity = std::make_unique<Entity>("Player_1", 120, 15);
//	const auto entityStringRepr = entity->getStringRepr();
//
//	EXPECT_THAT(entityStringRepr, StartsWith("Entity:"));
//}
//
//TEST(EntityTestNoFixture, StringReprStatsLabelsTest)
//{
//	const auto entity = std::make_unique<Entity>("Player_1", 120, 15);
//	const auto entityStringRepr = entity->getStringRepr();
//
//	EXPECT_THAT(entityStringRepr, HasSubstr("Stats:"));
//	EXPECT_THAT(entityStringRepr, HasSubstr("HP"));
//	EXPECT_THAT(entityStringRepr, HasSubstr("DMG"));
//}
