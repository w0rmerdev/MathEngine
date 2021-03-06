#include <iostream>
#include <string>
#include "src/Vector3/Vector3n.h"
#include "src/Matrix/Matrix.h"
#include "src/Quaternion/Quaternion.h"

// Vectors stuff
void vectorsTest()
{
	ME::Vector3n vector(1, 2, 3);
	ME::Vector3n vector1(0, 0, 0);
	ME::Vector3n vector2(4, 5, 6);
	ME::Vector3n vector3(1, 1, 1);
	ME::Vector3n vector4(1, 3, 2);
	ME::Vector3n vector5(9, 10, 2);

	std::cout << "vector: ";
	vector.show();

	std::cout << "vector1: ";
	vector1.show();

	std::cout << "vector2: ";
	vector2.show();

	std::cout << "vector3: ";
	vector3.show();

	std::cout << "vector4: ";
	vector4.show();

	std::cout << "vector5: ";
	vector5.show();

	// test vector operands
	// sum and subtraction tests
	ME::Vector3n result = vector + vector2;

	std::cout << "Result of sum of vectors: ";
	result.show();

	vector3 += vector4;
	std::cout << "vector3 after sum with vector4: ";
	vector3.show();

	ME::Vector3n resultReset = result - vector2;
	std::cout << "Result of subtraction of vectors: ";
	resultReset.show();

	vector3 -= vector4;
	std::cout << "vector3 after subtraction with vector4: ";
	vector3.show();

	vector1 -= vector2;
	std::cout << "vector1 after subtraction with vector2: ";
	vector1.show();

	// multiplication and division by scalar tests
	vector *= 2;
	std::cout << "vector multiplied by 2: ";
	vector.show();

	ME::Vector3n multiplied = vector2 * 5;
	std::cout << "result of vector2 multiplied by 5: ";
	multiplied.show();

	vector /= 3;
	std::cout << "vector divided by 3: ";
	vector.show();

	ME::Vector3n divided = vector2 / 2;
	std::cout << "result of vector2 divided by 2: ";
	divided.show();

	// vector product
	float dotProduct = vector.dot(vector2);
	std::cout << "Dot product of vector with vector2: " << dotProduct << std::endl;

	float dotProductMult = vector * vector4;
	std::cout << "Dot product of vector with vector4: " << dotProductMult << std::endl;

	// cross product
	ME::Vector3n crossProduct = vector.cross(vector2);
	std::cout << "Cross product of vector with vector2: ";
	crossProduct.show();

	ME::Vector3n crossProductMod = vector3 % vector4;
	std::cout << "Cross product of vector3 with vector4: ";
	crossProductMod.show();

	vector5 %= crossProductMod;
	std::cout << "Cross product of vector5 with crossProductMod: ";
	vector5.show();

	// magnitude of a vector
	float magnitude = vector5.magnitude();
	std::cout << "magnitude of vector5: " << magnitude << std::endl;

	// convert to unit vector
	vector5.normalize();
	std::cout << "unit vector of vector5: ";
	vector5.show();
}

// Matrices stuff
void matrixTest()
{
	ME::Matrix m(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	);
	m.show();

	ME::Matrix n(
		10, 11, 12,
		13, 14, 15,
		16, 17, 18
	);
	n.show();

	ME::Matrix o(
		19, 20, 21,
		22, 23, 24,
		25, 26, 27
	);
	o.show();

	ME::Matrix p(
		0, 0, 0,
		0, 0, -1,
		0, 1, 0
	);
	p.show();

	// test addition
	std::cout << "result of m + n: " << std::endl;
	ME::Matrix resultSum = m + n;
	resultSum.show();

	// test subtraction
	std::cout << "result of m - n: " << std::endl;
	ME::Matrix resultSub = m - n;
	resultSub.show();

	// test multiplication for scalar
	std::cout << "result of m * 2: " << std::endl;
	ME::Matrix resultMultSca = m * 2;
	resultMultSca.show();

	// test multiplication of matrices
	std::cout << "result of m * n: " << std::endl;
	ME::Matrix resultMult = m * n;
	resultMult.show();

	// test set matrix to identity
	std::cout << "result of setting o to identity: " << std::endl;
	ME::Matrix resultIdentity = o;
	resultIdentity.setMatrixAsIdentity();
	resultIdentity.show();

	// test invert matrix
	std::cout << "result of inverting m: " << std::endl;
	ME::Matrix resultInversion = m.getInverseOfMatrix();
	resultInversion.show();

	// test transpose matrix
	std::cout << "result of transposing m: " << std::endl;
	ME::Matrix resultTranspose = m.getTransposeOfMatrix();
	resultTranspose.show();

	// test vector transformation
	ME::Vector3n v(0, -1, 2);
	std::cout << "result of vector transformation of p * v: " << std::endl;
	ME::Vector3n resultVectorTrans = p * v;
	resultVectorTrans.show();

}

// Quaternions stuff
void quaternionsTest() 
{
	ME::Vector3n a(0, 1, 0);
	ME::Quaternion aQ(180, a);
	aQ.show();

	ME::Vector3n b(4, 2, 0);
	ME::Quaternion bQ(45, b);
	bQ.show();

	ME::Vector3n c(7, 3, 5);
	ME::Quaternion cQ(480, c);
	cQ.show();

	ME::Vector3n d(1, 2, 1);
	ME::Quaternion dQ(10, c);
	dQ.show();

	// test addition
	std::cout << "Addition of a and b: ";
	ME::Quaternion addResult = aQ + bQ;
	addResult.show();

	// test subtraction
	std::cout << "Subtraction of a and c: ";
	ME::Quaternion subResult = aQ - cQ;
	subResult.show();

	// test multiplication
	std::cout << "Multiplication of a and b: ";
	ME::Quaternion mulResult = aQ * bQ;
	mulResult.show();

	// test scalar multiplication
	std::cout << "Multiplication of c by 2: ";
	ME::Quaternion mulScalResult = cQ * 2;
	mulScalResult.show();

	// test norm of quaternion
	float normB = bQ.norm();
	std::cout << "Norm of b: " << normB << std::endl;

	// test unit norm of quaternion
	std::cout << "Unit norm of d: ";
	dQ.normalize();
	dQ.show();

	// test conjugation of quaternions
	std::cout << "Conjugate of c: ";
	ME::Quaternion cConjugateResult = cQ.conjugate();
	cConjugateResult.show();

	// test inversion of quaternions
	std::cout << "Inverse of b: ";
	ME::Quaternion bInverseResult = bQ.inverse();
	bInverseResult.show();

	// test rotating a vector
	ME::Vector3n axis(1, 0, 0);
	std::cout << "Rotated vector of b by 90 degrees and x axis: ";
	ME::Vector3n rotateResult = bQ.rotateVector(90, axis);
	rotateResult.show();
}

int main(int argc, const char* argv[])
{
	//vectorsTest();
	//matrixTest();
	//quaternionsTest();
}