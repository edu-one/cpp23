/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */


#include <cpp23.h>
#include <gtest/gtest.h>

using namespace dv::cpp23;

TEST(Bitmap1Test, PixelAccess) {
    Bitmap1 bmp;
    bmp.width = 4;
    bmp.height = 4;
    bmp.pixels.resize(bmp.width * bmp.height);

    // Set pixel at (2, 3)
    bmp(2, 3).r = 1.0f;
    bmp(2, 3).g = 0.5f;
    bmp(2, 3).b = 0.25f;
    bmp(2, 3).a = 1.0f;

    // Verify pixel at (2, 3)
    EXPECT_FLOAT_EQ(bmp(2, 3).r, 1.0f);
    EXPECT_FLOAT_EQ(bmp(2, 3).g, 0.5f);
    EXPECT_FLOAT_EQ(bmp(2, 3).b, 0.25f);
    EXPECT_FLOAT_EQ(bmp(2, 3).a, 1.0f);

    // Verify default pixel at (0, 0)
    EXPECT_FLOAT_EQ(bmp(0, 0).r, 0.0f);
    EXPECT_FLOAT_EQ(bmp(0, 0).g, 0.0f);
    EXPECT_FLOAT_EQ(bmp(0, 0).b, 0.0f);
    EXPECT_FLOAT_EQ(bmp(0, 0).a, 1.0f);
}

// added corner case tests

TEST(Bitmap1Test, NegativeIndicesThrow) {
    Bitmap1 bmp;
    bmp.width = 4;
    bmp.height = 4;
    bmp.pixels.resize(bmp.width * bmp.height);

    EXPECT_THROW(bmp(-1, 0), std::out_of_range);
    EXPECT_THROW(bmp(0, -1), std::out_of_range);
    EXPECT_THROW(bmp(-5, -5), std::out_of_range);
}

TEST(Bitmap1Test, TooLargeIndicesThrow) {
    Bitmap1 bmp;
    bmp.width = 4;
    bmp.height = 4;
    bmp.pixels.resize(bmp.width * bmp.height);

    EXPECT_THROW(bmp(4, 0), std::out_of_range);
    EXPECT_THROW(bmp(0, 4), std::out_of_range);
    EXPECT_THROW(bmp(100, 100), std::out_of_range);
}

TEST(Bitmap1Test, CornerPixelsAccess) {
    Bitmap1 bmp;
    bmp.width = 4;
    bmp.height = 4;
    bmp.pixels.resize(bmp.width * bmp.height);

    // top-left
    EXPECT_FLOAT_EQ(bmp(0, 0).a, 1.0f);

    // bottom-right
    bmp(3, 3).r = 0.7f;
    EXPECT_FLOAT_EQ(bmp(3, 3).r, 0.7f);
}

TEST(Bitmap1Test, ConstAccessAndBounds) {
    Bitmap1 bmp;
    bmp.width = 2;
    bmp.height = 2;
    bmp.pixels.resize(bmp.width * bmp.height);

    bmp(1, 1).g = 0.33f;
    const Bitmap1& cbmp = bmp;

    EXPECT_FLOAT_EQ(cbmp(1, 1).g, 0.33f);
    EXPECT_THROW(cbmp(2, 0), std::out_of_range);
}

TEST(Bitmap1Test, ZeroSizeBitmapThrows) {
    Bitmap1 bmp;
    bmp.width = 0;
    bmp.height = 0;
    bmp.pixels.clear();

    EXPECT_THROW(bmp(0, 0), std::out_of_range);
}
