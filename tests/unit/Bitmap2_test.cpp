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

TEST(Bitmap2Test, NegativeIndicesThrow) {
    Bitmap2 bmp;
    bmp.width = 4;
    bmp.height = 4;
    bmp.pixels.resize(bmp.width * bmp.height);

    EXPECT_THROW(bmp(-1, 0), std::out_of_range);
    EXPECT_THROW(bmp(0, -1), std::out_of_range);
    EXPECT_THROW(bmp(-5, -5), std::out_of_range);
}

TEST(Bitmap2Test, FirstExists) {
    Bitmap2 bmp;
    bmp.width = 4;
    bmp.height = 4;
    bmp.pixels.resize(bmp.width * bmp.height);

    bmp(0, 0).r = 0.5f;
    bmp(0, 0).g = 0.6f;
    bmp(0, 0).b = 0.7f;
    bmp(0, 0).a = 0.8f;

    auto result = bmp.first();
    ASSERT_TRUE(result.has_value());
    EXPECT_FLOAT_EQ(result->r, 0.5f);
    EXPECT_FLOAT_EQ(result->g, 0.6f);
    EXPECT_FLOAT_EQ(result->b, 0.7f);
    EXPECT_FLOAT_EQ(result->a, 0.8f);
}

TEST(Bitmap2Test, FirstEmpty) {
    Bitmap2 bmp;
    bmp.width = 0;
    bmp.height = 0;
    bmp.pixels.clear();

    auto result = bmp.first();
    ASSERT_FALSE(result.has_value());
    EXPECT_EQ(result.error(), Bitmap2::Error::OutOfRange);
}
TEST(Bitmap2Test, TooLargeIndicesThrow) {
    Bitmap2 bmp;
    bmp.width = 4;
    bmp.height = 4;
    bmp.pixels.resize(bmp.width * bmp.height);

    EXPECT_THROW(bmp(4, 0), std::out_of_range);
    EXPECT_THROW(bmp(0, 4), std::out_of_range);
    EXPECT_THROW(bmp(100, 100), std::out_of_range);
}

TEST(Bitmap2Test, CornerPixelsAccess) {
    Bitmap2 bmp;
    bmp.width = 4;
    bmp.height = 4;
    bmp.pixels.resize(bmp.width * bmp.height);

    // top-left
    EXPECT_FLOAT_EQ(bmp(0, 0).a, 1.0f);

    // bottom-right
    bmp(3, 3).r = 0.7f;
    EXPECT_FLOAT_EQ(bmp(3, 3).r, 0.7f);
}
