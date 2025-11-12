/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg== 
 */

#ifndef __DV_INCLUDE_CPP23_H__
#define __DV_INCLUDE_CPP23_H__

#include <vector>
#include <stdexcept>
#include <concepts>

namespace dv::cpp23 {
    

    struct Color
    {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        float a = 1.0f;
    };

    struct Bitmap1
    {
        int width = 1024;
        int height = 768;
        std::vector<Color> pixels = std::vector<Color>(width * height);

        // multidimensional subscript operator usage
        Color& operator()(int x, int y) {
            if (x < 0 || x >= width || y < 0 || y >= height)
                throw std::out_of_range("Bitmap1 pixel coordinates out of range");
            return pixels[y * width + x];
        }

        const Color& operator()(int x, int y) const {
            if (x < 0 || x >= width || y < 0 || y >= height)
                throw std::out_of_range("Bitmap1 pixel coordinates out of range");
            return pixels[y * width + x];
        }

    };

    struct Bitmap2
    {
        int width = 1024;
        int height = 768;
        std::vector<Color> pixels = std::vector<Color>(width * height);

        // multidimensional subscript operator with deducing this
        template<typename Self>
        requires std::same_as<std::remove_cvref_t<Self>, Bitmap2>
        auto&& operator()(this Self&& self, int x, int y) {
            if (x < 0 || x >= self.width || y < 0 || y >= self.height)
                throw std::out_of_range("Bitmap2 pixel coordinates out of range");
            return std::forward<Self>(self).pixels[y * self.width + x];
        }

    };
} // namespace dv::cpp23

#endif // __DV_INCLUDE_CPP23_H__
