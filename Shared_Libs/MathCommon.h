#ifndef MATHCOMMON_H
#define MATHCOMMON_H

#include <cstdarg>
#include <cmath>
#include <limits>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <limits>


#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace TDS
{
    class Vec2;
    class Mathf
    {
        public:
        static float Sin(float f) { return sinf(f); }
        static float Cos(float f) { return cosf(f); }
        static float Tan(float f) { return tanf(f); }
        static float Asin(float f) { return asinf(f); }
        static float Acos(float f) { return acosf(f); }
        static float Atan(float f) { return atanf(f); }
        static float Atan2(float y, float x) { return atan2f(y, x); }
        static float Sqrt(float f) { return sqrtf(f); }
        static float Abs(float f) { return fabsf(f); }
        static int Abs(int value) { return abs(value); }
        static float Min(float a, float b) { return fminf(a, b); }
        static float Min(float count, ...)
        {
            if (count == 0) 
                return 0;
            va_list args;
            va_start(args, count);
            float min = va_arg(args, float);

            for (int i = 1; i < count; i++)
            {
                float f = va_arg(args, float);
                if (f < min) 
                    min = f;
            }
            va_end(args);
            return min;
        }
        static float Min (float values[], int count)
        {
            if (count == 0)
                return 0;
            float min = values[0];
            for (int i = 1; i < count; i++)
            {
                if (values[i] < min)
                    min = values[i];
            }
            return min;
        }

        static int Min(int a, int b) { return (std::min)(a, b); }

        static int Min(int count, ...)
        {
            if (count == 0)
                return 0;
            va_list args;
            va_start(args, count);
            int min = va_arg(args, int);

            for (int i = 1; i < count; i++)
            {
                int f = va_arg(args, int);
                if (f < min)
                    min = f;
            }
            va_end(args);
            return min;

        }
        static int Min(int values[], int count)
        {
            if (count == 0)
                return 0;
            int min = values[0];
            for (int i = 1; i < count; i++)
            {
                if (values[i] < min)
                    min = values[i];
            }
            return min;
        }
        static float Max(float a, float b) { return fmaxf(a, b); }
        static float Max(float count, ...)
        {
            if (count == 0)
                return 0;
            va_list args;
            va_start(args, count);
            float max = va_arg(args, float);

            for (int i = 1; i < count; i++)
            {
                float f = va_arg(args, float);
                if (f > max)
                    max = f;
            }
            va_end(args);
            return max;
        }
        static float Max(float values[], int count)
        {
            if (count == 0)
                return 0;
            float max = values[0];
            for (int i = 1; i < count; i++)
            {
                if (values[i] > max)
                    max = values[i];
            }
            return max;
        }

        static int Max(int a, int b) { return (std::max)(a, b); }

        static int Max(int count, ...)
        {
            if (count == 0)
                return 0;
            va_list args;
            va_start(args, count);
            int max = va_arg(args, int);

            for (int i = 1; i < count; i++)
            {
                int f = va_arg(args, int);
                if (f > max)
                    max = f;
            }
            va_end(args);
            return max;
        }
        static int Max(int values[], int count)
        {
            if (count == 0)
                return 0;
            int max = values[0];
            for (int i = 1; i < count; i++)
            {
                if (values[i] > max)
                    max = values[i];
            }
            return max;
        }
        static float Pow(float f, float p) { return powf(f, p); }
        static float Exp(float power) { return expf(power); }
        static float Log(float f, float p) { return logf(f) / logf(p); }
        static float Log(float f) { return logf(f); }
        static float Log10(float f) { return log10f(f); }
        static float Ceil(float f) { return ceilf(f); }
        static float Floor(float f) { return floorf(f); }
        static float Round(float f) { return roundf(f); }
        static int CeilToInt(float f) { return (int)ceilf(f); }
        static int FloorToInt(float f) { return (int)floorf(f); }
        static int RoundToInt(float f) { return (int)roundf(f); }
        static float Sign(float f) { return (f == 0.f) ? 0.f : ((f > 0.f) ? 1.f : -1.f); }
        
        static constexpr float PI = 3.1415926535897931f;
        static constexpr float Infinity = std::numeric_limits<float>::infinity();
        static constexpr float NegativeInfinity = -std::numeric_limits<float>::infinity();
        static constexpr float Deg2Rad = PI  / 180.0f;
        static constexpr float Rad2Deg = 1.0f / Deg2Rad;
        
        // Max number of decimals to display when converting to string
        const int kMaxDecimals = 15; 
        // A tiny floating point value (Read Only).
        static constexpr float Epsilon = std::numeric_limits<float>::epsilon();
        
        // Clamps a value between a minimum float and maximum float value.
        static float Clamp(float value, float min, float max);
        static float Clamp(int value, int min, int max);
        // Clamps value between 0 and 1 and returns value.
        static float Clamp01(float value);

        // Linearly interpolates between a and b by t. t is clamped between 0 and 1.
        static float Lerp(float a, float b, float t);
       
        // Linearly interpolates between a and b by t. t is not clamped.
        static float LerpUnclamped(float a, float b, float t);

        // Same as Lerp but makes sure the values interpolate correctly when they wrap around 360 degrees.
        static float LerpAngle(float a, float b, float t);
        
        // Moves a value current towards target.
        static float MoveTowards(float current, float target, float maxDelta);
        
        // Same as MoveTowards but makes sure the values interpolate correctly when they wrap around 360 degrees.
        static float MoveTowardsAngle(float current, float target, float maxDelta);

        // Interpolates between min and max with smoothing at the limits.
        static float SmoothStep(float from, float to, float t);

        // undocumented
        static float Gamma(float value, float absmax, float gamma);

        // Compares two floating point values if they are similar.
        static bool Approximately(float a, float b);

        // Loops the value t, so that it is never larger than length and never smaller than 0.
        static float Repeat(float t, float length);

        // PingPongs the value t, so that it is never larger than length and never smaller than 0.
        static float PingPong(float t, float length);

        // Calculates the linear parameter t that produces the interpolant value within the range [a, b].
        static float InverseLerp(float a, float b, float value);

        // Calculates the shortest difference between two given angles given in degrees.
        static float DeltaAngle(float current, float target);
    
        // Infinite Line Intersection (line1 is p1-p2, line2 is p3-p4)
        static bool LineIntersection(const Vec2& p1, const Vec2& p2, const Vec2& p3, const Vec2& p4, Vec2& result);

        // Line Segment Intersection (line1 is p1-p2, line2 is p3-p4)
        static bool LineSegmentIntersection(const Vec2& p1, const Vec2& p2, const Vec2& p3, const Vec2& p4, Vec2& result);

    };
}


#endif // MATH_H