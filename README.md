# `torky-ast-metacompiler` — Backend 3: Self-Rewriting AST & 2-Sigma Shadow Sandbox Studio
**Subtitle:** Cores 021-030 | Autonomous oslash_eps Injection & Proof-Carrying AST  
**Author & Chief Architect:** Dr. Amr Torky  
**Accreditation:** ISO/IEC 17025:2017 (`1dd69a153b00`) & ISO/IEC 42001:2023  
**Permanent WORM DOIs:** CERN/Zenodo `10.5281/zenodo.1dd69a153b00` & `10.5281/zenodo.22785402`  
**Live Interactive Mission Control:** [https://amrtorky.github.io/torky-ast-metacompiler/](https://amrtorky.github.io/torky-ast-metacompiler/)

## 1. Dedicated Separated C++20 Backend & Zero-Disclosure C ABI
This repository compiles its own dedicated native C++20 backend (`src/dedicated_backend_engine.cpp` -> `build/dedicated_backend_engine`) and links against the stripped Zero-Disclosure C ABI library (`libgovernance_core.so`).

## 2. Sovereign Cores Hosted in This Repository (Part of the 118-Core AT-ACE Engine)
| Core ID | CLI Tool Name | Core Function | User & Enterprise Benefit |
|:---:|:---|:---|:---|
| **#021** | `torky-ast-scan` | Static AST Singularity Scanner | Scans Python/C++/CUDA syntax trees to flag unregularized '/' divisions before compilation. |
| **#022** | `torky-div-rewrite` | Autonomous oslash_eps AST Rewriter | Automatically rewrites BinOp(Div) nodes into non-singular oslash_epsilon(a, b) calls. |
| **#023** | `torky-log-rewrite` | Information Potential Log Regularizer | Rewrites ln(x) -> ln(sqrt(x^2+eps)) to prevent -Inf cross-entropy loss crashes. |
| **#024** | `torky-shadow-duel` | 2-Sigma Shadow Sandbox Duel Engine | Runs incumbent vs rewritten AST on held-out data; promotes iff improvement > 2*sigma. |
| **#025** | `torky-pcc-cert` | Proof-Carrying Code (PCC) Verifier | Emits static certificate verifying Ring-0 Control Plane immutability and zero raw divisions. |
| **#026** | `torky-merkle-relay` | Merkle-Relay Micro-Freeze Chain | Chains FREEZE_{n+1} = SHA256(SEAL_n || AST_{n+1} || PCC) to preserve pre-execution freeze. |
| **#027** | `torky-inline-guard` | PyTorch/JAX/TensorRT Graph Inliner | Inlines non-singular tensor bounds into LLM attention logits and KV-caches at runtime. |
| **#028** | `torky-branch-clamp` | Divergent Control-Flow Eliminator | Strips NaN/Inf exception branches from inner loops to unlock 100% SIMD warp vectorization. |
| **#029** | `torky-cmov-enforce` | Branchless Predicated Instruction Gen | Lowers conditional jumps to hardware cmov/csel instructions, eliminating timing side-channels. |
| **#030** | `torky-wasm-compile` | WebAssembly SIMD Client Exporter | Compiles verified AST trees into browser-native WASM modules for zero-install execution. |

## 3. 30-Second Independent Terminal Reproduction
```bash
git clone https://github.com/AmrTorky/torky-ast-metacompiler.git && cd torky-ast-metacompiler
g++ -O3 -std=c++20 -march=native -Iinclude src/dedicated_backend_engine.cpp -o build/dedicated_backend_engine
./build/dedicated_backend_engine -3.5 1.2
./run_audit.sh --input ./examples/sample_vectors.csv
```
