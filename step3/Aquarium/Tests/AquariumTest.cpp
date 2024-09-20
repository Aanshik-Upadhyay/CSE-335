#include <pch.h>
#include "gtest/gtest.h"
#include <Aquarium.h>
#include <FishBeta.h>
using namespace std;


TEST(AquariumTest, HitTest) {
    Aquarium aquarium;

    ASSERT_EQ(aquarium.HitTest(100, 200), nullptr) <<
        L"Testing empty aquarium";

    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    aquarium.Add(fish1);
    fish1->SetLocation(100, 200);

    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish1) <<
        L"Testing fish1 at 100, 200";

    shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);

    aquarium.Add(fish2);

    fish2->SetLocation(100, 200);

    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish2) <<
        L"Testing fish2 on top of fish1 at 100, 200";


    ASSERT_EQ(aquarium.HitTest(300, 300), nullptr) <<
        L"Testing click on empty area in populated aquarium";
}