// [TERMS&CONDITIONS]

#include "SQAngle.h"
#include "QMatrix3x3.h"
#include "QMatrix3x4.h"

namespace Kinesis
{
namespace QuimeraEngine
{
namespace Tools
{
namespace Math
{


//##################=======================================================##################
//##################             ____________________________              ##################
//##################            |                            |             ##################
//##################            |            METHODS         |             ##################
//##################           /|                            |\            ##################
//##################             \/\/\/\/\/\/\/\/\/\/\/\/\/\/              ##################
//##################                                                       ##################
//##################=======================================================##################

QMatrix3x3 QMatrix3x3::operator*(const float_q &fScalar) const
{
    QMatrix3x3 aux;

    aux.ij[0][0] = fScalar * this->ij[0][0];
    aux.ij[0][1] = fScalar * this->ij[0][1];
    aux.ij[0][2] = fScalar * this->ij[0][2];
    aux.ij[1][0] = fScalar * this->ij[1][0];
    aux.ij[1][1] = fScalar * this->ij[1][1];
    aux.ij[1][2] = fScalar * this->ij[1][2];
    aux.ij[2][0] = fScalar * this->ij[2][0];
    aux.ij[2][1] = fScalar * this->ij[2][1];
    aux.ij[2][2] = fScalar * this->ij[2][2];

    return aux;
}

QMatrix3x3 operator*(const float_q &fScalar, const QBaseMatrix3x3 &matrix)
{

    QMatrix3x3 aux;

    aux.ij[0][0] = fScalar * matrix.ij[0][0];
    aux.ij[0][1] = fScalar * matrix.ij[0][1];
    aux.ij[0][2] = fScalar * matrix.ij[0][2];
    aux.ij[1][0] = fScalar * matrix.ij[1][0];
    aux.ij[1][1] = fScalar * matrix.ij[1][1];
    aux.ij[1][2] = fScalar * matrix.ij[1][2];
    aux.ij[2][0] = fScalar * matrix.ij[2][0];
    aux.ij[2][1] = fScalar * matrix.ij[2][1];
    aux.ij[2][2] = fScalar * matrix.ij[2][2];

    return aux;
}

QMatrix3x3 QMatrix3x3::operator*(const QBaseMatrix3x3 &matrix) const
{
    QMatrix3x3 aux;

    aux.ij[0][0] = this->ij[0][0] * matrix.ij[0][0] + this->ij[0][1] * matrix.ij[1][0] + this->ij[0][2] * matrix.ij[2][0];
    aux.ij[0][1] = this->ij[0][0] * matrix.ij[0][1] + this->ij[0][1] * matrix.ij[1][1] + this->ij[0][2] * matrix.ij[2][1];
    aux.ij[0][2] = this->ij[0][0] * matrix.ij[0][2] + this->ij[0][1] * matrix.ij[1][2] + this->ij[0][2] * matrix.ij[2][2];

    aux.ij[1][0] = this->ij[1][0] * matrix.ij[0][0] + this->ij[1][1] * matrix.ij[1][0] + this->ij[1][2] * matrix.ij[2][0];
    aux.ij[1][1] = this->ij[1][0] * matrix.ij[0][1] + this->ij[1][1] * matrix.ij[1][1] + this->ij[1][2] * matrix.ij[2][1];
    aux.ij[1][2] = this->ij[1][0] * matrix.ij[0][2] + this->ij[1][1] * matrix.ij[1][2] + this->ij[1][2] * matrix.ij[2][2];

    aux.ij[2][0] = this->ij[2][0] * matrix.ij[0][0] + this->ij[2][1] * matrix.ij[1][0] + this->ij[2][2] * matrix.ij[2][0];
    aux.ij[2][1] = this->ij[2][0] * matrix.ij[0][1] + this->ij[2][1] * matrix.ij[1][1] + this->ij[2][2] * matrix.ij[2][1];
    aux.ij[2][2] = this->ij[2][0] * matrix.ij[0][2] + this->ij[2][1] * matrix.ij[1][2] + this->ij[2][2] * matrix.ij[2][2];

    return aux;
}

QBaseMatrix3x4 QMatrix3x3::operator*(const QBaseMatrix3x4& matrix) const
{
    QMatrix3x4 aux;

    aux.ij[0][0] = this->ij[0][0] * matrix.ij[0][0] + this->ij[0][1] * matrix.ij[1][0] + this->ij[0][2] * matrix.ij[2][0];
    aux.ij[0][1] = this->ij[0][0] * matrix.ij[0][1] + this->ij[0][1] * matrix.ij[1][1] + this->ij[0][2] * matrix.ij[2][1];
    aux.ij[0][2] = this->ij[0][0] * matrix.ij[0][2] + this->ij[0][1] * matrix.ij[1][2] + this->ij[0][2] * matrix.ij[2][2];
	aux.ij[0][3] = this->ij[0][0] * matrix.ij[0][3] + this->ij[0][1] * matrix.ij[1][3] + this->ij[0][2] * matrix.ij[2][3];

    aux.ij[1][0] = this->ij[1][0] * matrix.ij[0][0] + this->ij[1][1] * matrix.ij[1][0] + this->ij[1][2] * matrix.ij[2][0];
    aux.ij[1][1] = this->ij[1][0] * matrix.ij[0][1] + this->ij[1][1] * matrix.ij[1][1] + this->ij[1][2] * matrix.ij[2][1];
    aux.ij[1][2] = this->ij[1][0] * matrix.ij[0][2] + this->ij[1][1] * matrix.ij[1][2] + this->ij[1][2] * matrix.ij[2][2];
	aux.ij[1][3] = this->ij[1][0] * matrix.ij[0][3] + this->ij[1][1] * matrix.ij[1][3] + this->ij[1][2] * matrix.ij[2][3];

    aux.ij[2][0] = this->ij[2][0] * matrix.ij[0][0] + this->ij[2][1] * matrix.ij[1][0] + this->ij[2][2] * matrix.ij[2][0];
    aux.ij[2][1] = this->ij[2][0] * matrix.ij[0][1] + this->ij[2][1] * matrix.ij[1][1] + this->ij[2][2] * matrix.ij[2][1];
    aux.ij[2][2] = this->ij[2][0] * matrix.ij[0][2] + this->ij[2][1] * matrix.ij[1][2] + this->ij[2][2] * matrix.ij[2][2];
    aux.ij[2][3] = this->ij[2][0] * matrix.ij[0][3] + this->ij[2][1] * matrix.ij[1][3] + this->ij[2][2] * matrix.ij[2][3];

    return aux;

}

QMatrix3x3& QMatrix3x3::operator*=(const float_q fScalar)
{
    this->ij[0][0] *= fScalar;
	this->ij[0][1] *= fScalar;
	this->ij[0][2] *= fScalar;
	this->ij[1][0] *= fScalar;
	this->ij[1][1] *= fScalar;
	this->ij[1][2] *= fScalar;
	this->ij[2][0] *= fScalar;
	this->ij[2][1] *= fScalar;
	this->ij[2][2] *= fScalar;

    return *this;
}

QMatrix3x3 QMatrix3x3::operator/(const float_q &fScalar) const
{

    QE_ASSERT(fScalar != SQFloat::_0)

    const float_q &DIVISOR = SQFloat::_1/fScalar;

    QMatrix3x3 aux;

    aux.ij[0][0] = this->ij[0][0] * DIVISOR;
    aux.ij[0][1] = this->ij[0][1] * DIVISOR;
    aux.ij[0][2] = this->ij[0][2] * DIVISOR;
    aux.ij[1][0] = this->ij[1][0] * DIVISOR;
    aux.ij[1][1] = this->ij[1][1] * DIVISOR;
    aux.ij[1][2] = this->ij[1][2] * DIVISOR;
    aux.ij[2][0] = this->ij[2][0] * DIVISOR;
    aux.ij[2][1] = this->ij[2][1] * DIVISOR;
    aux.ij[2][2] = this->ij[2][2] * DIVISOR;

    return aux;
}

QMatrix3x3 QMatrix3x3::operator+(const QBaseMatrix3x3 &matrix) const
{
    QMatrix3x3 aux;

    aux.ij[0][0] = this->ij[0][0] + matrix.ij[0][0];
    aux.ij[0][1] = this->ij[0][1] + matrix.ij[0][1];
    aux.ij[0][2] = this->ij[0][2] + matrix.ij[0][2];
    aux.ij[1][0] = this->ij[1][0] + matrix.ij[1][0];
    aux.ij[1][1] = this->ij[1][1] + matrix.ij[1][1];
    aux.ij[1][2] = this->ij[1][2] + matrix.ij[1][2];
    aux.ij[2][0] = this->ij[2][0] + matrix.ij[2][0];
    aux.ij[2][1] = this->ij[2][1] + matrix.ij[2][1];
    aux.ij[2][2] = this->ij[2][2] + matrix.ij[2][2];

    return aux;
}

QMatrix3x3 QMatrix3x3::operator-(const QBaseMatrix3x3 &matrix) const
{
    QMatrix3x3 aux;

    aux.ij[0][0] = this->ij[0][0] - matrix.ij[0][0];
    aux.ij[0][1] = this->ij[0][1] - matrix.ij[0][1];
    aux.ij[0][2] = this->ij[0][2] - matrix.ij[0][2];
    aux.ij[1][0] = this->ij[1][0] - matrix.ij[1][0];
    aux.ij[1][1] = this->ij[1][1] - matrix.ij[1][1];
    aux.ij[1][2] = this->ij[1][2] - matrix.ij[1][2];
    aux.ij[2][0] = this->ij[2][0] - matrix.ij[2][0];
    aux.ij[2][1] = this->ij[2][1] - matrix.ij[2][1];
    aux.ij[2][2] = this->ij[2][2] - matrix.ij[2][2];

    return aux;
}

QMatrix3x3& QMatrix3x3::operator*=(const QBaseMatrix3x3 &matrix)
{
    QMatrix3x3 aux;

    aux.ij[0][0] = this->ij[0][0] * matrix.ij[0][0] + this->ij[0][1] * matrix.ij[1][0] + this->ij[0][2] * matrix.ij[2][0];
    aux.ij[0][1] = this->ij[0][0] * matrix.ij[0][1] + this->ij[0][1] * matrix.ij[1][1] + this->ij[0][2] * matrix.ij[2][1];
    aux.ij[0][2] = this->ij[0][0] * matrix.ij[0][2] + this->ij[0][1] * matrix.ij[1][2] + this->ij[0][2] * matrix.ij[2][2];

    aux.ij[1][0] = this->ij[1][0] * matrix.ij[0][0] + this->ij[1][1] * matrix.ij[1][0] + this->ij[1][2] * matrix.ij[2][0];
    aux.ij[1][1] = this->ij[1][0] * matrix.ij[0][1] + this->ij[1][1] * matrix.ij[1][1] + this->ij[1][2] * matrix.ij[2][1];
    aux.ij[1][2] = this->ij[1][0] * matrix.ij[0][2] + this->ij[1][1] * matrix.ij[1][2] + this->ij[1][2] * matrix.ij[2][2];

    aux.ij[2][0] = this->ij[2][0] * matrix.ij[0][0] + this->ij[2][1] * matrix.ij[1][0] + this->ij[2][2] * matrix.ij[2][0];
    aux.ij[2][1] = this->ij[2][0] * matrix.ij[0][1] + this->ij[2][1] * matrix.ij[1][1] + this->ij[2][2] * matrix.ij[2][1];
    aux.ij[2][2] = this->ij[2][0] * matrix.ij[0][2] + this->ij[2][1] * matrix.ij[1][2] + this->ij[2][2] * matrix.ij[2][2];

    *this = aux;

    return *this;
}

QMatrix3x3 QMatrix3x3::Transpose() const
{
    return QMatrix3x3(this->ij[0][0], this->ij[1][0], this->ij[2][0],
                      this->ij[0][1], this->ij[1][1], this->ij[2][1],
                      this->ij[0][2], this->ij[1][2], this->ij[2][2]);
}

float_q QMatrix3x3::GetDeterminant() const
{
    return this->ij[0][0] * this->ij[1][1] * this->ij[2][2] +
           this->ij[0][1] * this->ij[1][2] * this->ij[2][0] +
           this->ij[0][2] * this->ij[1][0] * this->ij[2][1] -
           this->ij[0][2] * this->ij[1][1] * this->ij[2][0] -
           this->ij[0][0] * this->ij[1][2] * this->ij[2][1] -
           this->ij[0][1] * this->ij[1][0] * this->ij[2][2];
}

QMatrix3x3 QMatrix3x3::Invert() const
{
    // Gets the inverse of the Determinant.
    const float_q INV_DET = SQFloat::_1 / this->GetDeterminant();

    return QMatrix3x3( INV_DET * (this->ij[1][1] * this->ij[2][2] - this->ij[1][2] * this->ij[2][1]),
                      -INV_DET * (this->ij[1][0] * this->ij[2][2] - this->ij[1][2] * this->ij[2][0]),
                       INV_DET * (this->ij[1][0] * this->ij[2][1] - this->ij[1][1] * this->ij[2][0]),
                      -INV_DET * (this->ij[0][1] * this->ij[2][2] - this->ij[0][2] * this->ij[2][1]),
                       INV_DET * (this->ij[0][0] * this->ij[2][2] - this->ij[0][2] * this->ij[2][0]),
                      -INV_DET * (this->ij[0][0] * this->ij[2][1] - this->ij[0][1] * this->ij[2][0]),
                       INV_DET * (this->ij[0][1] * this->ij[1][2] - this->ij[0][2] * this->ij[1][1]),
                      -INV_DET * (this->ij[0][0] * this->ij[1][2] - this->ij[0][2] * this->ij[1][0]),
                       INV_DET * (this->ij[0][0] * this->ij[1][1] - this->ij[0][1] * this->ij[1][0]) );
}

string_q QMatrix3x3::ToString() const
{
    return QE_L("M3x3((") + SQFloat::ToString(this->ij[0][0]) + QE_L(",")  +
                            SQFloat::ToString(this->ij[0][1]) + QE_L(",")  +
                            SQFloat::ToString(this->ij[0][2]) + QE_L(")(") +
                            SQFloat::ToString(this->ij[1][0]) + QE_L(",")  +
                            SQFloat::ToString(this->ij[1][1]) + QE_L(",")  +
                            SQFloat::ToString(this->ij[1][2]) + QE_L(")(") +
                            SQFloat::ToString(this->ij[2][0]) + QE_L(",")  +
                            SQFloat::ToString(this->ij[2][1]) + QE_L(",")  +
                            SQFloat::ToString(this->ij[2][2]) + QE_L("))");
}

} //namespace Math
} //namespace Tools
} //namespace QuimeraEngine
} //namespace Kinesis

