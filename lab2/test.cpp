#include "pch.h"
#include "tchar.h"
#include "gtest\gtest.h"
#include "..\lab2\Decart.h"
	// тестирование конструктора
TEST(DecartConstructor, DefaultConstructor) {
	Prog2::Decart a;
	ASSERT_EQ(1, a.getN());
}
	// тестирование сеттеров
TEST(DecartMethods, Setters) {
	Prog2::Decart a1;
	a1.setN(2);
	ASSERT_EQ(2, a1.getN());
}
	// тестирование остальных методов
TEST(DecartMethods, Parameters) {
	Prog2::Decart a2;
	const double PI = 3.14159, err = 0.00001;
	ASSERT_NEAR(0.707107, a2.square_side(), err);
	ASSERT_NEAR(0, a2.distance_center(0), err);
	ASSERT_NEAR(0.08838, a2.curvature_vertices(), err);
	ASSERT_NEAR(0.5, a2.curvature_node(), err);
	ASSERT_NEAR(0.16666, a2.square(), err);
	ASSERT_NEAR(0.32114, a2.max_diameter(), err);
	ASSERT_NEAR(0.40824, a2.distance_diameter(), err);
	a2.setN(2);
	ASSERT_NEAR(1.41421, a2.square_side(), err);
	ASSERT_NEAR(0.288812, a2.distance_center(3), err);
	ASSERT_NEAR(0.176777, a2.curvature_vertices(), err);
	ASSERT_NEAR(1, a2.curvature_node(), err);
	ASSERT_NEAR(0.66666, a2.square(), err);
	ASSERT_NEAR(0.64228, a2.max_diameter(), err);
	ASSERT_NEAR(0.81649, a2.distance_diameter(), err);
	a2.setN(-10.5);
	ASSERT_NEAR(-7.42462, a2.square_side(), err);
	ASSERT_NEAR(1.55584, a2.distance_center(-8), err);
	ASSERT_NEAR(-0.92807, a2.curvature_vertices(), err);
	ASSERT_NEAR(-5.25, a2.curvature_node(), err);
	ASSERT_NEAR(18.375, a2.square(), err);
	ASSERT_NEAR(-3.37202, a2.max_diameter(), err);
	ASSERT_NEAR(-4.28661, a2.distance_diameter(), err);

	ASSERT_STREQ("x^3 + y^3 = -10.50xy\n", a2.frm());
}

int _tmain1(int argc, _TCHAR* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
