//-------------------------------------------------------------------------------//
//                         QUIMERA ENGINE : LICENSE                              //
//-------------------------------------------------------------------------------//
// This file is part of Quimera Engine.                                          //
// Quimera Engine is free software: you can redistribute it and/or modify        //
// it under the terms of the Lesser GNU General Public License as published by   //
// the Free Software Foundation, either version 3 of the License, or             //
// (at your option) any later version.                                           //
//                                                                               //
// Quimera Engine is distributed in the hope that it will be useful,             //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// Lesser GNU General Public License for more details.                           //
//                                                                               //
// You should have received a copy of the Lesser GNU General Public License      //
// along with Quimera Engine. If not, see <http://www.gnu.org/licenses/>.        //
//                                                                               //
// This license doesn't force you to put any kind of banner or logo telling      //
// that you are using Quimera Engine in your project but we would appreciate     //
// if you do so or, at least, if you let us know about that.                     //
//                                                                               //
// Enjoy!                                                                        //
//                                                                               //
// Kinesis Team                                                                  //
//-------------------------------------------------------------------------------//

#ifndef __SQANGLE__
#define __SQANGLE__

#include <string>

#include "MathDefinitions.h"

using Kinesis::QuimeraEngine::Tools::DataTypes::float_q;


namespace Kinesis
{
namespace QuimeraEngine
{
namespace Tools
{
namespace Math
{

/// <summary>
/// Helper class that offers functionality related to angles (radians and degrees).<br/>
/// Use constant angle values as far as you can in your code.
/// </summary>
class QDllExport SQAngle
{
    // CONSTANTS
    // ---------------
public:

    /// <summary>
    /// 45 degrees angle.
    /// </summary>
    static const float_q _45;

    /// <summary>
    /// 90 degrees angle.
    /// </summary>
    static const float_q _90;

    /// <summary>
    /// 180 degrees angle.
    /// </summary>
    static const float_q _180;

    /// <summary>
    /// 15 degrees angle.
    /// </summary>
    static const float_q _15;

    /// <summary>
    /// 30 degrees angle.
    /// </summary>
    static const float_q _30;

    /// <summary>
    /// 60 degrees angle.
    /// </summary>
    static const float_q _60;

    /// <summary>
    /// 270 degrees angle.
    /// </summary>
    static const float_q _270;

    /// <summary>
    /// 360 degrees angle.
    /// </summary>
    static const float_q _360;

    /// <summary>
    /// Half Pi radians angle (\f$ \frac{\pi}{2} \f$).
    /// </summary>
    static const float_q _HalfPi;

    /// <summary>
    /// A quarter of Pi radians angle (\f$ \frac{\pi}{4} \f$).
    /// </summary>
    static const float_q _QuarterPi;

    /// <summary>
    /// Third part of Pi radians angle (\f$ \frac{\pi}{3} \f$).
    /// </summary>
    static const float_q _ThirdPi;

    /// <summary>
    /// 2 Pi radians angle (\f$ 2\pi \f$).
    /// </summary>
    static const float_q _2Pi;

    /// <summary>
    /// Pi radians angle (\f$ \pi \f$).
    /// </summary>
    static const float_q _Pi;

    /// <summary>
    /// 3 halfs of Pi radians angle (\f$ \frac{3\pi}{2} \f$).
    /// </summary>
    static const float_q _3HalfsPi;

    /// <summary>
    /// Defines how many degrees are equivalent to 1 radian, and how much accurate is that value.
    /// </summary>
    static const float_q DegreesPerRadian;

    /// <summary>
    /// Defines how many radians are equivalent to 1 degree, and how much accurate is that value.
    /// </summary>
    static const float_q RadiansPerDegree;


	// CONSTRUCTORS
	// ---------------
private:

	// <summary>
	// Default constructor (hidden).
	// </summary>
	SQAngle();


	// METHODS
	// ---------------
public:

    /// <summary>
    /// Computes the conversion from a value expressed in degrees to its equivalent in radians.
    /// </summary>
    /// <param name="fDegrees">[IN] The angle measured in degrees.</param>
    /// <returns>
    /// The same angle converted to radians.
    /// </returns>
    inline static float_q DegreesToRadians(const float_q &fDegrees)
    {
        return fDegrees * SQAngle::RadiansPerDegree;
    }

    /// <summary>
    /// Computes the conversion from a value expressed in radians to its equivalent in degrees.
    /// </summary>
    /// <param name="fRadians">[IN] The angle measured in radians.</param>
    /// <returns>
    /// The same angle converted to degrees.
    /// </returns>
    inline static float_q RadiansToDegrees(const float_q &fRadians)
    {
        return fRadians * SQAngle::DegreesPerRadian;
    }

    /// <summary>
    /// Truncates an angle which describes more than one revolution.<br/>
    /// If the angle value is greater than one revolution positive angle or lower than one revolution negative angle, then it will be adjusted to remain into that interval.
    /// </summary>
    /// <param name="fAngle">[IN] The original angle value</param>
    /// <returns>
    /// The truncated angle value.
    /// </returns>
    inline static float_q Truncate(const float_q &fAngle)
	{
		#if QE_CONFIG_ANGLENOTATION_DEFAULT == QE_CONFIG_ANGLENOTATION_RADIANS
			return fmod_q(fAngle, SQAngle::_2Pi);  
		#elif QE_CONFIG_ANGLENOTATION_DEFAULT == QE_CONFIG_ANGLENOTATION_DEGREES
			return fmod_q(fAngle, SQAngle::_360);
		#endif
    }

    /// <summary>
    /// Counts how many revolutions are represented by an angle, including fractions.
    /// </summary>
    /// <param name="fAngle">[IN] The angle value.</param>
    /// <returns>
    /// The number of revolutions (partial and complete).
    /// </returns>
    inline static float_q CountRevolutions(const float_q &fAngle)
    {
        const float_q COMPLETE_REVOLUTION =
            #if QE_CONFIG_ANGLENOTATION_DEFAULT == QE_CONFIG_ANGLENOTATION_RADIANS
                SQAngle::_2Pi;
            #elif QE_CONFIG_ANGLENOTATION_DEFAULT == QE_CONFIG_ANGLENOTATION_DEGREES
                SQAngle::_360;
            #endif

        return fAngle / COMPLETE_REVOLUTION;
    }

    /// <summary>
    /// Counts how many revolutions are represented by an angle, ignoring fractions.
    /// </summary>
    /// <param name="fAngle">[IN] The angle value.</param>
    /// <returns>
    /// The number of revolutions (only complete).
    /// </returns>
    inline static float_q CountCompleteRevolutions(const float_q &fAngle)
    {
        const float_q COMPLETE_REVOLUTION =
            #if QE_CONFIG_ANGLENOTATION_DEFAULT == QE_CONFIG_ANGLENOTATION_RADIANS
                SQAngle::_2Pi;
            #elif QE_CONFIG_ANGLENOTATION_DEFAULT == QE_CONFIG_ANGLENOTATION_DEGREES
                SQAngle::_360;
            #endif

        return SQFloat::Truncate(fAngle / COMPLETE_REVOLUTION);
    }
};

} //namespace Math
} //namespace Tools
} //namespace QuimeraEngine
} //namespace Kinesis

#endif // __SQANGLE__
