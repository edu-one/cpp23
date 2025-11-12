/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include <cpp23.h>
#include <gtest/gtest.h>

using namespace dv::cpp23;

TEST(Bitmap2Test, PixelAccess) {
    Bitmap2 bmp;
    bmp.width = 4;
    bmp.height = 4;
    bmp.pixels.resize(bmp.width * bmp.height);

    // Set pixel at (1, 2)
    bmp(1, 2).r = 0.1f;
    bmp(1, 2).g = 0.2f;
    bmp(1, 2).b = 0.3f;
    bmp(1, 2).a = 0.4f;

    // Verify pixel at (1, 2)
    EXPECT_FLOAT_EQ(bmp(1, 2).r, 0.1f);
    EXPECT_FLOAT_EQ(bmp(1, 2).g, 0.2f);
    EXPECT_FLOAT_EQ(bmp(1, 2).b, 0.3f);
    EXPECT_FLOAT_EQ(bmp(1, 2).a, 0.4f);

    // Verify default pixel at (0, 0)
    EXPECT_FLOAT_EQ(bmp(0, 0).r, 0.0f);
    EXPECT_FLOAT_EQ(bmp(0, 0).g, 0.0f);
    EXPECT_FLOAT_EQ(bmp(0, 0).b, 0.0f);
    EXPECT_FLOAT_EQ(bmp(0, 0).a, 1.0f);
}