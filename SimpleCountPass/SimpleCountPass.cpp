
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

#include <iostream>

using namespace llvm;
using namespace std;

namespace {
    class SimpleCountPass : public FunctionPass {
    public:
        static char ID;

        unsigned int functionCount = 0;
        unsigned int basicBlockCount = 0;
        unsigned int instCount = 0;

        SimpleCountPass() : FunctionPass(ID) {}

        bool runOnFunction(Function &F) override;

        bool doFinalization(Module &module) override;
    };
} // namespace

char SimpleCountPass::ID = 0;

bool SimpleCountPass::runOnFunction(Function &F) {
    functionCount++;

    for (auto &iter : F) {
        basicBlockCount++;
        for (auto &bb : iter) {
            instCount++;
        }
    }

    return true;
}

bool SimpleCountPass::doFinalization(Module &module) {
    cout << "function count : " << functionCount << endl;
    cout << "basic block count : " << basicBlockCount << endl;
    cout << "inst count : " << instCount << endl;
    return Pass::doFinalization(module);
}

static RegisterPass<SimpleCountPass> X("SimpleCountPass", "My SimpleCountPass Pass");

static void registerPass(const PassManagerBuilder &,
                         legacy::PassManagerBase &PM) {
    PM.add(new SimpleCountPass());
}

static RegisterStandardPasses
        RegisterTheSpindlePass(PassManagerBuilder::EP_EarlyAsPossible,
                               registerPass);
