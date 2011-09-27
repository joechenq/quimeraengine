// [TERMS&CONDITIONS]

#ifndef __QINTEGER__
#define __QINTEGER__

#include <string>
#include <cstdlib>

#include <boost\lexical_cast.hpp>

#include "DataTypesDefinitions.h"


namespace Kinesis
{
namespace QuimeraEngine
{
namespace Tools
{
namespace DataTypes
{

/// <summary>
/// Helper class that offers functionality related to integer types.
/// Use these static methods extensively in your code, as far as you can.
/// </summary>
class QDllExport QInteger
{

	// CONSTRUCTORS
	// ---------------
private:

	// Default constructor (hidden).
	QInteger();


	// METHODS
	// ---------------
public:

    /// <summary>
    /// Returns the absolute value of an 8-bit integer value.
    /// </summary>
    /// <param name="nValue">[IN] An 8-bit integer value to extract its absolute value.</param>
    /// <returns>
    /// The absolute value, expressed as an 8-bit integer.
    /// </returns>
    inline static i8_q Abs(i8_q& nValue)
    {
       return abs(nValue);
    }

    /// <summary>
    /// Returns the absolute value of an 8-bit integer value.
    /// </summary>
    /// <param name="nValue">[IN] An 8-bit integer value to extract its absolute value.</param>
    /// <param name="nOutput">[OUT] The absolute value.</param>
    inline static void Abs(const i8_q& nValue, i8_q& nOutput)
    {
       nOutput = abs(nValue);
    }

    /// <summary>
    /// Returns the absolute value of a short integer value.
    /// </summary>
    /// <param name="nValue">[IN] A short integer value to extract its absolute value.</param>
    /// <returns>
    /// The absolute value, expressed as a short integer.
    /// </returns>
    inline static i16_q Abs(const i16_q& nValue)
    {
       return abs(nValue);
    }

    /// <summary>
    /// Returns the absolute value of a short integer value.
    /// </summary>
    /// <param name="nValue">[IN] A short integer value to extract its absolute value.</param>
    /// <param name="nOutput">[OUT] The absolute value.</param>
    inline static void Abs(const i16_q& nValue, i16_q& nOutput)
    {
       nOutput = abs(nValue);
    }

    /// <summary>
    /// Returns the absolute value of an integer value.
    /// </summary>
    /// <param name="nValue">[IN] An integer value to extract its absolute value.</param>
    /// <returns>
    /// The absolute value, expressed as an integer.
    /// </returns>
    inline static i32_q Abs(const i32_q& nValue)
    {
       return abs(nValue);
    }

    /// <summary>
    /// Returns the absolute value of an integer value.
    /// </summary>
    /// <param name="nValue">[IN] An integer value to extract its absolute value.</param>
    /// <param name="nOutput">[OUT] The absolute value.</param>
    inline static void Abs(const i32_q& nValue, i32_q& nOutput)
    {
       nOutput = abs(nValue);
    }

    /// <summary>
    /// Returns the absolute value of a long integer value.
    /// </summary>
    /// <param name="nValue">[IN] A long integer value to extract its absolute value.</param>
    /// <returns>
    /// The absolute value, expressed as a long integer.
    /// </returns>
    inline static i64_q Abs(const i64_q& nValue)
    {
	   return llabs(nValue);
    }

    /// <summary>
    /// Returns the absolute value of a long integer value.
    /// </summary>
    /// <param name="nValue">[IN] A long integer value to extract its absolute value.</param>
    /// <param name="nOutput">[OUT] The absolute value.</param>
    inline static void Abs(const i64_q& nValue, i64_q& nOutput)
    {
	   nOutput = llabs(nValue);
    }

    /// <summary>
    /// Inverts the order of bytes which compound an integer number. A 32-bits integer number
    /// whose value equals to 0xAABBCCDD will be transformed to 0xDDCCBBAA, for example.
    /// </summary>
    /// <param name="nValue">[IN/OUT] The value whose bytes are to be swapped.</param>
    template<typename IntegerType>
    inline static void SwapEndianess(IntegerType &nValue)
    {
        QInteger::SwapEndianess(nValue, nValue);
    }

    /// <summary>
    /// Inverts the order of bytes which compound an integer number and returns the result as
    /// output parameter. A 32-bits integer number whose value equals to 0xAABBCCDD will be
    /// transformed to 0xDDCCBBAA, for example.
    /// </summary>
    /// <param name="nValue">[IN] The value whose bytes are to be swapped.</param>
    /// <param name="nSwappedValue">[OUT] The transformed value.</param>
    template<typename IntegerType>
    inline static void SwapEndianess(const IntegerType &nValue, IntegerType &nSwappedValue)
    {
        const unsigned int INTEGER_SIZE = sizeof(IntegerType);

        // Ambiguous type to treat the same bit strip as byte array and integer types
        // Note: The type change is not immediate, it has memory reading/writing cost
        union IntegerOrBytesUnion
        {
            IntegerType _integer;
            u8_q        _bytes[INTEGER_SIZE];
        };

        IntegerOrBytesUnion srcValue;
        srcValue._integer = nValue;

        IntegerOrBytesUnion swappedValue;

        // Integer's bytes are copied in inverse order to the output float
        for(unsigned int i = 0, j = INTEGER_SIZE - 1; i < INTEGER_SIZE; ++i, --j)
            swappedValue._bytes[i] = srcValue._bytes[j];

        nSwappedValue = swappedValue._integer;
    }

    /// <summary>
    /// Converts the integer number to a readable character string that represents it.
    /// </summary>
    /// <param name="nValue">[IN] The integer number to be converted.</param>
    /// <returns>
    /// The string that represents the number.
    /// </returns>
    template<typename IntegerType>
    static string_q ToString(const IntegerType &nValue)
    {
        string_q strOut = boost::lexical_cast<string_q>(nValue);
        return strOut;
    }

};

} //namespace DataTypes
} //namespace Tools
} //namespace QuimeraEngine
} //namespace Kinesis

#endif // __QINTEGER__
