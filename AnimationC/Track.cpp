#include "Track.h"

namespace TrackHelpers {
	inline float Interpolate(float a, float b, float t)
	{
		return a + (b - a) * t;
	}

	inline vec3 Interpolate(const vec3& a, const vec3& b, float t)
	{
		return lerp(a, b, t);
	}

	inline quat Interpolate(const quat& a, const quat& b, float t)
	{
		quat result = mix(a, b, t);
		if (dot(a, b) < 0) {//Neighborhood
			result = mix(a, -b, t);
		}

		return normalized(result); //NLerp, not slerp
	}

	inline float AdjustHermiteResult(float f)
	{
		return f;
	}

	inline vec3 AdjustHermiteResult(const vec3& v)
	{
		return v;
	}

	inline quat AdjustHermiteResult(const quat& q)
	{
		return normalized(q);
	}

	inline void Neighborhood(const float& a, float& b) {}
	inline void Neighborhood(const vec3& a, vec3& b) {}
	inline void Neighborhood(const quat& a, quat& b)
	{
		if (dot(a, b) < 0)
		{
			b = -b;
		}
	}
}; // End Track Helpers

template<typename T, int N>
Track<T, N>::Track()
{
	mInterpolation = Interpolation::Linear;
}
template<typename T, int N>
float Track<T, N>::GetStartTime()
{
	return mFrames[0].mTime;
}

template<typename T, int N>
float Track<T, N>::GetEndTime()
{
	return m_Frames[mFramces.size() - 1].mTime;
}

