#pragma once

#include <cmath>

class MathVec2 {
    public:
        template<template<typename> class Vec2Type, typename T>
            static T length(Vec2Type<T> v) {
                return sqrt(v.x * v.x + v.y * v.y);
            }
};
