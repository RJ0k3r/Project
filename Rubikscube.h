#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

class RubiksCube{
	public:
		enum class Faces{
			UP,
	        LEFT,
	        FRONT,
	        RIGHT,
	        BACK,
	        DOWN	
		};

		enum class Moves{
			L,L2,LPRIME,
			F,F2,FPRIME,	
			B,B2,BPRIME,
			U,U2,UPRIME,
			D,D2,DPRIME,
			R,R2,RPRIME
		};

		enum class COLOR{
			WHITE,
			ORANGE,
			GREEN,
			RED,
			BLUE,
			YELLOW
		};

		virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

	    static char getColorLetter(COLOR color);

	    virtual bool isSolved() const = 0;

	    static string getMove(MOVE ind);

	    /*
	     *
	     * The cube is laid out as follows.
	     *
	     * The sides:
	     *    U
	     *  L F R B
	     *    D
	     *
	     * Color wise:
	     *
	     *          W W W
	     *          W W W
	     *          W W W
	     *
	     *  G G G   R R R   B B B   O O O
	     *  G G G   R R R   B B B   O O O
	     *  G G G   R R R   B B B   O O O
	     *
	     *          Y Y Y
	     *          Y Y Y
	     *          Y Y Y
	     *
	     *
	     */
	    void print() const;

	    vector<MOVE> randomShuffleCube(unsigned int times);

	    /*
	     * Perform moves on the Rubik Cube
	     */
	    RubiksCube &move(MOVE ind);

	    /*
	     * Invert a move
	     */
	    RubiksCube &invert(MOVE ind);

	    /*
	     * Rotational Moves on the Rubik Cubes
	     *
	     * F, F’, F2,
	     * U, U’, U2,
	     * L, L’, L2,
	     * D, D’, D2,
	     * R, R’, R2,
	     * B, B’, B2
	     */

	    virtual RubiksCube &f() = 0;

	    virtual RubiksCube &fPrime() = 0;

	    virtual RubiksCube &f2() = 0;

	    virtual RubiksCube &u() = 0;

	    virtual RubiksCube &uPrime() = 0;

	    virtual RubiksCube &u2() = 0;

	    virtual RubiksCube &l() = 0;

	    virtual RubiksCube &lPrime() = 0;

	    virtual RubiksCube &l2() = 0;

	    virtual RubiksCube &r() = 0;

	    virtual RubiksCube &d() = 0;

	    virtual RubiksCube &dPrime() = 0;

	    virtual RubiksCube &d2() = 0;

	    virtual RubiksCube &rPrime() = 0;

	    virtual RubiksCube &r2() = 0;

	    virtual RubiksCube &b() = 0;

	    virtual RubiksCube &bPrime() = 0;

	    virtual RubiksCube &b2() = 0;

	    string getCornerColorString(uint8_t ind) const;

	    uint8_t getCornerIndex(uint8_t ind) const;

	    uint8_t getCornerOrientation(uint8_t ind) const;
};


#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H


