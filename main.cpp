
// Generated by llvm2cpp - DO NOT MODIFY!

#include <llvm/Pass.h>
//#include <llvm/ADT/SmallVector.h>
//#include <llvm/Analysis/Verifier.h>
#include <llvm/Analysis/Passes.h>
#include <llvm/Passes/PassBuilder.h>

//#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/Constants.h>
//#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Attributes.h>
#include <llvm/IR/AssemblyAnnotationWriter.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/InlineAsm.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/MathExtras.h>
#include <algorithm>

#include <iostream>

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/Optional.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <system_error>
#include <utility>
#include <vector>

using namespace llvm;
using namespace llvm::sys;


using namespace llvm;

LLVMContext TheContext;

Module *Mod;

Module *makeLLVMModule();

int main(int argc, char **argv) {
  Mod = makeLLVMModule();
//  verifyModule(*Mod, PrintMessageAction);
    PassManager<Module> *PM = new PassManager<Module>();
    AnalysisManager<Module> AM;
//  ModulePass::createPrinterPass()
//   ModulePass *MP = createModuleDebugInfoPrinterPass();
//    PM->addPass(*MP);
//    PM.run()
//  PM->run(*Mod, AM);
    std::cout << "executing main()... print called on module:" << std::endl;
    Mod->print(errs(), new AssemblyAnnotationWriter());
    std::cout << "executing main()... dump caled on module:" << std::endl;
    Mod->dump();
    legacy::PassManager pass;

    pass.add(createVerifierPass());
    pass.run(*Mod);
    return 0;
}


Module *makeLLVMModule() {
    // Module Construction
    Module *mod = new Module("test.ll", TheContext);
    mod->setDataLayout(
            "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128");
    mod->setTargetTriple("x86_64-apple-macosx10.10.0");

    // Type Definitions
    ArrayType *ArrayTy_0 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 14);

    PointerType *PointerTy_1 = PointerType::get(ArrayTy_0, 0);

    std::vector<Type *> FuncTy_2_args;
    FuncTy_2_args.push_back(IntegerType::get(mod->getContext(), 32));
    FunctionType *FuncTy_2 = FunctionType::get(
            /*Result=*/IntegerType::get(mod->getContext(), 32),
            /*Params=*/FuncTy_2_args,
            /*isVarArg=*/false);

    PointerType *PointerTy_3 = PointerType::get(IntegerType::get(mod->getContext(), 32), 0);

    std::vector<Type *> FuncTy_4_args;
    FunctionType *FuncTy_4 = FunctionType::get(
            /*Result=*/IntegerType::get(mod->getContext(), 32),
            /*Params=*/FuncTy_4_args,
            /*isVarArg=*/false);

    PointerType *PointerTy_5 = PointerType::get(FuncTy_2, 0);

    PointerType *PointerTy_6 = PointerType::get(IntegerType::get(mod->getContext(), 8), 0);

    std::vector<Type *> FuncTy_8_args;
    FuncTy_8_args.emplace_back(PointerTy_6);
// ArrayRef<Type*> fty = ArrayRef(FuncTy_8_args);
    FunctionType *FuncTy_8 = FunctionType::get(
            /*Result=*/IntegerType::get(mod->getContext(), 32),
            /*Params=*/FuncTy_8_args,
            /*isVarArg=*/true);

    PointerType *PointerTy_7 = PointerType::get(FuncTy_8, 0);


    // Function Declarations

    Function *func_some_function = mod->getFunction("some_function");
    if (!func_some_function) {
        func_some_function = Function::Create(
                /*Type=*/FuncTy_2,
                /*Linkage=*/GlobalValue::ExternalLinkage,
                /*Name=*/"some_function", mod);
        func_some_function->setCallingConv(CallingConv::C);
    }
    AttributeList func_some_function_PAL;
    {
        SmallVector<AttributeList, 4> Attrs;
        AttributeList PAS;
        {
            AttrBuilder B;
            B.addAttribute(Attribute::NoUnwind);
            B.addAttribute(Attribute::StackProtect);
            B.addAttribute(Attribute::UWTable);
            PAS = AttributeList::get(mod->getContext(), ~0U, B);
        }

        Attrs.push_back(PAS);
        func_some_function_PAL = AttributeList::get(mod->getContext(), Attrs);

    }
    func_some_function->setAttributes(func_some_function_PAL);

    Function *func_main = mod->getFunction("main");
    if (!func_main) {
        func_main = Function::Create(
                /*Type=*/FuncTy_4,
                /*Linkage=*/GlobalValue::ExternalLinkage,
                /*Name=*/"main", mod);
        func_main->setCallingConv(CallingConv::C);
    }
    AttributeList func_main_PAL;
    {
        SmallVector<AttributeList, 4> Attrs;
        AttributeList PAS;
        {
            AttrBuilder B;
            B.addAttribute(Attribute::NoUnwind);
            B.addAttribute(Attribute::StackProtect);
            B.addAttribute(Attribute::UWTable);
            PAS = AttributeList::get(mod->getContext(), ~0U, B);
        }

        Attrs.push_back(PAS);
        func_main_PAL = AttributeList::get(mod->getContext(), Attrs);

    }
    func_main->setAttributes(func_main_PAL);

    Function *func_printf = mod->getFunction("printf");
    if (!func_printf) {
        func_printf = Function::Create(
                /*Type=*/FuncTy_8,
                /*Linkage=*/GlobalValue::ExternalLinkage,
                /*Name=*/"printf", mod); // (external, no body)
        func_printf->setCallingConv(CallingConv::C);
    }
    AttributeList func_printf_PAL;
    {
        SmallVector<AttributeList, 4> Attrs;
        AttributeList PAS;
        {
            AttrBuilder B;
            PAS = AttributeList::get(mod->getContext(), ~0U, B);
        }

        Attrs.push_back(PAS);
        func_printf_PAL = AttributeList::get(mod->getContext(), Attrs);

    }
    func_printf->setAttributes(func_printf_PAL);

    // Global Variable Declarations


    GlobalVariable *gvar_array__str = new GlobalVariable(/*Module=*/*mod,
            /*Type=*/ArrayTy_0,
            /*isConstant=*/true,
            /*Linkage=*/GlobalValue::PrivateLinkage,
            /*Initializer=*/0, // has initializer, specified below
            /*Name=*/".str");
    gvar_array__str->setAlignment(1);

    // Constant Definitions
    Constant *const_array_9 = ConstantDataArray::getString(mod->getContext(), "Answer is %d\x0A", true);
    ConstantInt *const_int32_10 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
    ConstantInt *const_int32_11 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("2"), 10));
    ConstantInt *const_int32_12 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
    ConstantInt *const_int32_13 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("21"), 10));
    std::vector<Constant *> const_ptr_14_indices;
    const_ptr_14_indices.emplace_back(const_int32_12);
    const_ptr_14_indices.emplace_back(const_int32_12);
