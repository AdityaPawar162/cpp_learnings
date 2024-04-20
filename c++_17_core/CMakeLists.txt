add_executable(feature_macros feature_macros.cpp)
add_executable(if_switch_initialization if_switch_initialization.cpp)
add_executable(a a.cpp)
add_executable(b b.cpp)
add_executable(inline_variables inline_variables.cpp)
add_executable(structure_bindings structure_bindings.cpp)
add_executable(copy_elision copy_elision.cpp)
target_compile_options(copy_elision PRIVATE -fno-elide-constructors)
add_executable(Class_Template_Argument_Deduction Class_Template_Argument_Deduction.cpp)
add_executable(Folding Folding.cpp)
add_executable(Fold_Expressions Fold_Expressions.cpp)
add_executable(if_constexpr if_constexpr.cpp)
add_executable(optional optional.cpp)
add_executable(variant variant.cpp)
add_executable(type_safety type_safety.cpp)











