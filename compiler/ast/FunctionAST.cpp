/*
 * FunctionAST.cpp
 *
 *  Created on: Aug 28, 2020
 *      Author: zbc
 */

#include "FunctionAST.h"

FunctionAST::FunctionAST() {
	// TODO Auto-generated constructor stub

}

FunctionAST::~FunctionAST() {
	// TODO Auto-generated destructor stub
}

llvm::Function* FunctionAST::Codegen() {
	//todo:待实现
	return nullptr;
}

FunctionAST* FunctionAST::ParseDefinition() {
	next_tok();  // eat def.
	/*PrototypeAST *Proto = ParsePrototype();
	if (Proto == 0)
		return 0;

	if (ExprAST *E = ParseExpression())
		return new FunctionAST(Proto, E);*/
	return 0;
}

