/*
 * PrototypeAST.cpp
 *
 *  Created on: Dec 21, 2020
 *      Author: zbc
 */

#include "PrototypeAST.h"
#include <iostream>

PrototypeAST::PrototypeAST(CompileUnit* unit,const std::string &name,
		const std::vector<std::string> &args):BaseAST(unit) {
	std::cout << "Function definition found:" << name << std::endl;
	this->name=name;
}

PrototypeAST::~PrototypeAST() {
	// TODO Auto-generated destructor stub
}

llvm::Function* PrototypeAST::Codegen() {
	// Make the function type:  double(double,double) etc.
	/*std::vector<Type*> Doubles(llvm::Args.size(),
			Type::getDoubleTy(TheContext));
	llvm::FunctionType *FT = llvm::FunctionType::get(Type::getDoubleTy(TheContext),llvm::Doubles, false);
	*/
	std::vector<llvm::Type*> args;
	llvm::FunctionType *FT = llvm::FunctionType::get(llvm::Type::getVoidTy(*unit->context),args, false);

	llvm::Function *F = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, name,
			unit->module);

	// If F conflicted, there was already something named 'Name'.  If it has a
	// body, don't allow redefinition or reextern.
	//todo:重定义异常处理
	/*if (F->getName() != Name) {
		// Delete the one we just made and get the existing one.
		F->eraseFromParent();
		F = TheModule->getFunction(Name);

		// If F already has a body, reject this.
		if (!F->empty()) {
			ErrorF("redefinition of function");
			return 0;
		}

		// If F took a different number of args, reject.
		if (F->arg_size() != Args.size()) {
			ErrorF("redefinition of function with different # args");
			return 0;
		}
	}*/
	//todo:参数处理
	// Set names for all arguments.
	/*unsigned Idx = 0;
	for (llvm::Function::arg_iterator AI = F->arg_begin(); Idx != Args.size();
			++AI, ++Idx) {
		AI->setName(Args[Idx]);

		// Add arguments to variable symbol table.
		NamedValues[Args[Idx]] = AI;
	}*/

	return F;
}
