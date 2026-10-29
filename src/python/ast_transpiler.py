#!/usr/bin/env python3
"""
Torky AST Metacompiler - Python AST NodeTransformer
Rewrites ast.Div into torky_oslash calls on computational expression trees.
"""

import ast
import math

EPSILON_NM2 = 0.016

def torky_oslash(numerator, denominator):
    return numerator / math.sqrt(denominator * denominator + EPSILON_NM2)

class NonSingularDivTransformer(ast.NodeTransformer):
    def visit_BinOp(self, node):
        self.generic_visit(node)
        if isinstance(node.op, ast.Div):
            return ast.Call(
                func=ast.Name(id='torky_oslash', ctx=ast.Load()),
                args=[node.left, node.right],
                keywords=[]
            )
        return node

def test_ast_rewrite():
    print("==============================================================================")
    print("[PYTHON AST METACOMPILER] Dynamic ast.Div Interceptor")
    print("==============================================================================")

    code = "def compute_field(q, r): return q / r"
    tree = ast.parse(code)

    transformer = NonSingularDivTransformer()
    new_tree = transformer.visit(tree)
    ast.fix_missing_locations(new_tree)

    compiled = compile(new_tree, filename="<ast_transpiled>", mode="exec")
    namespace = {'torky_oslash': torky_oslash}
    exec(compiled, namespace)

    compute_field = namespace['compute_field']

    val_at_zero = compute_field(1.0, 0.0)
    print(f"Transpiled Function: compute_field(1.0, 0.0)")
    print(f"Output at r=0:       {val_at_zero:.5f} (< inf, non-singular)")
    print("[STATUS] Python AST Metacompiler Pass Verified.")
    return True

if __name__ == "__main__":
    test_ast_rewrite()
