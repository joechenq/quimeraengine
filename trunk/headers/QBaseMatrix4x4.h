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

#ifndef __QBASEMATRIX4X4__
#define __QBASEMATRIX4X4__

#include <memory>

#include "SQFloat.h"
#include "SQVF32.h"

using Kinesis::QuimeraEngine::Tools::DataTypes::SQFloat;
using Kinesis::QuimeraEngine::Tools::DataTypes::float_q;
using Kinesis::QuimeraEngine::Tools::DataTypes::vf32_q;


namespace Kinesis
{
namespace QuimeraEngine
{
namespace Tools
{
namespace Math
{

/// <summary>
/// Base class to represent a matrix of floating point values with 4 rows and 4 columns.
/// </summary>
class QDllExport QBaseMatrix4x4
{
	// CONSTRUCTORS
	// ---------------
public:

	/// <summary>
	/// Default constructor. Initializes each element in the matrix to 0.
	/// </summary>
	inline QBaseMatrix4x4()
	{
		ij[0][0] = ij[0][1] = ij[0][2] = ij[0][3] =
		ij[1][0] = ij[1][1] = ij[1][2] = ij[1][3] =
		ij[2][0] = ij[2][1] = ij[2][2] = ij[2][3] =
		ij[3][0] = ij[3][1] = ij[3][2] = ij[3][3] = SQFloat::_0;
	}

	/// <summary>
	/// Copy constructor. Copies attributes from given matrix.
	/// </summary>
	/// <param name="matrix">[IN] The 4x4 matrix from which we want to create a copy in the resident matrix.</param>
	inline QBaseMatrix4x4(const QBaseMatrix4x4 &matrix)
	{
        memcpy(this->ij, matrix.ij, sizeof(float_q) * 16);
	}

	/// <summary>
	/// Constructor that receives a floating point value for all elements of the matrix.
	/// </summary>
	/// <param name="fValueAll">[IN] Floating point value which to fill the matrix with.</param>
	inline explicit QBaseMatrix4x4(const float_q &fValueAll)
	{
		ij[0][0] = ij[0][1] = ij[0][2] = ij[0][3] =
		ij[1][0] = ij[1][1] = ij[1][2] = ij[1][3] =
		ij[2][0] = ij[2][1] = ij[2][2] = ij[2][3] =
		ij[3][0] = ij[3][1] = ij[3][2] = ij[3][3] = fValueAll;
	}

	/// <summary>
	/// Constructor from a floating point value for each element of the matrix.
	/// </summary>
	/// <param name="f00">[IN] Floating point value for element of row 0, column 0.</param>
	/// <param name="f01">[IN] Floating point value for element of row 0, column 1.</param>
	/// <param name="f02">[IN] Floating point value for element of row 0, column 2.</param>
	/// <param name="f03">[IN] Floating point value for element of row 0, column 3.</param>
	/// <param name="f10">[IN] Floating point value for element of row 1, column 0.</param>
	/// <param name="f11">[IN] Floating point value for element of row 1, column 1.</param>
	/// <param name="f12">[IN] Floating point value for element of row 1, column 2.</param>
	/// <param name="f13">[IN] Floating point value for element of row 1, column 3.</param>
	/// <param name="f20">[IN] Floating point value for element of row 2, column 0.</param>
	/// <param name="f21">[IN] Floating point value for element of row 2, column 1.</param>
	/// <param name="f22">[IN] Floating point value for element of row 2, column 2.</param>
	/// <param name="f23">[IN] Floating point value for element of row 2, column 3.</param>
	/// <param name="f30">[IN] Floating point value for element of row 3, column 0.</param>
	/// <param name="f31">[IN] Floating point value for element of row 3, column 1.</param>
	/// <param name="f32">[IN] Floating point value for element of row 3, column 2.</param>
	/// <param name="f33">[IN] Floating point value for element of row 3, column 3.</param>
	inline QBaseMatrix4x4(	const float_q &f00, const float_q &f01, const float_q &f02, const float_q &f03,
							const float_q &f10, const float_q &f11, const float_q &f12, const float_q &f13,
							const float_q &f20, const float_q &f21, const float_q &f22, const float_q &f23,
							const float_q &f30, const float_q &f31, const float_q &f32, const float_q &f33)
	{
		ij[0][0] = f00;
		ij[0][1] = f01;
		ij[0][2] = f02;
		ij[0][3] = f03;
		ij[1][0] = f10;
		ij[1][1] = f11;
		ij[1][2] = f12;
		ij[1][3] = f13;
		ij[2][0] = f20;
		ij[2][1] = f21;
		ij[2][2] = f22;
		ij[2][3] = f23;
		ij[3][0] = f30;
		ij[3][1] = f31;
		ij[3][2] = f32;
		ij[3][3] = f33;
	}