// Constant* const_ptr_14 = ConstantExpr::getGetElementPtr(gvar_array__str, const_ptr_14_indices);
    Constant *const_ptr_14 = ConstantExpr::getGetElementPtr(ArrayTy_0, gvar_array__str, const_ptr_14_indices);

    // Global Variable Definitions
    gvar_array__str->setInitializer(const_array_9);

    // Function Definitions

    // Function: some_function (func_some_function)
    {
        Function::arg_iterator args = func_some_function->arg_begin();
        Value *int32_input = args++;
        int32_input->setName("input");

        BasicBlock *label_entry = BasicBlock::Create(mod->getContext(), "entry", func_some_function, 0);

        // Block entry (label_entry)
        AllocaInst *ptr_input_addr = new AllocaInst(IntegerType::get(mod->getContext(), 32), "input.addr", label_entry);
        ptr_input_addr->setAlignment(4);
        StoreInst *void_15 = new StoreInst(int32_input, ptr_input_addr, false, label_entry);
        void_15->setAlignment(4);
        LoadInst *int32_16 = new LoadInst(ptr_input_addr, "", false, label_entry);
        int32_16->setAlignment(4);
        BinaryOperator *int32_mul = BinaryOperator::Create(Instruction::Mul, int32_16, const_int32_11, "mul",
                                                           label_entry);
        ReturnInst::Create(mod->getContext(), int32_mul, label_entry);

    }

    // Function: main (func_main)
    {

        BasicBlock *label_entry_18 = BasicBlock::Create(mod->getContext(), "entry", func_main, 0);

        // Block entry (label_entry_18)
        AllocaInst *ptr_retval = new AllocaInst(IntegerType::get(mod->getContext(), 32), "retval", label_entry_18);
        ptr_retval->setAlignment(4);
        AllocaInst *ptr_answer = new AllocaInst(IntegerType::get(mod->getContext(), 32), "answer", label_entry_18);
        ptr_answer->setAlignment(4);
        StoreInst *void_19 = new StoreInst(const_int32_12, ptr_retval, false, label_entry_18);
        CallInst *int32_call = CallInst::Create(func_some_function, const_int32_13, "call", label_entry_18);
        int32_call->setCallingConv(CallingConv::C);
        int32_call->setTailCall(false);
        AttributeList int32_call_PAL;
        int32_call->setAttributes(int32_call_PAL);

        StoreInst *void_20 = new StoreInst(int32_call, ptr_answer, false, label_entry_18);
        void_20->setAlignment(4);
        LoadInst *int32_21 = new LoadInst(ptr_answer, "", false, label_entry_18);
        int32_21->setAlignment(4);
        std::vector<Value *> int32_call1_params;
        int32_call1_params.emplace_back(const_ptr_14);
        int32_call1_params.emplace_back(int32_21);
        CallInst *int32_call1 = CallInst::Create(func_printf, int32_call1_params, "call1", label_entry_18);
        int32_call1->setCallingConv(CallingConv::C);
        int32_call1->setTailCall(false);
        AttributeList int32_call1_PAL;
        int32_call1->setAttributes(int32_call1_PAL);

        ReturnInst::Create(mod->getContext(), const_int32_12, label_entry_18);

    }

    return mod;
}

