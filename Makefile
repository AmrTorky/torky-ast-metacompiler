CXX ?= g++
CXXFLAGS = -O3 -std=c++20 -march=native -Wall -Wextra -Iinclude -pthread

TARGET = build/torky-ast-metacompiler
REWRITER_BIN = build/ast_rewriter_engine

all: $(TARGET) $(REWRITER_BIN)

$(TARGET): src/torky_cli_kernel.cpp include/torky_continuum_core.hpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) src/torky_cli_kernel.cpp -o $(TARGET)

$(REWRITER_BIN): src/compiler/ast_rewriter_engine.cpp include/torky_continuum_core.hpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) src/compiler/ast_rewriter_engine.cpp -o $(REWRITER_BIN)

test: all
	./$(TARGET)
	./$(REWRITER_BIN)
	python3 src/python/ast_transpiler.py
	./run_audit.sh

clean:
	rm -rf build local_verification_certificate.json
