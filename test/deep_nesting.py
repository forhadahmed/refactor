# Test: deep Python nesting with sudden dedent to level 0
# This tests the stack popping logic in process_py

def deeply_nested_function():
    if True:
        if True:
            if True:
                if True:
                    if True:
                        if True:
                            if True:
                                # 7 levels deep
                                x = 1
                                y = 2
                                z = 3
                                result = x + y + z
                                print(f"Deep result: {result}")
# Sudden dedent to level 0 - must pop all 8 blocks correctly

def normal_after_deep():
    # This should parse correctly after the deep nesting
    a = 10
    b = 20
    return a + b


def another_deeply_nested():
    if True:
        if True:
            if True:
                if True:
                    if True:
                        if True:
                            if True:
                                # 7 levels deep - similar to above
                                x = 1
                                y = 2
                                z = 3
                                result = x + y + z
                                print(f"Deep result: {result}")
# Another sudden dedent

def final_normal():
    return 42