	/// <summary>
	/// Constructor that receives a pointer to 16 floating point values.
	/// </summary>
	/// <remarks>
	/// Keeps the convention rows x columns, so each chunck of 4 consecutive elements
	/// corresponds to a row, where each element in the chunck is the column in the row.
	/// </remarks>
	/// <param name="arValues">[IN] A 16 length array of floating point values. If the pointer is null, the behavior  
    /// is undefined.</param>
	inline explicit QBaseMatrix4x4(const float_q* arValues)
	{
		QE_ASSERT(arValues != null_q)

		ij[0][0] = arValues[0];
		ij[0][1] = arValues[1];
		ij[0][2] = arValues[2];
		ij[0][3] = arValues[3];
		ij[1][0] = arValues[4];
		ij[1][1] = arValues[5];
		ij[1][2] = arValues[6];
		ij[1][3] = arValues[7];
		ij[2][0] = arValues[8];
		ij[2][1] = arValues[9];
		ij[2][2] = arValues[10];
		ij[2][3] = arValues[11];
		ij[3][0] = arValues[12];
		ij[3][1] = arValues[13];
		ij[3][2] = arValues[14];
		ij[3][3] = arValues[15];
	}

	/// <summary>
	/// Constructor from four 4x32 floating point packed values. Each param contains a row of the matrix.
	/// </summary>
	/// <param name="row0">[IN] 4x32 values for row 0, columns 0 to 3, parsed in this order.</param>
	/// <param name="row1">[IN] 4x32 values for row 1, columns 0 to 3, parsed in this order.</param>
	/// <param name="row2">[IN] 4x32 values for row 2, columns 0 to 3, parsed in this order.</param>
	/// <param name="row3">[IN] 4x32 values for row 3, columns 0 to 3, parsed in this order.</param>
	inline QBaseMatrix4x4(const vf32_q &row0, const vf32_q &row1, const vf32_q &row2, const vf32_q &row3)
	{
        using Kinesis::QuimeraEngine::Tools::DataTypes::SQVF32;

		SQVF32::Unpack(row0, this->ij[0][0], this->ij[0][1], this->ij[0][2], this->ij[0][3]);
		SQVF32::Unpack(row1, this->ij[1][0], this->ij[1][1], this->ij[1][2], this->ij[1][3]);
		SQVF32::Unpack(row2, this->ij[2][0], this->ij[2][1], this->ij[2][2], this->ij[2][3]);
		SQVF32::Unpack(row3, this->ij[3][0], this->ij[3][1], this->ij[3][2], this->ij[3][3]);
	}

	// METHODS
	// ---------------
public:

	/// <summary>
	/// Equality operator. Compares two [4x4] matrices.
	/// </summary>
	/// <param name="matrix">[IN] The matrix to compare to.</param>
	/// <returns>
	/// If matrices are equals, then it returns true. Otherwise, it returns false.
	/// </returns>
	inline bool operator==(const QBaseMatrix4x4 &matrix) const
	{
		return	SQFloat::AreEqual(this->ij[0][0], matrix.ij[0][0]) &&
				SQFloat::AreEqual(this->ij[0][1], matrix.ij[0][1]) &&
				SQFloat::AreEqual(this->ij[0][2], matrix.ij[0][2]) &&
				SQFloat::AreEqual(this->ij[0][3], matrix.ij[0][3]) &&
				SQFloat::AreEqual(this->ij[1][0], matrix.ij[1][0]) &&
				SQFloat::AreEqual(this->ij[1][1], matrix.ij[1][1]) &&
				SQFloat::AreEqual(this->ij[1][2], matrix.ij[1][2]) &&
				SQFloat::AreEqual(this->ij[1][3], matrix.ij[1][3]) &&
				SQFloat::AreEqual(this->ij[2][0], matrix.ij[2][0]) &&
				SQFloat::AreEqual(this->ij[2][1], matrix.ij[2][1]) &&
				SQFloat::AreEqual(this->ij[2][2], matrix.ij[2][2]) &&
				SQFloat::AreEqual(this->ij[2][3], matrix.ij[2][3]) &&
				SQFloat::AreEqual(this->ij[3][0], matrix.ij[3][0]) &&
				SQFloat::AreEqual(this->ij[3][1], matrix.ij[3][1]) &&
				SQFloat::AreEqual(this->ij[3][2], matrix.ij[3][2]) &&
				SQFloat::AreEqual(this->ij[3][3], matrix.ij[3][3]);
	}

	/// <summary>
	/// Inequality operator. Compares two [4x4] matrices.
	/// matrices are equals or not.
	/// </summary>
	/// <param name="matrix">[IN] The matrix to compare to.</param>
	/// <returns>
	/// If matrices are not equals, then it returns true. Otherwise, it returns false.
	/// </returns>
	inline bool operator!=(const QBaseMatrix4x4 &matrix) const
	{
		return !(*this == matrix);
	}

	// ATTRIBUTES
	// ---------------
public:

	/// <summary>
	/// Array that holds the matrix.
	/// </summary>
	float_q ij[4][4];
};

} //namespace Math
} //namespace Tools
} //namespace QuimeraEngine
} //namespace Kinesis

#endif // __QBASEMATRIX4X4__
